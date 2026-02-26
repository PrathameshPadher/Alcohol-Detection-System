#include <LiquidCrystal.h>

// LCD Pins
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// MQ-3 Alcohol Sensor
#define alcoholSensor 7   // Digital OUT from MQ-3

// LEDs & Engine
#define GREEN_LED 5
#define RED_LED 6
#define ENGINE 4          // Relay / Motor / Buzzer

void setup() {
  lcd.begin(16, 2);

  pinMode(alcoholSensor, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(ENGINE, OUTPUT);

  // Default condition
  digitalWrite(GREEN_LED, HIGH);   // Engine ON
  digitalWrite(RED_LED, LOW);
  digitalWrite(ENGINE, HIGH);

  lcd.setCursor(0, 0);
  lcd.print("Alcohol System");
  lcd.setCursor(0, 1);
  lcd.print("No Alcohol");
}

void loop() {

  int alcoholValue = digitalRead(alcoholSensor);

  if (alcoholValue == HIGH) {
    // 🔴 Alcohol Detected
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(ENGINE, LOW);   // Engine Shutdown

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Alcohol Detected");
    lcd.setCursor(0, 1);
    lcd.print("Engine Shutdown");

  } else {
    // 🟢 No Alcohol
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(ENGINE, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No Alcohol");
    lcd.setCursor(0, 1);
    lcd.print("Engine Running");
  }

  delay(500);
}
