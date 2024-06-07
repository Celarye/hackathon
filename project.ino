#include "modules/ledring.h"
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

// bepaald wie wint
bool reachedEndPlayer1 = false;
bool reachedEndPlayer2 = false;
// nog niet zeker hoe we 2 verschillende arduino's aanspreken met de zelfde code
// ik zat te denken om twee ledring.h files te maken voor P1 en P2 maar dat lijkt zo overbodig
// ik ben naar een oplossing aan het kijken.

// houd het current level bij van de speler
int gameStatePlayer1 = 0;
int gameStatePlayer2 = 0;

int P1VorigLvl;
int P2VorigLvl;

void setup()
{
  setupmp3();
  ledringSetup();
}

void loop()
{
  ledringLoop();
<<<<<<< HEAD
=======

  P1VorigLvl = gameStatePlayer1;
  P2VorigLvl = gameStatePlayer2;

  if (gameStatePlayer1 > P1VorigLvl)
  {
    // play winning sound
  }
  else if (gameStatePlayer1 < P1VorigLvl)
  {
    // play loser sound
  }

  if (gameStatePlayer2 > P2VorigLvl)
  {
    // play winning sound
  }
  else if (gameStatePlayer2 < P2VorigLvl)
  {
    // play loser sound
  }

  if (reachedEndPlayer1 == true)
  {
    // stop spel
    // maak speler 1 winaar
    // speel winner geluid af
  }
  if (reachedEndPlayer2 == true)
  {
    // stop spel
    // maak speler 2 winaar
    // speel winnaars geluid af
  }
  // lcd_init();
>>>>>>> efe72d5 (added an idea how the master should work)
}
