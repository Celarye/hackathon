#include <IRremote.h>

int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;

unsigned long key_value = 0;
unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
const unsigned long period = 500;
String result;

void remoteFunctionSetup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

String remoteFunction(){

  currentMillis = millis();

  if (irrecv.decode(&results))
  {
    
    if (results.value == 0xFFFFFFFF){
      results.value = key_value;
    }
      
    
    if (currentMillis - previousMillis > period)
    {
    switch (results.value)
    {
      case 0xff6897:
        result = "ON/OFF";
        Serial.println("ON/OFF");
        previousMillis = millis();
        break;
    
      case 0xff9867:
        result = "RESET";
        Serial.println("RESET");
        previousMillis = millis();
        break;

      case 0xffb04f:
        result = "BLAUW";
        Serial.println("BLAUW");
        previousMillis = millis();
        break;

      case 0xff30cf:
        result = "GEEL";
        Serial.println("GEEL");
        previousMillis = millis();
        break;

      case 0xff18e7:
        result = "PAARS";
        Serial.println("PAARS");
        previousMillis = millis();
        break;

      case 0xff7a85:
        result = "WIT";
        Serial.println("WIT");
        previousMillis = millis();
        break;

      default:
        Serial.println(results.value, HEX);
        previousMillis = millis();
        break;
    }

    return result;
    }
    
    

    
    key_value = results.value;
    irrecv.resume();
  }

  return "NO INPUT";

}
