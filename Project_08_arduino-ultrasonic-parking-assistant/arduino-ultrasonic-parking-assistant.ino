int sigpin=7;
int red=8;
int yellow=9;
int green=10;
unsigned long value;
int distance;

void setup(){
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop(){
  pinMode(sigpin,OUTPUT);
  digitalWrite(sigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(sigpin,HIGH);
  delayMicroseconds(5);
  digitalWrite(sigpin,LOW);
  pinMode(sigpin,INPUT);
  value=pulseIn(sigpin,HIGH);
  distance=value/58;
  
  if(distance<=10){
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);
  }
  else if(distance>=11 && distance<=30){
    digitalWrite(red,LOW);
    digitalWrite(yellow,HIGH);
    digitalWrite(green,LOW);
  }
  else{
    digitalWrite(red,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(green,HIGH);
  }
  
}
