int button = 2;
int previous = HIGH;
int current = HIGH;
int led_state = LOW;
int led = 6;

void setup(){
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop(){
  current = digitalRead(button);

  if (current == LOW && previous == HIGH){
    led_state = !led_state;
  }

  digitalWrite(led, led_state);

  previous = current;
}
