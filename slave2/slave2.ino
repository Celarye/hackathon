#include "modules/ledring.h"
#include "modules/I2c.h"

int gameState = 0;
int gameStatePlayer = 0;

void setup()
{
    ledringSetup();
    i2cSetup();
    Serial.begin(9600);
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
