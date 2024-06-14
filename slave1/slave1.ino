#include "modules/ledring.h"
//#include "master/master-Arduino.h"

int playerStage = 0;
int gameStatePlayer = 0;
bool reachedEndPlayer = false;

void setup()
{
    setupLedring();
}

void loop()
{
    loopledring(playerStage);
}