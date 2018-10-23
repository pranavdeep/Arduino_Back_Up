 //improvement of opt 2   trying to provide a left priority for bot
int lm1=6;
int lm2=5;
int rm1=4;
int rm2=2;
int ss1=51;
int ss2=49;
int ss3=47;
int ss4=45;
int ss5=43;
int ss6=41;
int ss7=39;
int ss8=37;
int a,b,c,d,e,f,g,h,dabba;
int led=A0;

void setup()
{
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
  pinMode(led,OUTPUT);
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
if(a==LOW && h==LOW && ( d==HIGH || e==HIGH ))
{
straight();
}

else if(a==HIGH && b==HIGH && d==HIGH && e==HIGH && g==HIGH && h==HIGH)
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);
  if( (digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
  {

  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(250);
  if( (digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
  {
   digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  digitalWrite(led,HIGH);
  delay(10000);
  }
  else
  {
      leftturn();

  }
  }
  else{
    goto WELCOME;
    }
}

else if(a==HIGH && b==HIGH && h==LOW && (e==HIGH || d==HIGH))
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);
  if( (digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==LOW || digitalRead(ss8)==LOW ) ){

  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(250);
  
  leftturn();
  }
  else{
    goto WELCOME;
    }
}

else if(g==HIGH && h==HIGH && a==LOW && (e==HIGH || d==HIGH))
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);
  if( (digitalRead(ss1)==LOW || digitalRead(ss2)==LOW) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) ){
  
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(250); 
  
  if((digitalRead(ss4)==LOW && digitalRead(ss5)==LOW && digitalRead(ss1)==LOW && digitalRead(ss2)==LOW && digitalRead(ss3)==LOW && digitalRead(ss6)==LOW && digitalRead(ss7)==LOW
  && digitalRead(ss8)==LOW)){
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

else if(a==LOW && b==LOW && c==LOW && d==LOW && e==LOW && f==LOW && g==LOW && h==LOW)
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(250);
  turnover();
}


}



void straight()
{
  if( digitalRead(ss7)==LOW || digitalRead(ss3)==HIGH ){
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    analogWrite(rm1, 250);
    digitalWrite(rm2, LOW);
    delay(1);
    return;
  }
  if(digitalRead(ss2)==LOW || digitalRead(ss6)==HIGH ){
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    analogWrite(lm1, 180);
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
    while(digitalRead(ss1)==LOW)
    {
      analogWrite(lm1, 0);
      analogWrite(lm2, 250);
      analogWrite(rm1, 250);
      analogWrite(rm2, LOW);
      delay(3);
      /*digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(1);*/
      }
      while(digitalRead(ss4)==HIGH || digitalRead(ss5)==LOW){
      digitalWrite(lm1, LOW);
      analogWrite(lm2, 255);
      analogWrite(rm1, 255);
      digitalWrite(rm2, LOW);
      delay(3);
      /*digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
   digitalWrite(rm2, LOW);
      delay(2);*/
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
  while(digitalRead(ss1)==LOW){
    digitalWrite(lm1, LOW);
    analogWrite(lm2,180);
    analogWrite(rm1, 180);
    digitalWrite(rm2, LOW);
    delay(3);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);*/
    }
    while(digitalRead(ss4)==LOW || digitalRead(ss5)==LOW){
    digitalWrite(lm1, LOW);
    analogWrite(lm2, 255);
    analogWrite(rm1, 255);
    digitalWrite(rm2, LOW);
    delay(3);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(2);*/
    }

    if(digitalRead(ss5)==HIGH){
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);
      }
      
  }

void rightturn(){
    while(digitalRead(ss8)==LOW){
    analogWrite(lm1, 250);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    analogWrite(rm2, 250);
    delay(3);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);*/
    }

    while(digitalRead(ss4)==LOW || digitalRead(ss5)==LOW){
    analogWrite(lm1, 250);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    analogWrite(rm2, 250);
    delay(3);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(2);*/
    }
    if(digitalRead(ss5)==HIGH){
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);
      }
      
  }
