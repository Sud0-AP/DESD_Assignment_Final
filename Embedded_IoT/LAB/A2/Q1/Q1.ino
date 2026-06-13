#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define SERVICE_UUID        "4fa4c201-1fb5-459e-8fcc-c5c9c331914b"

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");


  BLEDevice::init("ESP32_BLE_2602401300_05_32");

  BLEServer *pServer = BLEDevice::createServer();


  BLEService *pService = pServer->createService(SERVICE_UUID);


  pService->start();


  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // Functions that help with iPhone connections issues
  pAdvertising->setMinPreferred(0x12);
  
  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined! Now advertising...");
}

void loop() {
  // Put your main code here, to run repeatedly:
  delay(2000);
}