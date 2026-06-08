#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define DHTPIN 4        // Kept at Pin 4 to avoid Wi-Fi strapping pin conflicts
#define DHTTYPE DHT11   // DHT 11

const char* ssid = "DHT_AP_ARPN";
const char* password = "12345678o";
const String serverPath = "http://192.168.4.1/send?";

DHT_Unified dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nWi-Fi connected!");

  // Give the power rail 2 seconds to stabilize after the Wi-Fi spike
  delay(2000); 

  // Initialize the Unified DHT device
  dht.begin();

  Serial.println("\nDHT Sensor connected!!\n");
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  sensors_event_t humidityEvent;
  sensors_event_t tempEvent;

  // Fetch the events from the unified library
  dht.humidity().getEvent(&humidityEvent);
  dht.temperature().getEvent(&tempEvent);

  float h = humidityEvent.relative_humidity;
  float t = tempEvent.temperature;

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor using Unified API!"));
    return;
  }

  // Calculate heat index using the standard library's internal formula 
  // (The unified library doesn't have a direct wrapper for computeHeatIndex, so we use the raw math wrapper)
  //float hic = dht.temperature().computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  // Serial.print(F("Heat index: "));
  // Serial.print(hic);
  // Serial.println(F("°C "));

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    
    // Combine base URL with the sensor values
    String fullURL = serverPath + "temp=" + String(t) + "&humid=" + String(h) /*+ "&heatin=" + String(hic)*/;
    
    Serial.print("Sending GET request to: ");
    Serial.println(fullURL);
    
    // Initialize the HTTP request with the target URL
    http.begin(fullURL);
    
    // Send the actual GET request
    int httpResponseCode = http.GET();
    
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      
      // Read the response payload from the server
      String payload = http.getString();
      Serial.print("Server reply: ");
      Serial.println(payload);
    } else {
      Serial.print("Error code on sending GET: ");
      Serial.println(httpResponseCode);
    }
    
    // Free resources used by the HTTP instance
    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
  
  // Wait 5 seconds before sending the next GET request
  delay(5000);
}