#include <IRremote.h>

int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;

int result;

void remoteSetup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
}

int remoteLoop(){
  while (!result)
  {
    if (irrecv.decode(&results))
    { 

      Serial.print("Received value: ");
      Serial.println(results.value, HEX);
      
      switch (results.value)
      {
        case 0xff6897:
          result = 1;
          Serial.println("Remote-detected: ON");
          break;
      
        case 0xff9867:
          result = 2;
          Serial.println("Remote-detected: RESET");
          break;

        case 0xffb04f:
          result = 3;
          Serial.println("Remote-detected: BLAUW");
          break;

        case 0xff30cf:
          result = 4;
          Serial.println("Remote-detected: GEEL");
          break;

        case 0xff18e7:
          result = 5;
          Serial.println("Remote-detected: PAARS");
          break;

        case 0xff7a85:
          result = 6;
          Serial.println("Remote-detected: WIT");
          break;

        default:
          Serial.println(results.value, HEX);
          break;
      }

      return result;
      irrecv.resume();
    }
  }
  

      
  

  

  
  
}
    
    


  


