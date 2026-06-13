#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define LED_PIN 2
#define DHTPIN 4 
#define DHTTYPE DHT22

DHT_Unified dht(DHTPIN, DHTTYPE);

// Sensor reading timing
uint32_t sensorDelayMS;
unsigned long lastSensorReadTime = 0;

// LED Blinking variables (Non-blocking)
unsigned long lastLEDToggleTime = 0;
int blinkInterval = 0; // 0 means steady state (ON/OFF)
bool ledState = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);

  dht.begin();
  delay(1000);
  
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  sensorDelayMS = sensor.min_delay / 1000;
  
  // Ensure we wait at least 2 seconds between DHT22 readings
  if (sensorDelayMS < 2000) {
    sensorDelayMS = 2000;
  }

  Serial.println("Smart Fan Simulation Started.");
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastSensorReadTime >= sensorDelayMS) {
    lastSensorReadTime = currentMillis;

    sensors_event_t event;
    float t;

    dht.temperature().getEvent(&event);
    t = event.temperature;
    
    if (isnan(t)) {
      Serial.println(F("Error reading temperature!"));
      return; 
    }
    
    Serial.print(F("Temperature: "));
    Serial.print(t);
    Serial.println(F("°C"));

    // Determine Fan Speed and Blink Interval based on temperature
    if (t < 25.0) {
      Serial.println("FAN STATUS: OFF");
      blinkInterval = 0;   // Custom state for permanently OFF
      ledState = LOW;
    } 
    else if (t >= 25.0 && t < 30.0) {
      Serial.println("FAN STATUS: LOW");
      blinkInterval = 1000; // Slow blink (1s ON, 1s OFF)
    } 
    else if (t >= 30.0 && t < 35.0) {
      Serial.println("FAN STATUS: MEDIUM");
      blinkInterval = 500;  // Medium blink (0.5s ON, 0.5s OFF)
    } 
    else { // t >= 35.0
      Serial.println("FAN STATUS: HIGH");
      blinkInterval = 1000;  // Fast blink (0.1s ON, 0.1s OFF)
    }
  }

  if (blinkInterval == 0) {
    // If interval is 0, the fan is OFF
    digitalWrite(LED_PIN, LOW);
  } else {
    // Handle the blinking intervals dynamically
    if (currentMillis - lastLEDToggleTime >= (unsigned long)blinkInterval) {
      lastLEDToggleTime = currentMillis;
      ledState = !ledState; // Toggle the LED state
      digitalWrite(LED_PIN, ledState);
    }
  }
}