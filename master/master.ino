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
  i2cSetup();
  remoteSetup();
  rfidSetup();
  mp3Setup();
  lcdSetup();
  Serial.begin(9600);
}

void loop()
{
  switch (gameState)
  {
  case 0:
    gameState = remoteLoop();
    for (int i = 0; i < 2; i++)
    {
      player[i] = rfidGetPlayer();
    }
    lcdRefresh();
    myDFPlayer.play(6);
    i2cSend(gameState);
    break;
  case 1:
    switch (gameStateChangePlayer1)
    {
    case 1:
      gameStatePlayer1++;
      break;
    case -1:
      gameStatePlayer1--;
      break;
    case 0:
      break;
    }

    switch (gameStateChangePlayer2)
    {
    case 1:
      gameStatePlayer2++;
      break;
    case -1:
      gameStatePlayer2--;
      break;
    case 0:
      break;
    }

    switch (gameStateChangePlayer1 || gameStateChangePlayer2)
    {
    case 7:
      gameState = 2;
      break;

    default:
      myDFPlayer.play(gameStateChangePlayer1);
      gameStateChangePlayer1 = 0;

      myDFPlayer.play(gameStateChangePlayer2);
      gameStateChangePlayer2 = 0;

      lcdRefresh();
      break;
    }

    break;
  case 2:
    lcdRefresh();
    myDFPlayer.play(8);
    i2cSend(gameState);
    break;
  }
}
