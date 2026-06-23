int button = 2;
int pot = A0;

int red = 13;
int yellow = 12;
int green = 11;
int blue = 10;

bool pedReq = false;

int pedBlinkCount = 0;
int pedBlinkState = 0;

int greenTime = 5000;

unsigned long starttime = 0;

enum State {
  RED,
  YELLOW1,
  GREEN,
  YELLOW2,
  PEDBLINK1,
  PEDBLUE,
  PEDBLINK2
};

State currentState = RED;

void setup() {
  pinMode(button, INPUT_PULLUP);

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  if (digitalRead(button) == LOW) {
    pedReq = true;
  }

  switch (currentState) {
    case RED:
      digitalWrite(red, HIGH);

      if (millis() - starttime >= 5000) {
        digitalWrite(red, LOW);
        starttime = millis();
        currentState = YELLOW1;
      }
      break;
    case YELLOW1:
      digitalWrite(yellow, HIGH);
      int potvalue = analogRead(pot);

      if (potvalue <= 341) {
        greenTime = 5000;
      } 
      else if (potvalue <= 682) {
        greenTime = 10000;
      } 
      else {
        greenTime = 15000;
      }

      if (millis() - starttime >= 2000) {
        digitalWrite(yellow, LOW);
        starttime = millis();
        currentState = GREEN;
      }
      break;
    case GREEN:
      digitalWrite(green, HIGH);

      if (millis() - starttime >= greenTime) {
        digitalWrite(green, LOW);
        starttime = millis();
        currentState = YELLOW2;
      }
      break;
    case YELLOW2:
      digitalWrite(yellow, HIGH);

      if (millis() - starttime >= 2000) {
        digitalWrite(yellow, LOW);

        if (pedReq) {
          currentState = PEDBLINK1;
        } else {
          currentState = RED;
        }

        starttime = millis();
      }
      break;
    case PEDBLINK1:

      if (pedBlinkCount >= 3) {
        pedBlinkCount = 0;
        currentState = PEDBLUE;
        starttime = millis();
      } 
      else {
        if (pedBlinkState == 0 && millis() - starttime >= 500) {
          digitalWrite(yellow, HIGH);
          pedBlinkState = 1;
          starttime = millis();
        }
        else if (pedBlinkState == 1 && millis() - starttime >= 500) {
          digitalWrite(yellow, LOW);
          pedBlinkState = 0;
          pedBlinkCount++;
          starttime = millis();
        }
      }
      break;
    case PEDBLUE:
      digitalWrite(blue, HIGH);

      if (millis() - starttime >= 5000) {
        digitalWrite(blue, LOW);
        currentState = PEDBLINK2;
        starttime = millis();
      }
      break;
    case PEDBLINK2:

      if (pedBlinkCount >= 3) {
        pedBlinkCount = 0;
        pedReq = false;
        currentState = RED;
        starttime = millis();
      } 
      else {
        if (pedBlinkState == 0 && millis() - starttime >= 500) {
          digitalWrite(yellow, HIGH);
          pedBlinkState = 1;
          starttime = millis();
        }
        else if (pedBlinkState == 1 && millis() - starttime >= 500) {
          digitalWrite(yellow, LOW);
          pedBlinkState = 0;
          pedBlinkCount++;
          starttime = millis();
        }
      }
      break;
  }
}
