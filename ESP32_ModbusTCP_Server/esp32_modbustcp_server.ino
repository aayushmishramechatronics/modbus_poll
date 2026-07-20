#include <WiFi.h>
#include <ArduinoModbus.h>

// =============================
// WiFi Credentials
// =============================
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// Create Modbus TCP Server
ModbusTCPServer modbusTCPServer;

// Holding Registers
const int NUM_REGISTERS = 10;

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println("Connecting to WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connected!");

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Start Modbus TCP server
  if (!modbusTCPServer.begin()) {
    Serial.println("Failed to start Modbus TCP Server!");
    while (1);
  }

  // Configure Holding Registers
  modbusTCPServer.configureHoldingRegisters(0, NUM_REGISTERS);

  // Initialize register values
  for (int i = 0; i < NUM_REGISTERS; i++) {
    modbusTCPServer.holdingRegisterWrite(i, i * 100);
  }

  Serial.println("Modbus TCP Server Started");
}

void loop() {

  // Accept Incoming Client
  WiFiClient client = WiFiServer(502).available();

  if (client) {

    modbusTCPServer.accept(client);

    while (client.connected()) {

      modbusTCPServer.poll();

      // Example:
      // Increment Register 0 every second

      static unsigned long lastUpdate = 0;

      if (millis() - lastUpdate > 1000) {

        uint16_t value =
          modbusTCPServer.holdingRegisterRead(0);

        modbusTCPServer.holdingRegisterWrite(
          0,
          value + 1
        );

        lastUpdate = millis();
      }
    }
  }
}
