int red = 13;
int yellow = 12;
int green = 11;
int blue = 10;
int button = 2;

enum TrafficState {
  RED,
  YELLOW_TO_GREEN,
  GREEN,
  YELLOW_TO_RED,
  PED_BLINK_START,
  PED_BLUE,
  PED_BLINK_END
};

TrafficState currentState = RED;

unsigned long stateStartTime = 0;

bool pedRequest = false;

// Button edge detection
int previousButtonState = HIGH;

// Blink variables
bool yellowState = LOW;
int blinkCount = 0;


void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}


void loop() {

  // Only accept button presses during normal traffic mode
  if (currentState != PED_BLINK_START &&
      currentState != PED_BLUE &&
      currentState != PED_BLINK_END) {

    int currentButtonState = digitalRead(button);

    if (previousButtonState == HIGH && currentButtonState == LOW) {
      pedRequest = true;
    }

    previousButtonState = currentButtonState;
  }


  switch (currentState) {

    case RED:
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);

      if (millis() - stateStartTime >= 5000) {
        currentState = YELLOW_TO_GREEN;
        stateStartTime = millis();
      }
      break;


    case YELLOW_TO_GREEN:
      digitalWrite(red, LOW);
      digitalWrite(yellow, HIGH);
      digitalWrite(green, LOW);

      if (millis() - stateStartTime >= 2000) {
        currentState = GREEN;
        stateStartTime = millis();
      }
      break;


    case GREEN:
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, HIGH);

      if (millis() - stateStartTime >= 5000) {
        currentState = YELLOW_TO_RED;
        stateStartTime = millis();
      }
      break;


    case YELLOW_TO_RED:
      digitalWrite(red, LOW);
      digitalWrite(yellow, HIGH);
      digitalWrite(green, LOW);

      if (millis() - stateStartTime >= 2000) {

        if (pedRequest) {
          pedRequest = false;
          blinkCount = 0;
          yellowState = LOW;
          currentState = PED_BLINK_START;
        }
        else {
          currentState = RED;
        }

        stateStartTime = millis();
      }

      break;


    case PED_BLINK_START:
    case PED_BLINK_END:

      if (millis() - stateStartTime >= 500) {

        yellowState = !yellowState;
        digitalWrite(yellow, yellowState);

        stateStartTime = millis();

        // Count only when the light goes OFF
        if (yellowState == LOW) {
          blinkCount++;
        }
      }


      if (blinkCount >= 3) {

        digitalWrite(yellow, LOW);
        blinkCount = 0;

        if (currentState == PED_BLINK_START) {
          currentState = PED_BLUE;
        }
        else {
          currentState = RED;
        }

        stateStartTime = millis();
      }

      break;


    case PED_BLUE:

      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, HIGH);


      if (millis() - stateStartTime >= 5000) {

        digitalWrite(blue, LOW);

        blinkCount = 0;
        yellowState = LOW;

        currentState = PED_BLINK_END;
        stateStartTime = millis();
      }

      break;
  }
}
