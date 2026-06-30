int sigpin = 7;
unsigned long pulseTime;
int currentDistance;
int previousDistance = 0;
int carCount = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  pinMode(sigpin, OUTPUT);
  digitalWrite(sigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(sigpin, HIGH);
  delayMicroseconds(5);
  digitalWrite(sigpin, LOW);

  
  pinMode(sigpin, INPUT);
  pulseTime = pulseIn(sigpin, HIGH);
  currentDistance = pulseTime / 58;

  
  if (previousDistance > 10 && currentDistance <= 10) {
    carCount++;
    Serial.print("Vehicle Count: ");
    Serial.println(carCount);
  }

  
  previousDistance = currentDistance;
}
