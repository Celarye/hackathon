#include <Wire.h>

byte masterAddress = 0x0A;
byte slaveAddresses[2] = {0x0B, 0x0C};

int gameStateChangePlayer;
extern int gameStateChangePlayer1;
extern int gameStateChangePlayer2;

void i2cReceive(int data)
{
  gameStateChangePlayer = Wire.read();

  switch (gameStateChangePlayer)
  {
  case -1:
    gameStateChangePlayer1 = 1;
    break;
  case 1:
    switch (gameStateChangePlayer1)
    {
    case 1:
      break;

    default:
      gameStateChangePlayer1 = -1;
      break;
    }
    break;
  case -11:
    switch (gameStateChangePlayer2)
    {
    case 1:
      break;

    default:
      gameStateChangePlayer = -1;
      break;
    }
    break;
  case 11:
    gameStateChangePlayer = 1;
    break;
  }
}

void i2cSetup()
{
  Wire.begin(masterAddress);
  Wire.onReceive(i2cReceive);
}

void i2cSend(int data)
{
  for (const byte &slaveAddress : slaveAddresses)
  {
    Wire.beginTransmission(slaveAddress);
    Wire.write(data);
    Wire.endTransmission();
  }
}
