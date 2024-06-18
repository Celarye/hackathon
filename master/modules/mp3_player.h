#include "DFRobotDFPlayerMini.h"
#include <SoftwareSerial.h>

SoftwareSerial softSerial(/*rx =*/7, /*tx =*/8);
#define FPSerial softSerial
DFRobotDFPlayerMini myDFPlayer;

int mp3PlayerTimeOut = 500;
int mp3PlayerVolume = 15;

void mp3Setup()
{
  Serial.begin(9600);
  FPSerial.begin(9600);

  if (!myDFPlayer.begin(FPSerial, /*isACK = */ true, /*doReset = */ true))
  {
    Serial.println(F("DFPlayer setup failed:"));
    Serial.println(F("1.Please recheck the connections!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true)
      ;
  }
  Serial.println(F("DFPlayer setup succeeded"));

  myDFPlayer.setTimeOut(mp3PlayerTimeOut);
  myDFPlayer.volume(mp3PlayerVolume);
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
}
