#include<IRremote.h>
int RECV_PIN=11;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  irrecv.enableIRIn();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results)){
     Serial.println(results.value, DEC);
     irrecv.resume();
  }
}

//Test
