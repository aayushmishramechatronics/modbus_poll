# ESP32 Modbus TCP Server

Simple Modbus TCP Server using Arduino IDE.

---

## Features

- ESP32 as Modbus TCP Slave
- Holding Registers
- Compatible with Modbus Poll
- WiFi-based communication
- Read & Write support

---

## Hardware

- ESP32 DevKit V1
- USB Cable
- WiFi Network
- Windows PC
- Modbus Poll

---

## Software

Arduino IDE

Required Library

ArduinoModbus

---

## Installation

Clone the project

```bash
git clone https://github.com/yourusername/ESP32_ModbusTCP_Server.git
```

Open

```
ESP32_ModbusTCP_Server.ino
```

Change

```cpp
const char* ssid="YOUR_WIFI";
const char* password="PASSWORD";
```

Upload.

Open Serial Monitor

115200 baud

Expected

```
Connecting...
Connected!
IP Address:
192.168.1.xxx

Modbus TCP Server Started
```

---

## Modbus Poll

Connection

```
IP Address : ESP32 IP

Port : 502

Slave ID : 1
```

Read Definition

```
Function 03

Address 0

Quantity 10
```

---

## Register Map

| Register | Address | Initial |
|-----------|---------|---------|
|40001|0|0|
|40002|1|100|
|40003|2|200|
|40004|3|300|
|40005|4|400|
|40006|5|500|
|40007|6|600|
|40008|7|700|
|40009|8|800|
|40010|9|900|

---

## Reading

Function Code

```
03
```

---

## Writing

Double-click a register in Modbus Poll.

Enter new value.

ESP32 updates instantly.

---

## Tested

ESP32 DevKit V1

Arduino IDE 2.x

Modbus Poll 10.x

Windows 10/11
