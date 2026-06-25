int sigpin=7;
int red=8;
int yellow=9;
int green=10;
unsigned long value;
int distance;
int greenTime;

enum State{
  GREEN,
  RED,
  YELLOW1,
  YELLOW2,
};
State currentState=RED;
unsigned long startTime=0;

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
  
    switch(currentState){
    
    case RED:
    digitalWrite(red,HIGH);
    if(millis()-startTime>=5000){
      digitalWrite(red,LOW);
      currentState=YELLOW1;
      startTime=millis();
    }
    break;
    
    case YELLOW1:
    digitalWrite(yellow,HIGH);
    if(millis()-startTime>=2000){
      digitalWrite(yellow,LOW);
      currentState=GREEN;
      pinMode(sigpin, INPUT);
      value=pulseIn(sigpin,HIGH);
      distance=value/58;
      if(distance<=10){
        greenTime=15000;
      }
      else if(distance<=30){
        greenTime=10000;
      }else{
         greenTime=5000;
      }
          
      startTime=millis();
    }
    break;
    
    case GREEN:
    digitalWrite(green,HIGH);
    
    if(millis()-startTime>=greenTime){
      digitalWrite(green,LOW);
      currentState=YELLOW2;
      startTime=millis();
    }
    break;
    
    case YELLOW2:
    digitalWrite(yellow,HIGH);
    if(millis()-startTime>=2000){
      digitalWrite(yellow,LOW);
      currentState=RED;
      startTime=millis();
    }
    break;
    
    
  }
   
}
