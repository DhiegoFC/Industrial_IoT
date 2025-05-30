# 🌐 Full IoT Pipeline with Data Visualization

<div align="center">
    <img src="./lesson_images/lorawan_pipeline.png" alt="LoRaWAN Pipeline" width="650"/>
</div>

---

## 🎯 Objective

This final session demonstrates a complete Industrial IoT data pipeline using LoRaWAN.  
Students will visualize sensor data sent from an Arduino MKR WAN 1310 through ChirpStack, integrated via MQTT with Node-RED, stored in a time-series database (InfluxDB), and visualized through Grafana dashboards.

---

## 🛠️ What You’ll Need

- **Arduino MKR WAN 1310** (same configuration as Week 2)
- **Docker Desktop** (already installed)
- **ChirpStack (Docker version)** (already running from Week 2)
- **Node-RED for Windows** (already installed)
- **InfluxDB for Windows** (new installation)
- **Grafana for Windows** (new installation)
- Same sketch used in Week 2: [`LoRaSendAndReceiveUpdated`](../../week_02/sources/LoRaSendAndReceiveUpdated/)

---

## ⚙️ Installation Steps

### 1. 🛠️ Install InfluxDB

- Download and install InfluxDB from:  
  [https://portal.influxdata.com/downloads/](https://portal.influxdata.com/downloads/)

> If you are having trouble installing InfluxDB on Windows, check [this video on YouTube](https://www.youtube.com/watch?v=C-Anc1OeOpg).

After installation:
- Open the Command Prompt and run: `influxd`
- Access Influx via [http://localhost:8086](http://localhost:8086)
- Set up your **username**, **password**, and **organization name**

---

### 2. 📊 Install Grafana

Download Grafana for Windows:  
👉 [https://grafana.com/grafana/download](https://grafana.com/grafana/download)

> Need help? Follow this [Grafana installation video](https://www.youtube.com/watch?v=v7Bxka2Fb1g)

After installation:
- Access Grafana via [http://localhost:3000](http://localhost:3000)  
- Default login: `admin` / `admin`
- Set up **InfluxDB** as a new data source

---

## 🔁 Reusing the Arduino Sketch

Use the same sketch from Week 2:  
📂 [`LoRaSendAndReceiveUpdated`](../../week_02/sources/LoRaSendAndReceiveUpdated/)

- The device will send simulated sensor data (or dummy values).
- Uplink messages are transmitted via LoRaWAN to ChirpStack.
- ChirpStack forwards the messages to the local MQTT broker.

---

## 📥 Import Node-RED Flow

You can import the Node-RED flow from [here](./node-red/chirpstack-mqtt-integration-influxdb.json)

- This flow is already integrated with the ChirpStack MQTT broker.
- All LoRaWAN uplink data will be parsed and stored in **InfluxDB**.

---

## 📈 Import Grafana Dashboard

You can import the Grafana dashboard from [here](./grafana/grafana.json)

- It will visualize your **LoRaWAN data pipeline** using a dynamic and user-friendly graphical dashboard.

---

## 🔗 Integration Flow

1. **ChirpStack** receives uplinks from the Arduino via a LoRaWAN gateway.
2. **MQTT** publishes uplink messages on the topic:  
   `application/<applicationID>/device/<deviceEUI>/event/up`
3. **Node-RED** subscribes to the MQTT broker and parses the payload.
4. Parsed data is stored in **InfluxDB**.
5. **Grafana** queries InfluxDB and displays the data in a dashboard.

---

## 📂 Directory Structure

```plaintext
week_03/
├── README.md
└── sources/
    ├── grafana/
    │   └── grafana.json 
    ├── lesson_images/
    └── node-red/
        └── chirpstack-mqtt-integration-influxdb.json
