#include <Arduino.h>
#include <WiFi.h>
#include <NetworkClient.h>
#include <WiFiAP.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 4 
#define DHTTYPE    DHT22
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

// Non-blocking timing variables for DHT sensor
unsigned long lastDHTRead = 0;
float t = 0;
float h = 0;

const char *ssid = "4424";
const char *password = "LaalActiva";

#define LED_PIN 2
int LED_status = 0;
bool manualOverride = false;

NetworkServer server(80);

void toggleLED();
char *ledStatus();

void setup() {
  pinMode(LED_PIN, OUTPUT);

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

  // Non-blocking sensor read so web pages load fast
  if (millis() - lastDHTRead >= 2000) { 
    lastDHTRead = millis();
    
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    t = event.temperature;
    
    dht.humidity().getEvent(&event);
    h = event.relative_humidity;

    // Only auto-control if manual toggle hasn't been used
    if(!manualOverride) {
      if(t >= 30.0){
        LED_status = 1;
        digitalWrite(LED_PIN, HIGH);
      }else{
        LED_status = 0;
        digitalWrite(LED_PIN, LOW);
      }
    }
  }

  NetworkClient client = server.accept();

  if (client) {                     
    Serial.println("New Client.");  
    String currentLine = "";
    boolean isToggleRequest = false;

    while (client.connected()) {  
      if (client.available()) {     
        char c = client.read();  
        Serial.write(c);            

        if (c == '\n') {            

          if (currentLine.length() == 0) {
            
            if (isToggleRequest) {
              manualOverride = true; // Stay on manual control now
              toggleLED();
              
              // Redirect back to main page to clear the /T from URL bar
              client.println("HTTP/1.1 303 See Other");
              client.println("Location: /");
              client.println("Connection: close");
              client.println();
            } else {
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

              client.print("LED Status : ");
              client.print(ledStatus());
              client.print("<br>");

              client.print("Click <a href=\"/T\">here</a> to turn Toggle the LED.<br>");

              client.println();
            }
            break;
          } else {  
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;      
        }
        if (currentLine.endsWith("GET /T")) {
          isToggleRequest = true;
        }
      }
    }
    
    client.stop();
    Serial.println("Client Disconnected.");
  }
}

void toggleLED(){
  if(LED_status == 0){
    digitalWrite(LED_PIN, HIGH);
    LED_status = 1;
  }else{
    digitalWrite(LED_PIN, LOW);
    LED_status = 0;
  }
}

char *ledStatus(){
    if(LED_status == 0){
      return "OFF";
    }else{
      return "ON";
  }
}