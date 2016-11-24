

int sensorPin = A5;    
int sensorSpeedValue = 0;  


void speedMod() {
  
  sensorSpeedValue = analogRead(sensorPin);
  sensorSpeedValue = map(sensorSpeedValue, 0, 1023, 75, 255);
  allMotors(sensorSpeedValue,forward);
 
}
