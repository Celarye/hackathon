#include "FastLED.h"
#define NUM_LEDS 16
#define DATA_PIN A0
#define SCORE_PIN 6
#define SCORE_LEDS 6
#define BRIGHTNESS 25

CRGB leds[NUM_LEDS];
CRGB sleds[SCORE_LEDS];

extern int gameStatePlayer1;
extern bool reachedEndPlayer1;

int previousGameState = 0;
int level = 0;

int period = 1000;
unsigned long time_now = 0;
int Position = 0;

const int ledSpeed[6] = {50, 40, 30, 20, 14, 7};

const int staticSpots[6] = {3, 5, 7, 9, 11, 13};



void clearLEDS() {
  for (byte i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void PlayGame(byte bound1, byte bound2) {
  if (Position > 0) {
    leds[Position - 1] = CRGB::Black;
  } else {
    leds[NUM_LEDS - 1] = CRGB::Black;
  }
  leds[Position] = CRGB::Red;
  FastLED.show();
  Position++;
  if (Position >= NUM_LEDS) {
    Position = 0;
  }
}

void winner() {
  for (byte i = 0; i < 3; i++) {
    for (byte j = 0; j < NUM_LEDS; j++) {
      leds[j] = CRGB::Green;
      tone(9, 1000, 250);
    }
    FastLED.show();
    delay(500);
    clearLEDS();
    delay(500);
  }
  Position = 0;
  gameStatePlayer1 = level + 1;
  if (gameStatePlayer1 > 6) {
    gameStatePlayer1 = 0;
  }
}

void loser() {
  for (byte i = 0; i < 3; i++) {
    for (byte j = 0; j < NUM_LEDS; j++) {
      leds[j] = CRGB::Red;
      tone(9, 200, 250);
    }
    FastLED.show();
    delay(500);
    clearLEDS();
    delay(500);
  }
  
  Serial.println(previousGameState);
  gameStatePlayer1 = previousGameState - 1;
}

void ledringSetup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812B, SCORE_PIN, GRB>(sleds, SCORE_LEDS);
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Reset");
}

void ledringLoop(int playerStage) {
  FastLED.setBrightness(BRIGHTNESS);

  // Level setup
  if (gameStatePlayer1 == 0) {
    fill_rainbow(leds, NUM_LEDS, 0, 20);
    fill_rainbow(sleds, SCORE_LEDS, 0, 40);

    if (digitalRead(2) == LOW) {
      Position = 0;
      delay(500);
      for (byte i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Black;
        delay(40);
        FastLED.show();
        int thisPitch = map(i, 60, 0, 100, 1500);
        tone(9, thisPitch, 120);
      }
      for (byte i = 0; i < SCORE_LEDS; i++) {
        sleds[i] = CRGB::Black;
        delay(100);
        FastLED.show();
      }
      gameStatePlayer1 = 1;
    }
    FastLED.show();
  }

  byte spot = staticSpots[gameStatePlayer1 - 1];

  // Level 1
  if (gameStatePlayer1 == 1) {
    period = ledSpeed[0];
    if (millis() > time_now + period) {
      time_now = millis();
      leds[spot - 1] = CRGB(255, 140, 0);
      leds[spot] = CRGB(0, 255, 0);
      leds[spot + 1] = CRGB(255, 110, 0);
      sleds[0] = CRGB(0, 255, 0);
      PlayGame(spot + 1, spot + 2);
    }
    if (digitalRead(2) == LOW) {
      delay(300);
      previousGameState = gameStatePlayer1;
      if (Position == spot + 2 || Position == spot || Position == spot + 1) {
        level = gameStatePlayer1;
        gameStatePlayer1 = 98;
      } else {
        gameStatePlayer1 = 99;
      }
    }
  }

  // Level 2
  if (gameStatePlayer1 == 2) {
    period = ledSpeed[1];
    if (millis() > time_now + period) {
      time_now = millis();
      leds[spot - 1] = CRGB(255, 190, 0);
      leds[spot] = CRGB(0, 255, 0);
      leds[spot + 1] = CRGB(255, 190, 0);
      sleds[1] = CRGB(255, 255, 0);
      PlayGame(spot + 1, spot + 2);
    }
    if (digitalRead(2) == LOW) {
      delay(300);
      previousGameState = gameStatePlayer1;
      if (Position == spot + 2 || Position == spot || Position == spot + 1) {
        level = gameStatePlayer1;
        gameStatePlayer1 = 98;
      } else {
        gameStatePlayer1 = 99;
      }
    }
  }

  // Level 3
  if (gameStatePlayer1 == 3) {
    period = ledSpeed[2];
    if (millis() > time_now + period) {
      time_now = millis();
      leds[spot] = CRGB(0, 255, 0);
      sleds[2] = CRGB(255, 50, 0);
      PlayGame(spot + 1, spot + 1);
    }
    if (digitalRead(2) == LOW) {
      delay(300);
      previousGameState = gameStatePlayer1;
      if (Position == spot + 1) {
        level = gameStatePlayer1;
        gameStatePlayer1 = 98;
      } else {
        gameStatePlayer1 = 99;
      }
    }
  }

  // Level 4
  if (gameStatePlayer1 == 4) {
    period = ledSpeed[3];
    if (millis() > time_now + period) {
      time_now = millis();
      leds[spot] = CRGB(0, 255, 0);
      sleds[3] = CRGB(255, 0, 0);
      PlayGame(spot + 1, spot + 1);
    }
    if (digitalRead(2) == LOW) {
      delay(300);
      previousGameState = gameStatePlayer1;
      if (Position == spot + 1) {
        level = gameStatePlayer1;
        gameStatePlayer1 = 98;
      } else {
        gameStatePlayer1 = 99;
      }
    }
  }

  // Level 5
  if (gameStatePlayer1 == 5) {
    period = ledSpeed[4];
    if (millis() > time_now + period) {
      time_now = millis();
      leds[spot] = CRGB(0, 255, 0);
      sleds[4] = CRGB(0, 50, 255);
      PlayGame(spot + 1, spot + 1);
    }
    if (digitalRead(2) == LOW) {
      delay(300);
      previousGameState = gameStatePlayer1;
      if (Position == spot + 1) {
        level = gameStatePlayer1;
        gameStatePlayer1 = 98;
      } else {
        gameStatePlayer1 = 99;
      }
    }
  }

  // Level 6
  if (gameStatePlayer1 == 6) {
    period = ledSpeed[5];
    if (millis() > time_now + period) {
      time_now = millis();
      leds[spot] = CRGB(0, 255, 0);
      sleds[5] = CRGB(0, 150, 255);
      PlayGame(spot + 1, spot + 1);
    }
    if (digitalRead(2) == LOW) {
      delay(300);
      previousGameState = gameStatePlayer1;
      if (Position == spot + 1) {
        level = gameStatePlayer1;
        gameStatePlayer1 = 98;
        reachedEndPlayer1 = true;
      } else {
        gameStatePlayer1 = 99;
      }
    }
  }

  if (gameStatePlayer1 == 98) {
    winner();
  }
  if (gameStatePlayer1 == 99) {
    loser();
  }
}
