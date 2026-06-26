int redA=13;
int yellowA=12;
int greenA=11;
int redB=8;
int yellowB=9;
int greenB=10;
int A_sigpin=A0;
int B_sigpin=A1;

enum State{
  A_GREEN_B_RED,
  A_YELLOW_B_RED,
  A_RED_B_GREEN,
  A_RED_B_YELLOW,
};

int A_greenTime=5000;
int B_greenTime=5000;

State currentState= A_GREEN_B_RED;
unsigned long A_sigpin_value;
unsigned long B_sigpin_value;
int A_distance;
int B_distance;
unsigned long startTime=0;
void setup(){
  pinMode(redA,OUTPUT);
  pinMode(redB, OUTPUT);
  pinMode(greenA,OUTPUT);
  pinMode(greenB, OUTPUT);
  pinMode(yellowA, OUTPUT);
  pinMode(yellowB, OUTPUT);
}

void loop(){
  pinMode(A_sigpin,OUTPUT);
  digitalWrite(A_sigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(A_sigpin,HIGH);
  delayMicroseconds(5);
  digitalWrite(A_sigpin,LOW);
  pinMode(A_sigpin,INPUT);
  A_sigpin_value= pulseIn(A_sigpin,HIGH);
  A_distance=A_sigpin_value/58;
    
  pinMode(B_sigpin, OUTPUT);
  digitalWrite(B_sigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(B_sigpin,HIGH);
  delayMicroseconds(5);
  digitalWrite(B_sigpin,LOW);
  pinMode(B_sigpin,INPUT);
  B_sigpin_value=pulseIn(B_sigpin,HIGH);
  B_distance=B_sigpin_value/58;
     
  switch(currentState){
    
    case A_GREEN_B_RED:
    digitalWrite(greenA,HIGH);
    digitalWrite(redB,HIGH);
    if(millis()-startTime>=A_greenTime){
      digitalWrite(greenA,LOW);
      currentState=A_YELLOW_B_RED;
      startTime=millis();
    }
    break;
    
    case A_YELLOW_B_RED:
    digitalWrite(yellowA,HIGH);
    if(millis()-startTime>=2000){
      digitalWrite(yellowA,LOW);
      digitalWrite(redB,LOW);
      currentState=A_RED_B_GREEN;
      if(B_distance<=10){
        B_greenTime=15000;
      }
      else if(B_distance<=30){
        B_greenTime=10000;
      }
      else{
        B_greenTime=5000;
      }
      startTime=millis();
    }
    break;
    
    case A_RED_B_GREEN:
    digitalWrite(redA, HIGH);
    digitalWrite(greenB, HIGH);
    if(millis()-startTime>=B_greenTime){
      digitalWrite(greenB,LOW);
      currentState=A_RED_B_YELLOW;
      startTime=millis();
    }
    break;
    
    case A_RED_B_YELLOW:
    digitalWrite(yellowB,HIGH);
    if(millis()-startTime>=2000){
      digitalWrite(yellowB,LOW);
      digitalWrite(redA,LOW);
      currentState=A_GREEN_B_RED;
      if(A_distance<=10){
        A_greenTime=15000;
      }
      else if(A_distance<=30){
        A_greenTime=10000;
      }
      else{
        A_greenTime=5000;
      }
      startTime=millis();
    }
    break;
    
  }
  
}
