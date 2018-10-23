int lm1 = 3;// defines pin 3 as connected to the motor
int lm2 = 5;// defines pin 6 as connected to the motor
int rm1= 6;// defines pin 5 as connected to the motor
int rm2 = 9;// defines pin 9 as connected to the motor


void setup()
{
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  //trial();

}
void loop()
{
analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(lm1,255);
  analogWrite(rm2,0);
}
  /*analogWrite(rm1,255);
  analogWrite(rm2,0);
 delay(2000);
 analogWrite(lm1,0);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,0);
delay(5000);


analogWrite(lm1,255);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,255);
 delay(2000);
 analogWrite(lm1,0);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,0);
delay(5000);


analogWrite(lm2,255);
  analogWrite(lm1,0);
  analogWrite(rm1,255);
  analogWrite(rm2,0);
 delay(2000);
 analogWrite(lm1,0);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,0);
delay(5000);
 
}

/*void trial()
{
  analogWrite(lm1,255);
  analogWrite(lm2,0);
  analogWrite(rm1,255);
  analogWrite(rm2,0);
 delay(1000);
  analogWrite(lm1,0);
  analogWrite(lm2,255);
  analogWrite(rm1,0);
  analogWrite(rm2,255);
  delay(1000);
}
*/
