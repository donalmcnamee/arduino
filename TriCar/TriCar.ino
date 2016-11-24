#include "Wiring.h"
#include "Settings.h"
#include <IRremote.h>  // Infrared Libaray


IRrecv irrecv(RECV_PIN);

decode_results results;

void setup(){
Serial.begin(115200); 
setItUp();
}

void loop()
{

//avoidence();
ir();
// motorDemo();

  
 
}





