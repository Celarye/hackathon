#include <Wire.h>

byte masterAddress = 0x0A;
byte slaveAddresses[2] = {0x0B, 0x0C};

extern int gameStateChangePlayer1;
extern int gameStateChangePlayer2;

void i2cReceive(int data)
{
  switch (Wire.read())
  {
  case -1:
    gameStateChangePlayer1 = -1;
    break;
  case 1:
    gameStateChangePlayer1 = 1;
    break;
  }

  // switch (Wire.read())
  // {
  // case -11:
  //   gameStateChangePlayer2 = -1;
  //   break;
  // case 11:
  //   gameStateChangePlayer2 = 1;
  //   break;
  // }
}

void i2cSetup()
{
  Serial.begin(9600);
  Wire.begin(masterAddress);
  Wire.onReceive(i2cReceive);
}

void i2cSend(int data)
{
  for (const byte &slaveAddress : slaveAddresses)
  {
    Wire.beginTransmission(slaveAddress);
    Serial.print("Sending: ");
    Serial.println(data);
    Wire.write(data);
    Wire.endTransmission();
  }
}
