#include "modules/remote.h"
#include "modules/rfid.h"
#include "modules/lcd.h"
#include "modules/mp3_player.h"
/* all sounds used for games (so far)
1. lose sound
2. new stage sound
3. oppon click sound
4. show score sound
5. final winning sound
6. cassino sound (no use in mind yet)
7. final losing sound
8. sound when game finishes

how to use:
bv:
myDFPlayer.play(sound u want in number: 1, 2...)
if u just type myDFPlayer. it will show all options
*/
  
byte remoteResult;
String* rfidResult;

int gameStatePlayer1 = 0;
int gameStatePlayer2 = 0;

int gameStateChangePlayer1;
int gameStateChangePlayer2;

void setup()
{
  rfidSetup();
  setupmp3();
}

void loop()
{
  switch (gameStateChangePlayer1)
  {
  case 2:
    gameStatePlayer1 ++;
    break;
  case 1:
    gameStatePlayer1 --;
    break;
  }
  myDFPlayer.play(gameStateChangePlayer1);
  gameStateChangePlayer1 = 0;

  switch (gameStateChangePlayer2)
  {
  case 2:
    gameStatePlayer2 ++;
    break;
  case 1:
    gameStatePlayer2 --;
    break;
  }

  myDFPlayer.play(gameStateChangePlayer2);
  gameStateChangePlayer2 = 0;
}
