 //working on the unspecified combinational sensors and their specific allotment
 
 int lm1=10;
int lm2=11;
int rm1=6;
int rm2=9;
int ss1=2;
int ss2=3;
int ss3=4;
int ss4=5;
int ss5=7;
int ss6=8;
int ss7=12;
int ss8=13;
int a,b,c,d,e,f,g,h;
int replaystage;

#define led 0

char path[30] = {};
int pathLength;
int readLength;

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

else if( (a==HIGH || b==HIGH) && (d==HIGH || e==HIGH) && (g==HIGH || h==HIGH)  )
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);
  if( (digitalRead(ss1)==HIGH && digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH && digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH && digitalRead(ss8)==HIGH ) ){

  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(140);
  
  leftturn();
  }
  else{
    goto WELCOME;
    }
}



else if((a==HIGH || b==HIGH) && (e==HIGH || d==HIGH) && (h==LOW || g==LOW)  )
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(25);
  if( (digitalRead(ss1)==HIGH && digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==LOW && digitalRead(ss8)==LOW ) ){

  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(150);
  
  leftturn();
  }
  else{
    goto WELCOME;
    }
}

else if( a==LOW && (g==HIGH || h==HIGH) && (e==HIGH || d==HIGH))
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(25);

  
  
  if( (digitalRead(ss1)==LOW && digitalRead(ss2)==LOW) && ( digitalRead(ss4)==HIGH && digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) ){
  
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(140); 
  
  if ( ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss8)==LOW ) && (digitalRead(ss1)==LOW ) ){
  straight();
  }

  else if( (digitalRead(ss1)==LOW && digitalRead(ss2)==LOW) && ( digitalRead(ss4)==LOW && digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==LOW && digitalRead(ss8)==LOW ) ) {
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(30);
       rightturn();
       
    }
   path[pathLength]='S';
   // Serial.println("s");
    pathLength++;
    //Serial.print("Path length: ");
    //Serial.println(pathLength);
    if(path[pathLength-2]=='B'){
    //Serial.println("shortening path");
    shortPath();
     }
    
  
  }

    else if( (digitalRead(ss1)==HIGH && digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH && digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH && digitalRead(ss8)==HIGH ) ){
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(140);
    leftturn();
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
  delay(25);
  if(a==LOW && b==LOW && c==LOW && d==LOW && e==LOW && f==LOW && g==LOW && h==LOW){

  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(130);
  
  turnover();
  }
  else {
    goto WELCOME;
    }
}


}



void done(){
  digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
  replaystage=1;
  path[pathLength]='D';
  pathLength++;
 while(digitalRead(leftFarSensor)==LOW){
   digitalWrite(led, LOW);
   delay(150);
   digitalWrite(led, HIGH);
   delay(150);
 }
 delay(500);
  replay();
}

void straight()
{
  if( digitalRead(ss5)==LOW || digitalRead(ss3)==HIGH ){
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    analogWrite(rm1, 180);
    digitalWrite(rm2, LOW);
    delay(1);
    return;
  }
  if(digitalRead(ss4)==LOW || digitalRead(ss6)==HIGH ){
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
    delay(1);
    
  }

void leftturn(){
  while(digitalRead(ss1)==LOW){
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
    while(digitalRead(ss3)==LOW || digitalRead(ss4)==LOW){
    digitalWrite(lm1, LOW);
    analogWrite(lm2, 180);
    analogWrite(rm1, 180);
    digitalWrite(rm2, LOW);
    delay(1);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(3);
    }
    if(digitalRead(ss5)==HIGH){
      analogWrite(lm1, 150);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      analogWrite(rm2, 150);
      delay(2);
      
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);
      }

        if(replaystage==0){
    path[pathLength]='L';
    pathLength++;
      if(path[pathLength-2]=='B'){
        shortPath();
      }
  }
      
  }

void turnover(){
  while(digitalRead(ss8)==LOW){
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

    while(digitalRead(ss5)==LOW || digitalRead(ss6)==LOW){
    analogWrite(lm1, 180);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    analogWrite(rm2, 180);
    delay(1);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(3);
    }
    if(digitalRead(ss4)==HIGH){
      digitalWrite(lm1, LOW);
      analogWrite(lm2, 150);
      analogWrite(rm1, 150);
      digitalWrite(rm2, LOW);
      delay(2);
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(3);
      }
      
  }

void rightturn(){
    while(digitalRead(ss8)==LOW){
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

    while(digitalRead(ss5)==LOW || digitalRead(ss6)==LOW){
    analogWrite(lm1, 180);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    analogWrite(rm2, 180);
    delay(1);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(3);
    }
    if(digitalRead(ss4)==HIGH){
      /*digitalWrite(lm1, LOW);
      analogWrite(lm2, 150);
      analogWrite(rm1, 150);
      digitalWrite(rm2, LOW);
      delay(1);*/
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);
      }
      
}
