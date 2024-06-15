#include "modules/lcd.h"
#include "modules/remote.h"
#include "modules/rfid.h"
//#include "modules/test.h"

byte remoteResult;
String* rfidResult;

void setup()
{

    //testsetup();
    //remoteSetup();
    rfidSetup();
}

void loop()
{
    rfidResult = getUID();
    
    //testloop();
    //remoteResult = remoteLoop();
    //Serial.println(remoteResult);
 
}
