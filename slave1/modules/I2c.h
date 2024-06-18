#include <Wire.h>

extern int gameState;
extern int playerLevel;

byte masterAddress = 0x0A;
byte slave1Address = 0x0B;

void i2cReceive(int data)
{
    gameState = Wire.read();
}

void i2cSetup()
{
    Wire.begin(slave1Address);
    Wire.onReceive(i2cReceive);
}

void i2cSend(int data)
{
    Wire.beginTransmission(masterAddress);
    Wire.write(data);
    Wire.endTransmission();
}
