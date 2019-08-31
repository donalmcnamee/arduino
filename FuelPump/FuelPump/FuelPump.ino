#include <OneWire.h>

// This is the pin with the 1-Wire bus on it
OneWire ds(2);

// unique serial number read from the key
byte addr[8];

// poll delay (I think 750ms is a magic number for iButton)
int del = 1000;

// Teensy 2.0 has an LED on port 11
int ledpin = 11;

void setup() {
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
}

void loop() {
  byte result;

  // search looks through all devices on the bus
  ds.reset_search();

  if(result = !ds.search(addr)) {
    // Serial.println("Scanning...");
  } else if(OneWire::crc8(addr, 7) != addr[7]) {
    Serial.println("Invalid CRC");
    delay(del);
    return;
  } else {
    for(byte i=0; i<8; i++) {
      Serial.print(addr[i], HEX);
      Serial.print(" ");
    }
    Serial.print("\n");
    digitalWrite(ledpin, HIGH);
    delay(1000);
    digitalWrite(ledpin, LOW);
  }

  delay(del);
  return;
}
