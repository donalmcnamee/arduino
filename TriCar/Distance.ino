const int trigPin = 4;
const int echoPin = 3;
long duration, distance, cm;

void avoidence() {
  
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(50);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
 distance=  duration = pulseIn(echoPin, HIGH) / 29 / 2;

  // distance = duration /29 /2;
 
  if (distance >= 30)
{
 digitalWrite(LED_PIN, LOW); 
Serial.print("All Motors Forward ");
Serial.println(distance);  
allMotors(fast,forward); 
} else {
  digitalWrite(LED_PIN, HIGH); 
  Serial.print("All Motors HALT ");
Serial.println(distance);
  haltMotors_For_Seconds(1);
  Serial.print("All Motors REVERSE ");
Serial.println(distance);
  allMotors(fast,reverse);
  delay(1000);
   haltMotors_For_Seconds(1);
  Serial.print("LEFT Motors FAST REVERSE ");
Serial.println(distance);
  leftMotors(fast,reverse);
  Serial.print("RIGHT Motors SLOW REVERSE ");
Serial.println(distance); 
 rightMotors(slow,reverse);
  delay(1000);
}

   
}

void convertToDistance()
 {
  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
//  Serial.println(cm);
  delay(50);
 }

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

