// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       FuelPump.ino
    Created:  01/09/2019 19:13:02
    Author:     ARCHWAY\mcnameed
*/
//http://elimelecsarduinoprojects.blogspot.com/2013/06/read-dallas-ibutton-arduino.html

// Define User Types below here or use a .h file
//
#include <ArduinoJson.hpp>
#include <SPI.h>
#include <Ethernet.h>
#include <OneWire.h>
#include <ArduinoJson.h>
#include "RestClient.h"


// ################### 1-Wire Stuff ################
// This is the pin with the 1-Wire bus on it
OneWire ds(2);
// unique serial number read from the key
byte addr[8];
// poll delay (I think 750ms is a magic number for iButton)
int del = 1000;
// Teensy 2.0 has an LED on port 11
int ledpin = 11;
char dataStrings[50] = { 0 };




//###################### Ethernet Stuff ####################
// assign a MAC address for the ethernet controller.
// fill in your address here:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
// Set the static IP address to use if the DHCP fails to assign
IPAddress ip(192, 168, 0, 177);
IPAddress myDns(192, 168, 0, 1);

// initialize the library instance:
EthernetClient client;

char server[] = "www.arduino.cc";  // also change the Host line in httpRequest()
//IPAddress server(64,131,82,241);

unsigned long lastConnectionTime = 0;           // last time you connected to the server, in milliseconds
const unsigned long postingInterval = 10 * 1000;  // delay between updates, in milliseconds

// ################### RESTful Client ####################
RestClient restClient = RestClient("192.168.2.250", 3000);

void setup() {
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);


  // start the Ethernet connection:
  Serial.println("Initialize Ethernet with DHCP:");
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // Check for Ethernet hardware present
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
      while (true) {
        delay(1); // do nothing, no point running without Ethernet hardware
      }
    }
    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip, myDns);
    Serial.print("My IP address: ");
    Serial.println(Ethernet.localIP());
  }
  else {
    Serial.print("  DHCP assigned IP ");
    Serial.println(Ethernet.localIP());
  }
  // give the Ethernet shield a second to initialize:
  delay(1000);

}

// Add the main program code into the continuous loop() function
void loop() {
  byte result;

  // search looks through all devices on the bus
  ds.reset_search();

  if (result = !ds.search(addr)) {
    // Serial.println("Scanning...");
  }
  else if (OneWire::crc8(addr, 7) != addr[7]) {
    Serial.println("Invalid CRC");
    delay(del);
    return;
  }
  else {

    sprintf(dataStrings, "%02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X", addr[7], addr[6], addr[5], addr[4], addr[3], addr[2], addr[1], addr[0]);
    Serial.print(dataStrings);
    Serial.print("\n");
    digitalWrite(ledpin, HIGH);
    delay(1000);
    digitalWrite(ledpin, LOW);

    // Test the ID received against that of the DB.

    // if there's incoming data from the net connection.
      // send it out the serial port.  This is for debugging
      // purposes only:
    if (client.available()) {
      char c = client.read();
      Serial.write(c);
    }

    // if ten seconds have passed since your last connection,
    // then connect again and send data:
    if (millis() - lastConnectionTime > postingInterval) {

		String jsonResponse = "";
		int statusCode = restClient.get("/users/1", &jsonResponse);
		Serial.print("Response from HAL: ");
		Serial.println(jsonResponse);

		DynamicJsonDocument doc(1024);
		deserializeJson(doc, jsonResponse);

		const char* name = doc["name"];
		const char* fob_id= doc["fob_id"];
		int id = doc["id"];
		Serial.print("Name: ");
		Serial.println(name);

		Serial.print("Fob ID: ");
		Serial.println(fob_id);
		
		Serial.print("PostgreSQL ID: ");
		Serial.println(id);

    }
  }

  delay(del);
  return;
}

void httpRequest() {
  // close any connection before send a new request.
  // This will free the socket on the WiFi shield
  client.stop();

  // if there's a successful connection:
  if (client.connect(server, 80)) {
    Serial.println("connecting...");
    // send the HTTP GET request:
    client.println("GET /latest.txt HTTP/1.1");
    client.println("Host: www.arduino.cc");
    client.println("User-Agent: arduino-ethernet");
    client.println("Connection: close");
    client.println();

    // note the time that the connection was made:
    lastConnectionTime = millis();
  }
  else {
    // if you couldn't make a connection:
    Serial.println("connection failed");
  }
}
