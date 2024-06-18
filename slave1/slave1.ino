#include "modules/I2c.h"
#include "modules/ledring.h"

int gameState = 0;
int playerLevel = 0;

void setup()
{
    Serial.begin(9600);
    i2cSetup();
    ledringSetup();
}

void playerLevelChange(int result)
{
    switch (playerLevel)
    {
    case 1:
        break;

    default:
        playerLevel += result;
        break;
    }
}

void loop()
{
    switch (gameState)
    {
    case 0:
        break;
    case 1:
        int result = ledringLoop(playerLevel);
        playerLevelChange(result);
        i2cSend(playerLevel);
        break;
    case 2:
        gameState = 0;
        playerLevel = 0;
        break;
    }
}
