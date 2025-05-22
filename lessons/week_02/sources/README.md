
# Connecting Arduino MKR WAN 1310 to ChirpStack (Docker) and exploring LoRaWAN settings (DR, ADR, confirmed/unconfirmed messages) with basic MQTT via Node-RED

## 🎯 Objective

In this session, students will learn how to set up their own **ChirpStack LoRaWAN Server using Docker**, configure a **LoRaWAN gateway**, and integrate the **MQTT broker with Node-RED** for basic message visualization.

---

## 🛠️ What You’ll Need

- Personal computer (Windows)
- **Docker Desktop** installed
- **ChirpStack (Docker version)** downloaded
- **Node-RED for Windows** installed
- Arduino MKR WAN 1310
- LoRaWAN gateway (provided by the professor)
- Internet connection
- IP address provided to the professor (for gateway routing)

---

## ⚙️ Step-by-Step Setup

### 1. 📦 Install Docker Desktop

- Download and install [Docker Desktop for Windows](https://www.docker.com/products/docker-desktop/)
- Restart your computer if prompted.

### 2. 🛰️ Download and Run ChirpStack (Docker Version)

- Clone or download the [ChirpStack Docker repository](https://www.chirpstack.io/docs/getting-started/docker.html)
- Follow the instructions to launch the stack (usually `docker-compose up`)

> **Access ChirpStack at:** [https://localhost:8080](https://localhost:8080)  
> **Default login:** `admin` / `admin`

### 3. 🌐 Network Setup

- **Connect to the Wi-Fi network provided by the professor**
- Share your **IP address** with the professor  
  (You can find it using `ipconfig` in CMD or in the network settings)

> The professor will use this IP to configure the **Packet Forwarder** of the LoRaWAN gateway so that messages are forwarded directly to your ChirpStack instance.

---

## 🧭 ChirpStack Configuration

1. **Register the LoRaWAN Gateway**  
   Use the `Gateway EUI` shown on the device.

2. **Create a Service Profile & Device Profile**
   - Device Class: **Class A**
   - Activation: **OTAA**
   - Frequency band: **EU868**

3. **Create an Application**

4. **Register your Arduino MKR WAN 1310**
   - Use the same **`devEUI`**, **`appEUI`**, and **`appKey`** from [week 01](../../week_01/sources/README.md)
   - Match the device profile you created

---

## 🔗 Integrating MQTT with Node-RED

### 1. 🧰 Install Node-RED for Windows

- Download from [https://nodered.org](https://nodered.org)
- Install normally on your machine
- Open your command prompt and type "node-red"

> **Access Node-RED at:** [http://localhost:1880](http://localhost:1880)

### 2. 🔌 Connect Node-RED to ChirpStack MQTT Broker

- Add an MQTT-in node
- Broker: `localhost`
- Port: `1883`
- Topic: `application/"application-id"/device/"deviceEUI"/event/up`

🔍 You should start receiving **uplink messages** from your Arduino MKR WAN 1310, forwarded through the gateway and ChirpStack. You also can download the node-red flow used in this lesson [here](./node-red/chirpstack-mqtt-integration.json) and import it. 

---

## 📥 Arduino Sketch

Use the sketch provided at the link below for your device configuration:

👉 [LoRaSendAndReceiveUpdated Sketch for ChirpStack](./LoRaSendAndReceiveUpdated/)

---

## 📂 Directory Structure

```plaintext
week_02/
├── README.md
└── sources/
    ├── lesson_images/
    └── LoRaSendAndReceiveUpdated/
        └── LoRaSendAndReceiveUpdated.ino
        └── arduino_secrets.h

