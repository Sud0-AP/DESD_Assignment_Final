#include <WiFi.h>
#include <PubSubClient.h>

// --- Configuration ---
const char* ssid     = "Hotspot";         // Your Wi-Fi Name
const char* password = "12345678o";     // Your Wi-Fi Password

// Replace with your PC's local IP address (e.g., 192.168.1.50)
const char* mqtt_server = "10.249.150.163"; 
const int mqtt_port     = 1883;                  // Default Mosquitto port

// Topics
const char* subscribe_topic = "parantha/paneer";

// --- Network Objects ---
WiFiClient espClient;
PubSubClient client(espClient);

// --- Function Prototypes ---
void setup_wifi();
void callback(char* topic, byte* message, unsigned int length);
void reconnect();

void setup() {
  Serial.begin(115200);
  
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  // Ensure the MQTT client stays connected and processes incoming messages
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

// --- Handles Wi-Fi Connection ---
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

  Serial.println("");
  Serial.println("Wi-Fi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

// --- Handles Incoming MQTT Messages ---
void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  
  String messageTemp;
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // Example: Feel free to add logic here to control ESP32 pins based on the message
  /*
  if (messageTemp == "on") {
    digitalWrite(LED_BUILTIN, HIGH);
  } else if (messageTemp == "off") {
    digitalWrite(LED_BUILTIN, LOW);
  }
  */
}

// --- Handles MQTT Broker Reconnection & Subscription ---
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    
    // Attempt to connect with a unique client ID
    String clientId = "ESP32Client-" + String(random(0xffff), HEX);
    
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      
      // Once connected, resubscribe to the topic
      client.subscribe(subscribe_topic);
      Serial.print("Subscribed to topic: ");
      Serial.println(subscribe_topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}