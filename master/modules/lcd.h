#include "LiquidCrystal.h"

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 6, en = 5, d4 = 4, d5 = 3, d6 = 1, d7 = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void lcdSetup()
{
  pinMode(A0, INPUT);
  lcd.begin(20, 4);

  lcd.setCursor(0, 0);
  lcd.print("Speler 1:");

  lcd.setCursor(0, 2);
  lcd.print("Speler 2:");

  Serial.println("LCD setup succeeded");
}

void lcdRefresh(int gameState, int player1Level, int player2Level, String player1Name, String player2Name)
{
  switch (gameState)
  {
  case 0:
    break;
  case 1:
    lcd.setCursor(0, 1);
    lcd.print("Level ");
    lcd.setCursor(7, 1);
    lcd.print(player1Level);
    lcd.setCursor(0, 2);
    lcd.print(0, 3);
    lcd.print("Level ");
    lcd.setCursor(7, 3);
    lcd.print(player2Level);
    break;

  case 2:
    lcd.setCursor(0, 1);
    switch (player1Level)
    {
    case 7:
      lcd.print("WINNER");
      break;

    default:
      lcd.print("LOSER");
      break;
    }
    lcd.setCursor(0, 3);
    switch (player2Level)
    {
    case 7:
      lcd.print("WINNER");
      break;

    default:
      lcd.print("LOSER");
      break;
    }
    break;
  }
}
