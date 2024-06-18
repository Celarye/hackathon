#include <Wire.h>

extern int gameState;
extern int playerLevel;

byte masterAddress = 0x0A;
byte slave2Address = 0x0C;

void i2cReceive(int data)
{
    gameState = Wire.read();
}

void i2cSetup()
{
    Wire.begin(slave2Address);
    Wire.onReceive(i2cReceive);
}

void i2cSend(int data)
{
    Wire.beginTransmission(masterAddress);
    Wire.write(data + 10);
    Wire.endTransmission();
}
