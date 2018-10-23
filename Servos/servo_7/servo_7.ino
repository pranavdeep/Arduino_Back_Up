#include <Servo.h>

Servo myservo; 


int currentMillis,previousMillis,temp=0;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(10);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//currentMillis=millis();
if(temp==0)
{
 left();
}
else if(temp==2)
{
  right();
}
else 
{
  stop1();
}


}
/*
void right()
{
  while(delay1(200)==false)
  {
    myservo.write(105);
      }
}


bool delay1(int timee)
{
  if(currentMillis-previousMillis<timee)
  {
    return true;
  }
  else if(currentMillis-previousMillis>=timee)
  {
    return false;
  }*/
  void left()
{
  temp++;
  myservo.write(105);
  Serial.println("left");
  delay(1200);
}
void stop1()
{
  temp++;
  myservo.write(90);
  delay(1000);
}

void right()
{
 temp++;
  myservo.write(80);
  Serial.println("right");
  delay(1700);
}


