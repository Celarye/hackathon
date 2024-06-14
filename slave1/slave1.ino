#include "modules/ledring.h"
#include "master/master-Arduino.h"

void setup()
{
    setupLedring();
}

void loop()
{
    loopledring(playerStage);
}