#include "modules/i2c.h"
#include "modules/remote.h"
#include "modules/rfid.h"
#include "modules/lcd.h"
#include "modules/mp3_player.h"

/* All possible mp3 player sounds:
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

int player1Level = 0;
int player2Level = 0;

int player1OldLevel = 0;
int player2OldLevel = 0;

void setup()
{
  Serial.begin(9600);
  i2cSetup();
  remoteSetup();
  // rfidSetup();
  mp3Setup();
  lcdSetup();
}

int playerLevelChange(int playerOldLevel, int playerLevel)
{
  switch (playerOldLevel)
  {
  case 0:
    return 0;
  case 1:
    switch (playerLevel)
    {
    case 1:
      return 2;

    case 2:
      return 1;
    }

  default:
    int LevelDifference = playerLevel - playerOldLevel;

    switch (LevelDifference)
    {
    case -1:
      return 2;

    case 0:
      return 0;

    case 1:
      return 1;
    }
  }
}

void loop()
{
  switch (gameState)
  {
  case 0:
    gameState = remoteLoop();
    // for (int i = 0; i < 2; i++)
    // {
    //   player[i] = rfidLoop();

    //   delay(3000);
    // }

    lcdRefresh(gameState, player1Level, player2Level, "", "");
    myDFPlayer.play(3);
    Serial.println("Game start sound played");

    Serial.println("Game is starting...");

    i2cSend(gameState);
    break;
  case 1:
    switch (player1Level)
    {
    case 0:
      break;
    case 7:
      gameState = 2;
      Serial.println("Player 1 has won");
      return;

    default:
      switch (playerLevelChange(player1OldLevel, player1Level))
      {
      case 0:
        break;
      case 1:
        myDFPlayer.play(playerLevelChange(player1OldLevel, player1Level));
        Serial.println("Player 1 round result sound played");
        lcdRefresh(gameState, player1Level, player2Level, "", "");
        break;

      case 2:
        myDFPlayer.play(playerLevelChange(player1OldLevel, player1Level));
        Serial.println("Player 1 round result sound played");
        lcdRefresh(gameState, player1Level, player2Level, "", "");
        break;
      }
      break;
    }

    switch (player2Level)
    {
    case 0:
      break;
    case 7:
      gameState = 2;
      Serial.println("Player 2 has won");
      return;

    default:
      myDFPlayer.play(playerLevelChange(player2OldLevel, player2Level));
      Serial.println("Player 2 round result sound played");
      lcdRefresh(gameState, player1Level, player2Level, "", "");
      break;
    }

    break;
  case 2:
    lcdRefresh(gameState, player1Level, player2Level, "", "");
    myDFPlayer.play(4);
    Serial.println("Game end sound played");
    i2cSend(gameState);

    gameState = 0;
    player1Level = 0;
    player2Level = 0;

    Serial.println("Restarting game...");
    break;
  }
}
