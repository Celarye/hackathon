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

void setup()
{
  setupmp3();
  ledringSetup();
}

void loop()
{
  ledringLoop();
}
