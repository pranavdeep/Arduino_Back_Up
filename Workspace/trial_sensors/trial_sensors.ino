int lm1 = 10;
int lm2 = 9;
int rm1 = 6;
int rm2 = 5;



int ss1 = 13;
int ss2 = 12;
int ss3 = 11;
int ss4 = 8;
int ss5 = 7;
int ss6 = 4;
int ss7 = 3;
int ss8 = 2;
int a, b, c, d, e, f, g, h;

char path[30] = {};
int pathLength;
int readLength;


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
//    pinMode(toogle,INPUT);
 /*   trial1();


void trial1()
{
  if(a==HIGH && h==HIGH && ( d==LOW || e==LOW ))
{
straight();
 //Serial.println("1");

}
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
    digitalWrite(rm1, HIGH);//CHANGING FROM 180 TO HIGH
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
    digitalWrite(lm1, HIGH);//CHANGING FROM 180 TO HIGH
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
    
  }*/
void loop()
{
  a=digitalRead(ss1);
   Serial.print("a=");
  Serial.print(a);
  delay(500);
  b=digitalRead(ss2);
  Serial.print("    b=");
  Serial.print(b);
  delay(500);
  c=digitalRead(ss3);
  Serial.print("   c=");
  Serial.print(c);
  delay(500);
  d=digitalRead(ss4);
  Serial.print("    d=");
  Serial.print(d);
  delay(500);
  e=digitalRead(ss5);
  Serial.print("     e=");
  Serial.print(e);
  delay(500);
  f=digitalRead(ss6);
  Serial.print("     f=");
  Serial.print(f);
  delay(500);
  g=digitalRead(ss7);
  Serial.print("    g=");
  Serial.print(g);
  delay(500);
  h=digitalRead(ss8);
  Serial.print("    h=");
  Serial.print(h);
  delay(1000);
  Serial.println(" ");
}
  /*dabba=digitalRead(toogle);
  Serial.print("dabba=");
  Serial.print(dabba);
  delay(1000);
    Serial.println(" ");*/
    /*digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);//very minute distance just to verify*/




/*void loop()
{
 WELCOME :
  readsensors();

if(a==LOW && b==LOW && h==HIGH && (e==LOW || d==LOW))
{
  //This condition actually means that both straight & left are available but take a left
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);//just checking
  if( (digitalRead(ss1)==LOW || digitalRead(ss2)==LOW) && ( digitalRead(ss4)==LOW || digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
  {
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(300);
  
  leftturn();
  }
else{
    goto WELCOME;
    }
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

   /* while(digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH){
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
}*/

