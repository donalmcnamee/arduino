#include<IRremote.h>
int RECV_PIN=11;
IRrecv irrecv(RECV_PIN);
decode_results results;

int pwm_a = 3;  //PWM control for motor outputs 1 and 2 
int pwm_b = 9;  //PWM control for motor outputs 3 and 4 
int dir_a = 2;  //direction control for motor outputs 1 and 2 
int dir_b = 8;  //direction control for motor outputs 3 and 4 

void setup()
{
  
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  irrecv.enableIRIn();
  
  
  pinMode(pwm_a, OUTPUT);  //Set control pins to be outputs
  pinMode(pwm_b, OUTPUT);
  pinMode(dir_a, OUTPUT);
  pinMode(dir_b, OUTPUT);
  
  analogWrite(pwm_a, 100);  //set both motors to run at (100/255 = 39)% duty cycle (slow)
  //analogWrite(pwm_b, 100);
  
}

void loop()
{
  // Serial code begin 
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
  // Serial code end
  
  /*digitalWrite(dir_a, HIGH); 
  digitalWrite(dir_b, LOW);  
  
  delay(5000);
  
  analogWrite(pwm_a, 100);  // Start slow
  analogWrite(pwm_b, 0);
  
  delay(1000);
  
  analogWrite(pwm_a, 250);  //Build up speed
  analogWrite(pwm_b, 0);
  
  delay(1000);
  
  analogWrite(pwm_a, 100); //Slow down 
  analogWrite(pwm_b, 0);
  
  delay(1000);
  
  analogWrite(pwm_a, 100); //Turn 1
  analogWrite(pwm_b, 250);
  
  delay(2000);
  
  analogWrite(pwm_a, 100); //Slow drive  
  analogWrite(pwm_b, 0);
 
  delay(1000);
  
  analogWrite(pwm_a, 100); //Turn 2
  analogWrite(pwm_b, 250 );
  
  delay(2000);
  
 digitalWrite(dir_a, HIGH);       
 digitalWrite(dir_b, LOW);  
  
  
  analogWrite(pwm_a, 100); //Slow speed  
  analogWrite(pwm_b, 0);
  
  delay(1000);
  
  analogWrite(pwm_a, 250); //Speed up  
  analogWrite(pwm_b, 0);
  
  delay(1000);
  
  analogWrite(pwm_a, 100); //Slow down 
  analogWrite(pwm_b, 0);
  
  delay(1000);
  
  analogWrite(pwm_a, 100); //Turn 3
  analogWrite(pwm_b, 250);
  
  delay(2000);
  
  analogWrite(pwm_a, 100); //Slow speed
  analogWrite(pwm_b, 0);
 
  delay(1000);
  
  analogWrite(pwm_a, 0); //Stop
  analogWrite(pwm_b, 0);
*/
}


