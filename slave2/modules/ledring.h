#include "FastLED.h"
#define NUM_LEDS 16
#define DATA_PIN A0
#define SCORE_PIN 6
#define SCORE_LEDS 6
#define BRIGHTNESS 25

CRGB leds[NUM_LEDS];
CRGB sleds[SCORE_LEDS];

int period = 1000;
unsigned long time_now = 0;
int Position = 0;

const int ledSpeed[6] = {50, 40, 30, 20, 14, 7};

const int staticSpots[6] = {3, 5, 7, 9, 11, 13};

void clearLeds()
{
  for (byte i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
}

void ledringSetup()
{
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812B, SCORE_PIN, GRB>(sleds, SCORE_LEDS);
  pinMode(2, INPUT_PULLUP);
  clearLeds();
}

void PlayGame(byte bound1, byte bound2)
{
  if (Position > 0)
  {
    leds[Position - 1] = CRGB::Black;
  }
  else
  {
    leds[NUM_LEDS - 1] = CRGB::Black;
  }
  leds[Position] = CRGB::Red;
  FastLED.show();
  Position++;
  if (Position >= NUM_LEDS)
  {
    Position = 0;
  }
}

void resultColor(int result)
{
  for (byte i = 0; i < NUM_LEDS; i++)
  {
    switch (result)
    {
    case -1:
      leds[i] = CRGB(255, 0, 0);
      break;

    case 1:
      leds[i] = CRGB(0, 255, 0);
      break;
    }
    FastLED.show();
  }

  delay(500);

  clearLeds();
}

int ledringLoop(int playerLevel)
{
  FastLED.setBrightness(BRIGHTNESS);

  // Level setup
  if (playerLevel == 0)
  {
    while (true)
    {
      fill_rainbow(leds, NUM_LEDS, 0, 20);
      fill_rainbow(sleds, SCORE_LEDS, 0, 40);

      if (digitalRead(2) == LOW)
      {
        Position = 0;
        delay(500);
        for (byte i = 0; i < NUM_LEDS; i++)
        {
          leds[i] = CRGB::Black;
          delay(40);
          FastLED.show();
          int thisPitch = map(i, 60, 0, 100, 1500);
          tone(9, thisPitch, 120);
        }
        for (byte i = 0; i < SCORE_LEDS; i++)
        {
          sleds[i] = CRGB::Black;
          delay(100);
          FastLED.show();
        }
        return 1;
      }
      FastLED.show();
    }
  }

  byte spot = staticSpots[playerLevel - 1];

  // Level 1
  if (playerLevel == 1)
  {
    while (true)
    {
      period = ledSpeed[0];
      if (millis() > time_now + period)
      {
        time_now = millis();
        leds[spot - 1] = CRGB(255, 140, 0);
        leds[spot] = CRGB(0, 255, 0);
        leds[spot + 1] = CRGB(255, 110, 0);
        sleds[0] = CRGB(0, 255, 0);
        PlayGame(spot + 1, spot + 2);
      }
      if (digitalRead(2) == LOW)
      {
        if (Position == spot + 2 || Position == spot + 1 || Position == spot)
        {
          resultColor(1);
          return 1;
        }
        else
        {
          resultColor(-1);
          return -1;
        }
      }
    }
  }

  // Level 2
  if (playerLevel == 2)
  {
    while (true)
    {
      period = ledSpeed[0];
      if (millis() > time_now + period)
      {
        time_now = millis();
        leds[spot - 1] = CRGB(255, 190, 0);
        leds[spot] = CRGB(0, 255, 0);
        leds[spot + 1] = CRGB(255, 190, 0);
        sleds[1] = CRGB(255, 255, 0);
        PlayGame(spot + 1, spot + 2);
      }
      if (digitalRead(2) == LOW)
      {
        if (Position == spot + 2 || Position == spot || Position == spot + 1)
        {
          resultColor(1);
          return 1;
        }
        else
        {
          resultColor(-1);
          return -1;
        }
      }
    }
  }

  // Level 3
  if (playerLevel == 3)
  {
    while (true)
    {
      period = ledSpeed[0];
      if (millis() > time_now + period)
      {
        time_now = millis();
        leds[spot] = CRGB(0, 255, 0);
        sleds[2] = CRGB(255, 50, 0);
        PlayGame(spot + 1, spot + 1);
      }
      if (digitalRead(2) == LOW)
      {
        if (Position == spot + 1)
        {
          resultColor(1);
          return 1;
        }
        else
        {
          resultColor(-1);
          return -1;
        }
      }
    }
  }

  // Level 4
  if (playerLevel == 4)
  {
    while (true)
    {
      period = ledSpeed[0];
      if (millis() > time_now + period)
      {
        time_now = millis();
        leds[spot] = CRGB(0, 255, 0);
        sleds[3] = CRGB(255, 0, 0);
        PlayGame(spot + 1, spot + 1);
      }
      if (digitalRead(2) == LOW)
      {
        if (Position == spot + 1)
        {
          resultColor(1);
          return 1;
        }
        else
        {
          resultColor(-1);
          return -1;
        }
      }
    }
  }

  // Level 5
  if (playerLevel == 5)
  {
    while (true)
    {
      period = ledSpeed[0];
      if (millis() > time_now + period)
      {
        time_now = millis();
        leds[spot] = CRGB(0, 255, 0);
        sleds[4] = CRGB(0, 50, 255);
        PlayGame(spot + 1, spot + 1);
      }
      if (digitalRead(2) == LOW)
      {
        if (Position == spot + 1)
        {
          resultColor(1);
          return 1;
        }
        else
        {
          resultColor(-1);
          return -1;
        }
      }
    }
  }

  // Level 6
  if (playerLevel == 6)
  {
    while (true)
    {
      period = ledSpeed[0];
      if (millis() > time_now + period)
      {
        time_now = millis();
        leds[spot] = CRGB(0, 255, 0);
        sleds[5] = CRGB(0, 150, 255);
        PlayGame(spot + 1, spot + 1);
      }
      if (digitalRead(2) == LOW)
      {
        if (Position == spot + 1)
        {
          resultColor(1);
          return 1;
        }
        else
        {
          resultColor(-1);
          return -1;
        }
      }
    }
  }
}
