#include <Wire.h>

byte masterAddress = 0x0A;
byte slaveAddresses[] = {0x0B, 0x0C};

int gameStatePlayerChange;
extern int gameStatePlayerChange1;
extern int gameStatePlayerChange2;

void setupI2c()
{
  Wire.begin(0x0A);
  Wire.onReceive(receiveI2c);
}

void sendI2c(int data)
{
  for (const byte &slaveAddress : slaveAddresses)
  {
    Wire.beginTransmission(slaveAddress);
    Wire.write(data);
    Wire.endTransmission();
  }
}

void receiveI2c(int data)
{
  gameStatePlayerChange = Wire.read();

  switch (gameStatePlayerChange)
  {
  case -1:
    gameStatePlayerChange1 = 1;
    break;
  case 1:
    gameStatePlayerChange1 = -1;
    break;
  case -11:
    gameStatePlayerChange2 = -1;
    break;
  case 11:
    gameStatePlayerChange2 = 1;
    break;
  }
}
