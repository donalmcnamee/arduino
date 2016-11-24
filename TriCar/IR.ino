
//////////////////////////////////////////////
// INFRARED FUNCTION
//////////////////////////////////////////////
void ir()
{
 
 // Serial.println(icFirst);
   Serial.println("Waiting for Key Press");
  
 if (irrecv.decode(&results)) {
   Serial.println("Translating..... Please Wait.....");
    translateIR();
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);



}


//////////////////////////////////////////////
// KEYBOARD SELECTION
////////////////////////////////////////////// 
void translateIR() // takes action based on IR code received
// describing Sony IR codes on LCD module
{
  switch(results.value)
  {
      case 0xC101E57B: haltMotors(); break;
 //   case 0xA3C8EDDB: reverse(); break;
 //   case 0x20FE4DBB: turnRight(); break;
//    case 0x52A3D41F:  turnLeft(); break;
//    case 0xD7E84B1B:  brake(); break;
//    case 0xC101E57B:  speedSlow(); break;
//    case 0x9716BE3F:  speedSlow(); break;
//    case 0x8C22657B:  speedSlow(); break;
//    case 0x97483BFB:  speedMedium(); break;
//    case 0x3D9AE3F7:  speedMedium(); break;
//    case 0x488F3CBB:  speedMedium(); break;
//    case 0xF0C41643:  speedFast(); break;
//    case 0x6182021B:  speedFast(); break;
//    case 0x449E79F:  speedFast(); break;
    default: Serial.println("Key not configured");
  }
 // delay(500);
 
}
 
 



