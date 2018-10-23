int lm1=6;
int lm2=9;
int rm2=10;
int rm1=11;

  //trig-8, echo-12
void setup() 
{
  
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(rm2,HIGH);
  digitalWrite(lm1,LOW);
  digitalWrite(rm2,LOW);
  digitalWrite(lm2,LOW);
  
  
 /* delay(5000);
digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  delay(5000);*/

  /*left_turn();
  delay(225);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  delay(5000);*/

}

void left_turn()
{
  digitalWrite(rm1,HIGH);
  digitalWrite(lm2,HIGH);
  digitalWrite(lm1,LOW);
  digitalWrite(rm2,LOW);
  delay(1);
 /* analogWrite(lm1,0);
  analogWrite(rm1,0);
  digitalWrite(rm2,LOW);
  digitalWrite(lm2,LOW);
  delay(1);*/
  Serial.println("Left turn");
}
void right_turn()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(rm2,HIGH);
  digitalWrite(rm1,LOW);
  digitalWrite(lm2,LOW);
  delay(1);
  /*analogWrite(lm1,0);
  analogWrite(rm1,0);
  digitalWrite(rm2,LOW);
  digitalWrite(lm2,LOW);
  delay(1);*/
  
  Serial.println("Right turn");
}
