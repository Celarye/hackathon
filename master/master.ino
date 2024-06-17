#include "modules/i2c.h"
#include "modules/remote.h"
#include "modules/rfid.h"
#include "modules/lcd.h"
#include "modules/mp3_player.h"
/* All sounds used for games:
1. lose sound
2. new stage sound
3. oppon click sound
4. show score sound
5. final winning sound
6. cassino sound (no use in mind yet)
7. final losing sound
8. sound when game finishes

How to use:
myDFPlayer.play(sound u want in number: 1, 2...) */

String player[2];

int gameState = 0;

int gameStatePlayer1 = 0;
int gameStatePlayer2 = 0;

int gameStateChangePlayer1 = 0;
int gameStateChangePlayer2 = 0;

void setup()
{
  Serial.begin(9600);
  i2cSetup();
  remoteSetup();
  rfidSetup();
  mp3Setup();
  lcdSetup();
}

void loop()
{
  switch (gameState)
  {
  case 0:
    gameState = remoteLoop();
    for (int i = 0; i < 2; i++)
    {
      player[i] = rfidLoop();
      delay(5000);
    }
    lcdRefresh();
    myDFPlayer.play(6);
    i2cSend(gameState);
    break;
  case 1:
    switch (gameStatePlayer1)
    {
    case 7:
      gameState = 2;
      return;

    default:
      myDFPlayer.play(gameStateChangePlayer1);

      lcdRefresh();
      break;
    }

    switch (gameStatePlayer2)
    {
    case 7:
      gameState = 2;
      return;

    default:
      myDFPlayer.play(gameStateChangePlayer2);

      lcdRefresh();
      break;
    }

    switch (gameStateChangePlayer1)
    {
    case 1:
      gameStatePlayer1 += 1;
      break;
    case -1:
      if (gameStatePlayer2 != 1)
      {
        gameStatePlayer1 -= 1;
      }
      break;
    case 0:
      break;
    }

    switch (gameStateChangePlayer2)
    {
    case 1:
      gameStatePlayer2 += 1;
      break;
    case -1:
      if (gameStatePlayer2 != 1)
      {
        gameStatePlayer2 -= 1;
      }
      break;
    case 0:
      break;
    }

    Serial.print("GameStatePlayer1: ");
    Serial.println(gameStatePlayer1);
    Serial.print("GameStatePlayer2: ");
    Serial.println(gameStatePlayer2);

    gameStateChangePlayer1 = 0;
    gameStateChangePlayer2 = 0;

    break;
  case 2:
    lcdRefresh();
    myDFPlayer.play(8);
    i2cSend(gameState);

    gameState = 0;
    gameStatePlayer1 = 0;
    gameStatePlayer2 = 0;
    break;
  }
}
