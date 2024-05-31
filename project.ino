#include "modules/ledring.h"
#include "modules/lcd.h"
#include "modules/mp3_player.h"

void setup()
{
  Serial.begin(9600);
  setupmp3();
  Serial.println('setup done');
}

void loop()
{
  loopmp3();
  Serial.println('hello world');
}
