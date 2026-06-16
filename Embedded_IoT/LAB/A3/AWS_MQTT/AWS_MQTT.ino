#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
//#include "DHT.h"
#include <DHT22.h>

// ----------------------------
// AWS IoT Core Configuration
// ----------------------------
const char* WIFI_SSID = "Hostspot";
const char* WIFI_PASSWORD = "12345678o";

const char* AWS_IOT_ENDPOINT = "a30tmo8m9wjohd-ats.iot.us-east-1.amazonaws.com";  
// Example: "a3kodshaiixe9-ats.iot.eu-south-1.amazonaws.com"

// MQTT topic
const char* AWS_IOT_TOPIC = "esp32/weather/data";

// Client ID
const char* CLIENT_ID = "ESP32_DHT22";

// Certificates
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

static const char AWS_CERT_CRT[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUQosFApH79ZCGcMH+ZgNnatWVLFQwDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTI2MDYxMzA1MDMy
MloXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAKsnt7xImK05oXeTbyFN
X0HQmd658EqE7mHJDOvJcGRuRF4+Tl0dwcNnKthpN9njpA1T1QMlpsvMdpWvsUIZ
4eLD4l310xiJGAQhuKHqzF2cc/f7rpYb5O4ep08/6h4Y/MJ+c0Yr4aZVME96Ki86
9mqtpRoJ1XKBbZH1+w85GbiTA0BIkH4ie65KvHWlQap1Kzy3BjYfMsynLhpD/70N
f+AHsuWs79fZQPIwAvwaZTYfRQK7GSPFKrkQZGxJ1DuzlFyyhhIxQyPDsoHHaQWe
sKwPZRtKDyONlRASDLzbyYnKU2fG+NryTcWkGyrfmM+jhZmOefmZhkbHebzcp3aE
Vp8CAwEAAaNgMF4wHwYDVR0jBBgwFoAUqv99Rk0a4Nx+yeT5OsM86H3K2MAwHQYD
VR0OBBYEFL3b27/B3WHNyz/qEPA9QUPMEucFMAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQBpuC3ObbrLvYmsel6lYf+o2fml
K1m8uDMRSiHalRqg0XwgMr9dmGliU3jxECMMRsDNhlkTAK/sb9kCUQwkZwJaUkTc
ypKm/0VHc9fHFBsjrx70x9PglR6p0g/F8CIRF7kEs/w5bM69esKyA9uWSCRvat31
HR771vocA2bPC1u35ikF2Wky/o7Qw59YQg2aubNm9utimz2X+a+MWJULLEiSx+FG
pIk8W++VpjXLMhXs7lnmNnImgYu3elvfuYT7yl608B9nc67VCxpZTrL5ZzBuaz7k
RZDVcyQ1DwDyIGMED1t0oYpJ6oW7ZLlIKFGw+DsdsXECOTY7tu1HoQQIKPEQ
-----END CERTIFICATE-----
)EOF";

static const char AWS_CERT_PRIVATE[] PROGMEM = R"EOF(
-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEAqye3vEiYrTmhd5NvIU1fQdCZ3rnwSoTuYckM68lwZG5EXj5O
XR3Bw2cq2Gk32eOkDVPVAyWmy8x2la+xQhnh4sPiXfXTGIkYBCG4oerMXZxz9/uu
lhvk7h6nTz/qHhj8wn5zRivhplUwT3oqLzr2aq2lGgnVcoFtkfX7DzkZuJMDQEiQ
fiJ7rkq8daVBqnUrPLcGNh8yzKcuGkP/vQ1/4Aey5azv19lA8jAC/BplNh9FArsZ
I8UquRBkbEnUO7OUXLKGEjFDI8OygcdpBZ6wrA9lG0oPI42VEBIMvNvJicpTZ8b4
2vJNxaQbKt+Yz6OFmY55+ZmGRsd5vNyndoRWnwIDAQABAoIBAHvBRTYsG9EtGZZX
kYQ36Mey6H9GXPvU8HTeJaybw9uqa17lmE32BTOf9jfypIK0+dr1IdGbuOYlWh1T
o0zTYCRSVOxxoghcoHPkWhchqlGJncTSQ+OgGcEfgwRnh4XptWGAgyNa+VcGw97D
y5rI/IIYOogAUkjwUuS2Qqk4NWPiIjmq+tvPZ3TH+m+1Y79Sf+mnj/fix62GcLAy
uO+NcdU8DKEFCwYVY/yCXZNzRdIewmt7YD9nr/vId/ZzDDa29KRzJbyIbJMJK+TS
D96oMEynibaAZTaf7YlbQQqJCQPgnfyVdt+V3mfd2T1Fm6zKQ1UKxx+dc7iTjhmX
6fxA76kCgYEA1Kht+GUR/e+yyrmNKdTfWgut8nroI3iB2VfcQl0he+UYiiiSe5q4
LgrSCvutF4z1PQ3uMaLrcJYPhVOyC56ge3V6bcvT5fD7Ml4tb96Kd+et6yRA3zam
2q2KxsDecw/XONL9aRUj5T/zJB3kQEYlQDU3RLcTojGwgkpe6bC2qu0CgYEAzgna
Ryfvg5KW2K+T7v0n6peqkL/fjMpoUZs8dKGCb5G63upgaJXVSMP4GL2iKIMlFybV
G0OhtrQmkJsqxDvLRBp43L+UypUJY2SxvsKryiUAkqtrQHN0zCxWvJq1opnblTUe
20DywrXICa1iEkRSfAuuuCwbDB5tyKE/i+4OejsCgYEAnJwNoMiOH3zPJwzPMOdc
NWw0hkaNftHYjr9trlH3vs5Q7C5E8lJXIVFGrl/6cUWVtYj0ygk5aoiYlY+1p2kC
tuklaIabXtPBqq5AuAoj33n3Uxw3yirtZk43zXdsW0BnN6nqheDTtpkJ7qc02UDP
XiHSugA5rVD6tHkgvOkvHWECgYB8QR7dGK1uGKJWDRTW5N8Er/CSGNSVUJ+2zzqX
T6uc4zLiKlB34hxdJKnjKcG4Uta0bpvINHI6/8veG2WgMDs2WAyZfAQcY+LkiR5U
X4xAfS4qRayJktdWJksstNRjOgxdoEp6iWGdoQkBJQnm4EMqQdVdhmPNXDBy9SOg
nLEobwKBgFJqf9IhimkoTtCnmpBi5Nv7ky6tI9Zuw48N/jQFiKrYUJZ4HvVlPfcP
xyfj7IfFpHUfB65sDSw/Z8dOVsg2ED9YOy8DpoYdwWVLrZSwT3Zka8/Qx98h8oYp
175bBQQMadWH8beXYpqpPchQaVA03MZEMaZwH7xJ5nFJeWu4BoZ+
-----END RSA PRIVATE KEY-----
)EOF";

// ----------------------------
// DHT11 Sensor Configuration
// ----------------------------
//#define DHTPIN 4      // GPIO for DHT11 data pin
//#define DHTTYPE DHT11
//DHT dht(DHTPIN, DHTTYPE);
DHT22 dht(4);

// ----------------------------
// MQTT and WiFi Clients
// ----------------------------
WiFiClientSecure net = WiFiClientSecure();
PubSubClient client(net);

// ----------------------------
// Connect to WiFi
// ----------------------------
void connectToWiFi() {
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(2, LOW);
    Serial.print(".");
    delay(500);
  }
 
  Serial.println("\nConnected to Wi-Fi!");
  digitalWrite(2, HIGH);
  delay(100);
}

// ----------------------------
// Connect to AWS IoT Core
// ----------------------------
void connectToAWS() {
  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);

  client.setServer(AWS_IOT_ENDPOINT, 8883);
 
  Serial.print("Connecting to AWS IoT Core");

  while (!client.connect(CLIENT_ID)) {
    Serial.print(".");
    delay(100);
  }

  Serial.println("\nConnected to AWS IoT!");
  digitalWrite(2, LOW);
  delay(300);
  digitalWrite(2,HIGH);
  delay(500);

}

// ----------------------------
// Setup
// ----------------------------
void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  //dht.begin();

  connectToWiFi();
  connectToAWS();
}

// ----------------------------
// Main Loop
// ----------------------------
void loop() {
  if(WiFi.status() != WL_CONNECTED){
    connectToWiFi();
  }
  if (!client.connected()) {
    connectToAWS();
  }
  client.loop();

  // Read Temperature & Humidity
  float temp = dht.getTemperature(); // Celsius
  float hum = dht.getHumidity();

  // Check for reading errors
  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  // Prepare JSON payload
  char payload[256];
  snprintf(payload, sizeof(payload),
           "{\"device_id\":\"%s\",\"timestamp\":\"%lu\",\"temperature\":%.2f,\"humidity\":%.2f}",
           CLIENT_ID, millis(), temp, hum);

  // Publish to AWS IoT Core
  Serial.print("Publishing: ");
  Serial.println(payload);

  client.publish(AWS_IOT_TOPIC, payload);
  digitalWrite(2,LOW);
  delay(100);
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2,LOW);
  delay(100);
  digitalWrite(2, HIGH);

  delay(4700); // publish every 5 seconds
}
