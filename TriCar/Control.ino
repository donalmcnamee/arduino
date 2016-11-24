void leftMotors(int spe, int rotationDirection) {
 
  digitalWrite (leftMotorBlackWire, rotationDirection);
  digitalWrite (leftMotorRedWire,!rotationDirection); 
  analogWrite (enableLeftMotor,spe);
}


void rightMotors(int spe, int rotationDirection){

  digitalWrite (rightMotorBlackWire, rotationDirection);
  digitalWrite (rightMotorRedWire, !rotationDirection);
  analogWrite  (enableRightMotor, spe); 
}
void allMotors(int spe, int rotationDirection){
 leftMotors(spe,rotationDirection);
 rightMotors(spe,rotationDirection); 
 

}
void haltMotors_For_Seconds(int sec){
 leftMotors(0,forward);
 rightMotors(0,forward);
 delay(sec*1000);
}
void haltMotors(){
 leftMotors(0,forward);
 rightMotors(0,forward);
}
void doThisFor_Seconds(int seconds){
 delay(seconds*1000); 
}
void setItUp() {
  pinMode (leftMotorBlackWire, OUTPUT);
  pinMode (leftMotorRedWire, OUTPUT);
  pinMode (rightMotorBlackWire, OUTPUT);
  pinMode (rightMotorRedWire, OUTPUT);
  pinMode (enableLeftMotor, OUTPUT);
  pinMode (enableRightMotor, OUTPUT);
   pinMode (LED_PIN, OUTPUT);
 

 

  
}

