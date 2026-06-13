#include <WiFi.h>
#include <PubSubClient.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2 
#define DHTTYPE    DHT22
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

// --- Configuration ---
const char* ssid     = "Hotspot";         // Your Wi-Fi Name
const char* password = "12345678o";     // Your Wi-Fi Password

// Replace with your PC's local IP address
const char* mqtt_server = "10.249.150.163"; 
const int mqtt_port     = 1883;

// Topic to send data TO
const char* publish_topic = "parantha/paneer";

// --- Network Objects ---
WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastMsg = 0;

void setup_wifi();
void reconnect();

void setup() {
  Serial.begin(115200);
  dht.begin();
  delay(1000);
  
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  dht.humidity().getSensor(&sensor);
  delayMS = sensor.min_delay / 1000;

  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  delay(delayMS);

  sensors_event_t event;
  
  float t,h;

  dht.temperature().getEvent(&event);
  t = event.temperature;
  if (isnan(t)) {
    Serial.println(F("Error reading temperature!"));
    return;
  }
  
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.println(F("°C"));
  
  dht.humidity().getEvent(&event);
  h = event.relative_humidity;
  if (isnan(h)) {
    Serial.println(F("Error reading humidity!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.println(F("%"));



  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Non-blocking timer: Publish data every 2000ms (2 seconds)
  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;

    // Prepare the payload string
    String payload = "Temprature: " + String(t) + " Humidity: " + String(h);
    
    Serial.print("Publishing message: ");
    Serial.println(payload);
    
    // Publish data
    client.publish(publish_topic, payload.c_str());
  }
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWi-Fi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP32Publisher-" + String(random(0xffff), HEX);
    
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}