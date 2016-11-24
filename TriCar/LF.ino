// Value returned <500 = NO BLACK LINE
// Value returned >500 = BLACK LINE DETECTED
int valuePinLeft = 0;
int valuePinLeftMid = 0;
int valuePinRightMid = 0;
int valuePinRight = 0;


void lf() {
 
valuePinLeft = analogRead(analogLeft);
valuePinLeftMid = analogRead(analogLeftMid);   
valuePinRightMid = analogRead(analogRightMid);   
valuePinRight = analogRead(analogRight);
Serial.print("L=");
Serial.print(valuePinLeft);
Serial.print("  LM=");
Serial.print(valuePinLeftMid);
Serial.print("  RM=");
Serial.print(valuePinRightMid);
Serial.print("  R=");
Serial.print(valuePinRight);
Serial.println("  ");
delay(500);


}

