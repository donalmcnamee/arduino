int piezo=5;
int movement=7;
int movementstatus=0;
int light=3;

void setup(){
  pinMode(piezo, OUTPUT);
  pinMode(movement, INPUT);
  pinMode(light, OUTPUT);
    Serial.begin(9600);
}

void loop(){
  movementstatus=digitalRead(movement);
  
  if(movementstatus==HIGH){
  
      digitalWrite(piezo,HIGH);
      digitalWrite(light,HIGH);
      delay(2000);
      digitalWrite(piezo,LOW);
      digitalWrite(light,LOW);
        delay(2000);
      
    }
  else{
      digitalWrite(piezo,LOW);
      digitalWrite(light,LOW);
  }
    
}


//Darragh Is not that cool at all
