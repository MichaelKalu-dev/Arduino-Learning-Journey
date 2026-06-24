int redA=13;
int yellowA=12;
int greenA=11;
int redB=10;
int yellowB=9;
int greenB=8;

enum trafficState{
  RED_A_GREEN_B,
  RED_A_YELLOW_B,
  GREEN_A_RED_B,
  YELLOW_A_RED_B,
};
trafficState currentState=RED_A_GREEN_B;
unsigned long startTime=0;

void setup(){
  pinMode(redA,OUTPUT);
  pinMode(redB, OUTPUT);
  pinMode(yellowA,OUTPUT);
  pinMode(yellowB,OUTPUT);
  pinMode(greenA,OUTPUT);
  pinMode(greenB,OUTPUT);
}

void loop(){
  switch(currentState){
    case RED_A_GREEN_B:
    digitalWrite(redA,HIGH);
    digitalWrite(greenB,HIGH);
    
    if(millis()-startTime>=5000){
      digitalWrite(greenB,LOW);
      currentState=RED_A_YELLOW_B;
      startTime=millis();
    }
    break;
    
    case RED_A_YELLOW_B:
    digitalWrite(yellowB,HIGH);
    
    if(millis()-startTime>=2000){
      digitalWrite(redA,LOW);
      digitalWrite(yellowB,LOW);
      currentState=GREEN_A_RED_B;
      startTime=millis();
    }
    break;
    
    case GREEN_A_RED_B:
    digitalWrite(greenA,HIGH);
    digitalWrite(redB,HIGH);
    if(millis()-startTime>=5000){
      digitalWrite(greenA,LOW);
      currentState=YELLOW_A_RED_B;
      startTime=millis();
    }
    break;
    
    case YELLOW_A_RED_B:
    digitalWrite(yellowA,HIGH);
    if(millis()-startTime>=2000){
      digitalWrite(yellowA,LOW);
      digitalWrite(redB,LOW);
      currentState=RED_A_GREEN_B;
      startTime=millis();
    }
    break;
    
  }
}
  
