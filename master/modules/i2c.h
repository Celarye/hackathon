#include <Wire.h>

byte masterAddress = 0x0A;
byte slaveAddresses[2] = {0x0B, 0x0C};

extern int player1Level;
extern int player2Level;

void i2cReceive(int data)
{
  int playerLevel = Wire.read();

  if (playerLevel <= 7)
  {
    player1Level = playerLevel;
    Serial.print("player1Level update received from slave 1: ");
    Serial.println(player1Level);
  }
  else if (10 >= playerLevel)
  {
    int correctPlayerLevel = playerLevel - 10;

    player2Level = correctPlayerLevel;
    Serial.print("player2Level update received from slave 2: ");
    Serial.println(correctPlayerLevel);
  }
}

void i2cSetup()
{
  Serial.begin(9600);
  Wire.begin(masterAddress);
  Wire.onReceive(i2cReceive);
  Serial.println("I2C setup succeeded");
}

void i2cSend(int data)
{
  for (const byte &slaveAddress : slaveAddresses)
  {
    Wire.beginTransmission(slaveAddress);
    Wire.write(data);
    Wire.endTransmission();
  }

  Serial.print("Sending out gameState value to slaves: ");
  Serial.println(data);
}
