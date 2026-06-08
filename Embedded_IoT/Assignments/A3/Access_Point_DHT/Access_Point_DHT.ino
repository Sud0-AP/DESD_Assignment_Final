#include <WiFi.h>
#include <WebServer.h>

// Set your Access Point credentials
const char* ssid = "DHT_AP_ARPN";
const char* password = "12345678o";

// Create a web server object that listens for HTTP request on port 80
WebServer server(80);

const int ledPin = 2; // Onboard LED pin

// Function to handle the "GET /send?temp=XX" request
void handleSendData() {
  // Check if the parameter "temp" is present in the URL
  if (server.hasArg("temp")) {
    String valueStr1 = server.arg("temp");
    int temp_val = valueStr1.toInt();
    
    Serial.print("Received Temprature Value: ");
    Serial.println(temp_val);
    Serial.print(" °C");

    String valueStr2 = server.arg("humid");
    int humid_val = valueStr2.toInt();
    
    Serial.print("Received Humidity Value: ");
    Serial.println(humid_val);
    Serial.print(" %");

    String valueStr3 = server.arg("heatin");
    int heatin_val = valueStr3.toInt();
    
    Serial.print("Received Temp Value: ");
    Serial.println(heatin_val);
    Serial.print(" °C");

    // Respond back to the client to confirm receipt
    server.send(200, "text/plain", "Data received: " + valueStr1 + valueStr2 + valueStr3);
    
    // Check if the number meets your condition
    if (temp_val > 27.0) {
      Serial.println("Temprature > 27.0 °C Blinking LED 1 time...");
      blinkLED(1); 
    } else if(humid_val > 80){
      Serial.println("Humidity value is 80% or more Blinking LED 2 times...");
      blinkLED(2);
    }else{
      Serial.println("Both Temprature and Humidity values are below threshold. No action.");
    }
  } else {
    // If the client accessed /send but forgot the parameter
    server.send(400, "text/plain", "Bad Request: Missing 'value' parameter");
  }
}

// Function to handle 404 (Not Found) errors
void handleNotFound() {
  server.send(404, "text/plain", "Not Found");
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.println("\nSetting up Access Point...");
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  // Link the URL path "/send" to the handleSendData function
  server.on("/send", HTTP_GET, handleSendData);
  server.onNotFound(handleNotFound);

  // Start the server
  server.begin();
  Serial.println("HTTP Server started.");
}

void loop() {
  // Handle incoming client requests
  server.handleClient();
}

void blinkLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
}