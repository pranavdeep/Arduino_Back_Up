
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
int indicator[3];
int distance,duration;
int i=0;
int color;
int flag=0;
#define trigPin 11
#define echoPin 12
#define S0 8
#define S1 13
#define S2 2
#define S3 12
#define sensorOut 7
int rf = 0;
int bf,gf=0;
int frequency=0;

void setup() {
  // put your setup code here, to run once:
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
  pinMode(led,OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  /*ultrasonic();
  Serial.print("Distance=");
  Serial.println(distance);*/
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
void loop() {
  // put your main code here, to run repeatedly:
 WELCOME :
  readsensors();
if(a==LOW && h==LOW && ( d==HIGH || e==HIGH ))
{
straight();
}
else if(a==HIGH && b==HIGH && h==LOW && (e==HIGH || d==HIGH))
{
  analogWrite(lm1,150);
  digitalWrite(lm2,LOW);
    analogWrite(rm1,150);
//(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);
  if( (digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==LOW || digitalRead(ss8)==LOW ) )
  {
  analogWrite(lm1,120);
  digitalWrite(lm2,LOW);
  analogWrite(rm1,120);
  digitalWrite(rm2,LOW);
  delay(250);
  ultrasonic();
  delay(500);
  /*Serial.print("Distance=");
  Serial.println(distance);*/
  if (distance<=5)
  {
     digitalWrite(lm1,LOW);
     digitalWrite(lm2,LOW);
     digitalWrite(rm1,LOW);
     digitalWrite(rm2,LOW);
     delay(2000);
  colorsensing();
  indicator[i]=color;
  i++;
  reverse();
  delay(200);
  leftturn();
  }
  else{
    goto WELCOME;
  }
  /*reverse();//this is just little reverse
  delay(200);
  leftturn();*/
  }
}
else if(g==HIGH && h==HIGH && a==LOW && (e==HIGH || d==HIGH))
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);
  if( (digitalRead(ss1)==LOW || digitalRead(ss2)==LOW) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
  {
      analogWrite(lm1,150);
  digitalWrite(lm2,LOW);
   analogWrite(rm1,150);
  digitalWrite(rm2,LOW);
  delay(200); 
    ultrasonic();
    delay(500);
    if(distance<=5)
    {
      digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
    delay(500);
       colorsensing();
       indicator[i]=color;
       i++;
     
    reverse();
    delay(100);
    rightturn();
    }
  }
}
else if(a==HIGH && b==HIGH && d==HIGH && e==HIGH && g==HIGH && h==HIGH)
{
  analogWrite(lm1,150);
  digitalWrite(lm2,LOW);
    analogWrite(rm1,150);
  digitalWrite(rm2,LOW);
  delay(20);
    if( (digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
  {
      if(flag==0)
      {
       ultrasonic();
       delay(500);       
       while(distance>5)
       {
        straight();
       }
       if(distance<=5)
       {
          digitalWrite(lm1,LOW);
         digitalWrite(lm2,LOW);
         digitalWrite(rm1,LOW);
          digitalWrite(rm2,LOW);
          
               //straight();
            
       colorsensing();
      //pickup();        
      delay(100);
       reverse();//reverse of straight function
       delay(100);
       turnover();
       }
      }
      } 
}
}
void straight()
{
  ultrasonic();
  if(distance<=5)
  {
    digitalWrite(lm1,LOW);
         digitalWrite(lm2,LOW);
         digitalWrite(rm1,LOW);
          digitalWrite(rm2,LOW);
          delay(2000);
          colorsensing();
          delay(1000);
          reverse();
          delay(100);
          leftturn();
  }
  if( digitalRead(ss6)==LOW || digitalRead(ss2)==HIGH )
  {
  analogWrite(lm1, 165);
    digitalWrite(lm2, LOW);
    analogWrite(rm1, 165);
    digitalWrite(rm2, LOW);
    delay(1);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    analogWrite(rm1, 180);
    digitalWrite(rm2, LOW);
    delay(1);
    return;         
  }
  if(digitalRead(ss3)==LOW || digitalRead(ss7)==HIGH ){
    analogWrite(lm1, 165);
    digitalWrite(lm2, LOW);
    analogWrite(rm1, 165);
    digitalWrite(rm2, LOW);
    delay(1);
    analogWrite(lm1, 180);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);
    return;
  }
     analogWrite(lm1, 160);
     digitalWrite(lm2, LOW);
     analogWrite(rm1, 160);
      digitalWrite(rm2, LOW);
    delay(5);
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
      while(digitalRead(ss8)==LOW){
    analogWrite(lm1, 250);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    analogWrite(rm2, 250);
    delay(3);
      }
      while(digitalRead(ss4)==LOW || digitalRead(ss5)==LOW){
    analogWrite(lm1, 250);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    analogWrite(rm2, 250);
    delay(3);
    }
      if(digitalRead(ss4)==HIGH){
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);
      }
      }
      void reverse()
      {
        digitalWrite(lm2,HIGH);
        digitalWrite(rm2,HIGH);
        digitalWrite(rm1,LOW);
        digitalWrite(lm1,LOW);
        delay(500);
      }
      void colorsensing()
      {
          digitalWrite(S2,LOW);
          digitalWrite(S3,LOW);
   rf = pulseIn(sensorOut, LOW);
   Serial.println("red");
   delay(500);
   digitalWrite(S2,HIGH);
   digitalWrite(S3,HIGH);
   gf = pulseIn(sensorOut, LOW);
    Serial.println("green");
   digitalWrite(S2,LOW);
   digitalWrite(S3,HIGH);
   bf = pulseIn(sensorOut, LOW);
   Serial.println("blue"); 
      }
      
      
      void turnover()
      {
        while(digitalRead(ss1)==LOW){
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
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
void ultrasonic()
{
    digitalWrite(trigPin, LOW);
delayMicroseconds(25);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
}
