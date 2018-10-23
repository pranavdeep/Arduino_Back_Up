 //improvement of opt 2   trying to provide a left priority for bot
 /*
  Doubt 1: Y have we not considered c or ss3 here?
  */
int lm1=10;
int lm2=9;
int rm1=6;
int rm2=5;
int ss1=13;//2 3 4 7 8 11 12 13
int ss2=12;
int ss3=11;
int ss4=8;
int ss5=7;
int ss6=4;
int ss7=3;
int ss8=2;
int a,b,c,d,e,f,g,h;


void setup()
{
  Serial.begin(9600);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(ss1,INPUT);
  pinMode(ss2,INPUT);
  pinMode(ss3,INPUT);
  pinMode(ss4,INPUT);
  pinMode(ss5,INPUT);
  pinMode(ss6,INPUT);
  pinMode(ss7,INPUT);
  pinMode(ss8,INPUT);
}
void readsensors(){
  a=digitalRead(ss1);
  b=digitalRead(ss2);
  
  c=digitalRead(ss3);
  
  d=digitalRead(ss4);
  e=digitalRead(ss5);
  
  f=digitalRead(ss6);
  
  g=digitalRead(ss7);
  h=digitalRead(ss8);
}
void loop()
{
  WELCOME :
  readsensors();
if(a==HIGH && h==HIGH && ( d==LOW || e==LOW ))
{
straight();
}

else if(a==LOW && b==LOW && d==LOW && e==LOW && g==LOW && h==LOW)
{
  digitalWrite(lm1,HIGH);//little straight
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(2000);

  //just to check if i have read correctly or not
  if((digitalRead(ss1)==LOW || digitalRead(ss2)==LOW) && ( digitalRead(ss4)==LOW || digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==LOW || digitalRead(ss8)==LOW ) )
  {//doubt 1:
  digitalWrite(lm1,HIGH);//
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(3000000);
  leftturn();
  }
  else{
    goto WELCOME;
    }
}

else if(a==LOW && b==LOW && h==HIGH && (e==LOW || d==LOW))
{
  //This condition actually means that both straight & left are available but take a left
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(2000);//just checking
  if( (digitalRead(ss1)==LOW || digitalRead(ss2)==LOW) && ( digitalRead(ss4)==LOW || digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
  {
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(300000);
  
  leftturn();
  }
  else{
    goto WELCOME;
    }
}
/*
else if(g==LOW && h==LOW && a==HIGH && (e==LOW || d==LOW))
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);
  if( (digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==LOW || digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==LOW || digitalRead(ss8)==LOW ) ){
  
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(300); 
  
  if((digitalRead(ss4)==HIGH && digitalRead(ss5)==HIGH && digitalRead(ss1)==HIGH && digitalRead(ss2)==HIGH && digitalRead(ss3)==HIGH && digitalRead(ss6)==HIGH && digitalRead(ss7)==HIGH
  && digitalRead(ss8)==HIGH)){
  rightturn();
  }
  else {
    straight();
    }
  }
  else{
    goto WELCOME;
    }
}

else if(a==HIGH && b==HIGH && c==HIGH && d==HIGH && e==HIGH && f==HIGH && g==HIGH && h==HIGH)
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(300);
  turnover();
}

*/
}



void straight()
{
  if( digitalRead(ss5)==HIGH || digitalRead(ss3)==LOW )
  {
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    return;
  }
  if(digitalRead(ss4)==HIGH || digitalRead(ss6)==LOW )
  {
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);
    return;
  }
 
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(5);
    
  }

void leftturn(){
  while(digitalRead(ss1)==HIGH){
    digitalWrite(lm1, LOW);//lm2 is right first motor..........rm1 right motor 2(behind).....lm1 is left first motor.....and rm2 is left second motor
    digitalWrite(lm2, HIGH);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);*/
    }
    while(digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH){
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);
    }
    if(digitalRead(ss5)==HIGH){
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);
      }
      
  }

void turnover(){
  while(digitalRead(ss1)==HIGH){
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);*/
    }
    while(digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH){
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);
    }

    if(digitalRead(ss5)==LOW){
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);
      }
      
  }

void rightturn(){
    while(digitalRead(ss8)==HIGH){
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, HIGH);
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);*/
    }

    while(digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH){
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, HIGH);
    delay(1);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);
    }
    if(digitalRead(ss4)==LOW){
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(1);
      }
      
  }
