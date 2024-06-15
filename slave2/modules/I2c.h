#include <Wire.h>


extern int gameState;
byte masterAddress = 0x0A;
byte slaveAddress = 0x0C;

void setupI2c()
{
    Wire.begin(slaveAddress);
    Wire.onReceive(receiveI2c);
    // Serial.begin(9600);
}

void sendI2c(int data)
{
    Wire.beginTransmission(masterAddress);
    Wire.write(data);
    Wire.endTransmission();
}

void receiveI2c(int data)
{
    gameState = Wire.read();
}