int trigger=7;
int echo=6;
long time=0;

long dist=0;

void setup() 
{
Serial.begin(9600);

pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
  

}

void loop()
{
digitalWrite(trigger, LOW);
delay(5);
digitalWrite(trigger, HIGH);
delay(10);
digitalWrite(trigger, LOW);
time=pulseIn(echo, HIGH);

dist=(time/2)/29.1;

if(dist>=500||dist<=0){
Serial.println("Nomeasurement");
}

else

{
  Serial.print(dist);
  Serial.println("cm");
}

delay(1000);

}

