#define S0 8
#define S1 13
#define S2 2
#define S3 12
#define sensorOut 7
int rf = 0;
int bf,gf=0;
int frequency=0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  rf = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
 //frequency = map(frequency, 418,470,255,0);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(rf);//printing RED color frequency
  /*Serial.print("frequency=");
  Serial.println(frequency);*/
  Serial.print("  ");
  delay(500);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  gf = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  //frequency = map(frequency, 30,90,255,0);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(gf);//printing RED color frequency
  Serial.print("  ");
  delay(500);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  bf = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  //frequency = map(frequency, 25,70,255,0);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(bf);//printing RED color frequency
  Serial.println("  ");
  delay(500);
  /*if ((rf<gf)&&(rf<bf))
  {
    Serial.println("Red Detected");
  delay(500);
  }
  //else if( 
/*if((rf>=418)&&(rf<=470)&&(gf>=600)&&(gf<=690)&&(bf>=520)&&(bf<=620))
{
  Serial.println("Green Detected");
  delay(522);
}
else if((rf>=375)&&(rf<=420)&&(gf>=550)&&(gf<=650)&&(bf>=580)&&(bf<=630))
{
  Serial.println("Red Detected");
  delay(500);
  }
else if((rf>=350)&&(rf<=400)&&(gf>=550)&&(gf<=650)&&(bf>=450)&&(bf<=550))
{
  Serial.println("Yellow Detected");
  }*/
  
  }
  












void leftturn()
    {
      Serial.println("CHECK");
      while(digitalRead(ss1)==LOW)
    {
      analogWrite(lm1, 0);
      analogWrite(lm2, 250);
      analogWrite(rm1, 250);
      analogWrite(rm2, LOW);
      delay(3);
    }
    while(digitalRead(ss4)==LOW || digitalRead(ss5)==LOW){
      digitalWrite(lm1, LOW);
      analogWrite(lm2, 255);
      analogWrite(rm1, 255);
      digitalWrite(rm2, LOW);
      delay(3);
    }
     if(digitalRead(ss5)==HIGH){
        digitalWrite(lm1, LOW);
        digitalWrite(lm2, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);
        delay(2);
        }
    }









    void rightturn()
    {
      analogWrite(lm1,255);
  digitalWrite(lm2,LOW);
  analogWrite(rm1,0);
  analogWrite(rm2,215);
 delay(700);
 straight();
 delay(5);

      if(digitalRead(ss4)==HIGH){
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);
      }
      }
