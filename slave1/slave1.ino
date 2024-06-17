#include "modules/ledring.h"
#include "modules/I2c.h"

int gameState = 0;
int gameStatePlayer = 0;

void setup()
{
    Serial.begin(9600);
    i2cSetup();
    ledringSetup();
}

void loop()
{
    switch (gameState)
    {
    case 0:
        break;
    case 1:
        int result = ledringLoop(gameStatePlayer);
        i2cSend(result);
        break;
    case 2:
        break;
    }
}
