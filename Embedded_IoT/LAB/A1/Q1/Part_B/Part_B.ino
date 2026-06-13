#include <Arduino.h>
#include <WiFi.h>
#include <NetworkClient.h>
#include <WiFiAP.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2 
#define DHTTYPE    DHT22
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

const char *ssid = "4424";
const char *password = "LaalActiva";

NetworkServer server(80);

void setup() {

  Serial.begin(115200);
  
  dht.begin();
  delay(1000);
  
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  dht.humidity().getSensor(&sensor);
  delayMS = sensor.min_delay / 1000;

  Serial.println();
  Serial.println("Configuring access point...");

  if (!WiFi.softAP(ssid, password)) {
    log_e("Soft AP creation failed.");
    while (1);
  }

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");
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

  NetworkClient client = server.accept();

  if (client) {                     
    Serial.println("New Client.");  
    String currentLine = "";         
    while (client.connected()) {  
      if (client.available()) {     
        char c = client.read();  
        Serial.write(c);            

        if (c == '\n') {            

          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            
            client.println("Refresh: 5"); 
            client.println();

            client.print("Temprature : ");
            client.print(t);
            client.print("<br>");
            
            client.print("Humidity : ");
            client.print(h);
            client.print("<br>");

            client.println();
            break;
          } else {  
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;      
        }
      }
    }
    
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
