
# Full IoT Pipeline with Data Visualization 

---

## 🎯 Objective

This final session demonstrates a complete Industrial IoT data flow using LoRaWAN. Students will visualize sensor data sent from an Arduino MKR WAN 1310 through ChirpStack, integrated via MQTT with Node-RED, stored in a time-series database (MongoDB or InfluxDB), and visualized using Grafana dashboards.

---

## 🛠️ What You’ll Need

- **Arduino MKR WAN 1310** (same configuration as Week 2)
- **Docker Desktop** (already installed)
- **ChirpStack (Docker version)** (already running from Week 2)
- **Node-RED for Windows** (already installed)
- **MongoDB or InfluxDB for Windows** (new installation)
- **Grafana for Windows** (new installation)
- Same sketch used in Week 2: [`LoRaSendAndReceive`](../week_02/sources/LoRaSendAndReceive/)

---

## ⚙️ Installation Steps

### 1. 🛠️ Install InfluxDB

- **InfluxDB**:  
  Download and install from [https://portal.influxdata.com/downloads/](https://portal.influxdata.com/downloads/)

> You can use either as the time-series database for this activity.

---

### 2. 📊 Install Grafana

Download Grafana for Windows:  
👉 [https://grafana.com/grafana/download](https://grafana.com/grafana/download)

After installation:
- Access Grafana via [http://localhost:3000](http://localhost:3000)  
- Default login: `admin` / `admin`  
- Set up your data source (InfluxDB)

---

## 🔁 Reusing the Arduino Sketch

Use the same sketch from Week 2:  
📂 [`LoRaSendAndReceive`](../week_02/sources/LoRaSendAndReceive/)

- The device will send simulated sensor data (or dummy values).
- Uplink messages are transmitted via LoRaWAN to ChirpStack.
- ChirpStack forwards data to the local MQTT broker.

---

## 🔗 Integration Flow

1. **ChirpStack** receives uplinks from the Arduino via a LoRaWAN gateway.
2. **MQTT** publishes uplink messages on `application/+/device/+/event/up`.
3. **Node-RED** subscribes to MQTT and parses the payload.
4. The data is stored in **MongoDB** or **InfluxDB**.
5. **Grafana** queries the database and displays the data in dashboards.

---

## 📂 Directory Structure

```plaintext
week_03/
├── README.md
└── sources/
    ├── lesson_images/
    └── example_flows/
        ├── node-red-flow.json
        └── grafana-dashboard.json


