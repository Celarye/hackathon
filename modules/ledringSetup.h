#include "FastLED.h"
#define NUM_LEDS 16
#define DATA_PIN A0
#define SCORE_PIN 6
#define SCORE_LEDS 6
#define BRIGHTNESS 25
CRGB leds[NUM_LEDS];
CRGB sleds[SCORE_LEDS];

bool reachedEnd = false;
byte gameState = 0;
int period = 1000;
unsigned long time_now = 0;
byte Position = 0;
byte level = 0;
byte previousGameState = 0;

const byte ledSpeed[6] = {50, 40, 30, 20, 14, 7};

// Static spots for each level
const byte staticSpots[6] = {3, 5, 7, 9, 11, 13};