int red=10;
int blue=11;
int green=12;
int pot= A0;
int potvalue;

enum State{
  Off,
  Low,
  Medium,
  High,
};
State fanSpeed=Off;

void setup(){
  pinMode(red,OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop(){
  potvalue= analogRead(pot);
  
  
  if(potvalue>=0 && potvalue<=255){
    fanSpeed=Off;
  }
  else if(potvalue>=256 && potvalue<=511){
    fanSpeed=Low;
  }
  else if(potvalue>=512 && potvalue<=767){
    fanSpeed=Medium;
  }
  else{
    fanSpeed=High;
  }
  
  switch(fanSpeed){
    
    case Off:
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    digitalWrite(green,LOW);
    
    break;
    
    case Low:
    digitalWrite(red,HIGH);
    digitalWrite(blue,LOW);
    digitalWrite(green,LOW);
    
    break;
    
    case Medium:
    digitalWrite(red, HIGH);
    digitalWrite(blue,HIGH);
    digitalWrite(green,LOW);
    
    break;
    
    case High:
    digitalWrite(red,HIGH);
    digitalWrite(blue,HIGH);
    digitalWrite(green,HIGH);
    
    break;
  }
  
}
