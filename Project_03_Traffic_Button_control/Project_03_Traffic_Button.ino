int red = 13;
int yellow = 12;
int green = 11;
int button = 2;

bool request = false;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  pinMode(button, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  // ---- INPUT CHECK (always safe) ----
  if (digitalRead(button) == LOW) {
    request = true;
    Serial.println("REQUEST STORED");
  }

  // ---- RED PHASE ----
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(5000);

  // ---- RED + YELLOW PHASE ----
  digitalWrite(yellow, HIGH);
  delay(2000);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);

  // ---- GREEN PHASE ----
  digitalWrite(green, HIGH);
  delay(5000);
  digitalWrite(green, LOW);

  // ---- DECISION POINT ----
  if (request == true) {

    Serial.println("REQUEST ACTIVE");

    // yellow blink 3 times
    for (int i = 0; i < 3; i++) {
      digitalWrite(yellow, HIGH);
      delay(500);
      digitalWrite(yellow, LOW);
      delay(500);
    }

    // extended red
    digitalWrite(red, HIGH);
    delay(8000);
    digitalWrite(red, LOW);

    request = false;
  }
  else {
    // normal yellow before restart
    digitalWrite(yellow, HIGH);
    delay(2000);
    digitalWrite(yellow, LOW);
  }
}
