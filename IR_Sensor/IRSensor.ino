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
     //Serial.println(results.value, DEC);
     
     switch(results.value){
       case 1033561079:
         Serial.println("Turning on RTE1");
         break; 
       case 1217346747:
         Serial.println("Turning on BBC1");
         break;
         case 667707411:
         Serial.println("Turning on 3e");
         break;
       default:
         Serial.println("Sorry. I didn't understand.");
         Serial.print("The IR code is ");
         Serial.println(results.value);
       break;
     
    }
    irrecv.resume();
  }
}
