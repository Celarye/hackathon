#include "modules/ledring.h"
#include "modules/I2c.h"
// #include "master/master-Arduino.h"

int gameState = 0;
int gameStatePlayer = 0;
bool reachedEndPlayer = false;

void setup()
{
    setupLedring();
    setupI2c();
}

void loop()
{
    switch (gameState)
    {
    case 2:
        sendI2c(0);
    case 1:
        int result = loopledring(gameStatePlayer);
        gameStatePlayerChange(result);
        sendI2c(result);
        break;
    case 0:
        break;
    }
}

void gameStatePlayerChange(int result)
{
    if (gameStatePlayer > 1 && result != -1)
    {
        gameStatePlayer += result;
    }
    if (gameStatePlayer == 6)
    {
        gameState = 2;
    }
    
}