#include <LiquidCrystal.h>

int red = 9;
int green = 8;
int sigpin = 7;

unsigned long sigpin_value;
int distance;

LiquidCrystal lcd(13, 12, 2, 3, 4, 5);

enum Status {
  SAFE,
  CAUTION,
  STOP
};

Status currentStatus;
Status previousStatus = SAFE;

void setup() {
  lcd.begin(16, 2);

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Distance(cm):");
}

void loop() {

  
  pinMode(sigpin, OUTPUT);

  digitalWrite(sigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(sigpin, HIGH);
  delayMicroseconds(5);
  digitalWrite(sigpin, LOW);

  
  pinMode(sigpin, INPUT);
  sigpin_value = pulseIn(sigpin, HIGH);
  distance = sigpin_value / 58;

  
  lcd.setCursor(13, 0);
  lcd.print("   ");
  lcd.setCursor(13, 0);
  lcd.print(distance);

  
  if (distance <= 10) {
    currentStatus = STOP;
  }
  else if (distance <= 30) {
    currentStatus = CAUTION;
  }
  else {
    currentStatus = SAFE;
  }

  
  if (currentStatus != previousStatus) {

    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);

    switch (currentStatus) {

      case STOP:
        digitalWrite(red, HIGH);
        digitalWrite(green, LOW);
        lcd.print("STOP!!!");
        break;

      case CAUTION:
        digitalWrite(red, HIGH);
        digitalWrite(green, HIGH);
        lcd.print("CAUTION!!!");
        break;

      case SAFE:
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
        lcd.print("SAFE");
        break;
    }

    previousStatus = currentStatus;
  }
}
