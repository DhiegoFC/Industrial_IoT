// LoRa Send and Receive Updated Example for Arduino MKR WAN 1310 (EU868)
// Adjusted for: Data Rate, Adaptative Data Rate, Error Monitoring, and OTAA Join Attempts

#include <MKRWAN.h>

LoRaModem modem;

// Replace with your keys from The Things Network console
String appEui = "aa99887766554433";
String appKey = "aa99887766554433aa99887766554433";

void setup() {
  Serial.begin(9600);
  while (!Serial);
  delay(2000);

  if (!modem.begin(EU868)) {
    Serial.println("Failed to start module");
    while (1) {}
  };

  Serial.print("Your module version is: ");
  Serial.println(modem.version());
  Serial.print("Your device EUI is: ");
  Serial.println(modem.deviceEUI());

  // Set Data Rate for Join Request Messages 
  modem.dataRate(5); 

  int attempts = 0;
  const int maxAttempts = 3;
  bool connected = false;

  Serial.println("Joining LoRaWAN network using OTAA...");
  while (attempts < maxAttempts && !connected) {
    connected = modem.joinOTAA(appEui, appKey);
    if (!connected) {
      Serial.print("OTAA join attempt ");
      Serial.print(attempts + 1);
      Serial.println(" failed.");
      delay(5000);
      attempts++;
    }

    // Set Data Rate for Confirmed/Unconfirmed LoRaWAN Messages 
    modem.dataRate(5); 
    // Set Adaptative Data Rate 
    modem.setADR(true);
  }

  if (!connected) {
    Serial.println("Join failed after 3 OTAA attempts. Check your keys and coverage.");
    while (1) {}
  } else {
    Serial.println("Successfully joined LoRaWAN network via OTAA.");
  }
}

void loop() {
  Serial.println();
  Serial.println("Enter a message to send to network");
  Serial.println("(make sure that end-of-line 'NL' is enabled)");

  while (!Serial.available());
  String msg = Serial.readStringUntil('\n');

  Serial.println();
  Serial.print("Sending: " + msg + " - ");
  for (unsigned int i = 0; i < msg.length(); i++) {
    Serial.print(msg[i] >> 4, HEX);
    Serial.print(msg[i] & 0xF, HEX);
    Serial.print(" ");
  }
  Serial.println();

  int err;  

  modem.beginPacket();
  modem.print(msg);
  // true = Confirmed Messages, false = Unconfirmed Messages
  err = modem.endPacket(false);
  if (err > 0) {
    Serial.println("Message sent correctly!");
  } else {
    Serial.println("Error sending message :(");
    Serial.println("you may send a limited amount of messages per minute, depending on the signal strength");
    Serial.println("it may vary from 1 message every couple of seconds to 1 message every minute)");
  }
  delay(1000);
  if (!modem.available()) {
    Serial.println("No downlink message received at this time.");
    return;
  }
  char rcv[64];
  int i = 0;
  while (modem.available()) {
    rcv[i++] = (char)modem.read();
  }
  Serial.print("Received: ");
  for (unsigned int j = 0; j < i; j++) {
    Serial.print(rcv[j] >> 4, HEX);
    Serial.print(rcv[j] & 0xF, HEX);
    Serial.print(" ");
  }
  Serial.println();
}
