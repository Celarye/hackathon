#include <Wire.h>

extern int gameState;
byte masterAddress = 0x0A;
byte slaveAddress = 0x0B;

void i2cReceive(int data)
{
    gameState = Wire.read();
}

void i2cSetup()
{
    Wire.begin(slaveAddress);
    Wire.onReceive(i2cReceive);
}

void i2cSend(int data)
{
    Wire.beginTransmission(masterAddress);
    Wire.write(data);
    Wire.endTransmission();
}
