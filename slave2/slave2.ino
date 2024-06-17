#include "modules/ledring.h"
#include "modules/I2c.h"

int gameState = 0;
int gameStatePlayer = 0;

void setup()
{
    Serial.begin(9600);
    ledringSetup();
    i2cSetup();
}

void loop()
{
    switch (gameState)
    {
    case 1:
        int result = ledringLoop(gameStatePlayer);
        i2cSend(result);
        break;
    default:
        break;
    }
}
