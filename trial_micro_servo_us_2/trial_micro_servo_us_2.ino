
#include <Servo.h>

Servo myservo;  


   
int trigPin = 5;
int echoPin = 6;

long duration;
int distance,temp,temp1,pos,i,obj,check=0;
const long interval = 1000;
unsigned long previousMillis = 0; 
unsigned long currentMillis=0; 
bool flag=false;
void setup() {
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600);
 myservo.write(90);
}

void loop()
{
  ultrasonic();
  if(obj==1)
  {
    flag_check(); 
  if (flag==true )
  {
    myservo.write(90);
  }
  else
  {
    search();
  }
  }
  else
  {
    Serial.println("No object");
  }
  
}



void search()
{
      while(flag==false)
    {
      if(check==0)
      {
        Serial.println("Anti-clock");
        for (pos = 0; ((pos <= 180) && (flag==false) ); pos += 1) 
        {
          i++;
          myservo.write(pos);
          if(i==5)
          {
          myservo.write(90);
          i=0;
          }
          flag_check();              
         }
         //flag_check();
         check=1;
      }    
      
      else if(check==1)
      {
        Serial.println("clock");
        for (pos = 180; ((pos >= 0) && (flag==false) ); pos -= 1) 
        {
          myservo.write(pos);
         if(i==5)
          {
          myservo.write(90);
          i=0;
          }
          flag_check();             
         }
         //flag_check();
         check=0;
      }
      
      
    }
    if(flag==true)
    {
      Serial.println("Object found");
      myservo.write(90);
      delay(5);
      flag_check();
      return;
    }
    
  }



void flag_check()
{
  ultrasonic();
  if ((distance>=1) && (distance<=20) )
  flag=true;
  else
  flag=false;

  if(flag==true)
  {
  myservo.write(90);
  delay(1);
  }
}


 
void ultrasonic()
{
digitalWrite(trigPin, LOW);
//delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
//delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds
distance = (duration/2) / 29.1;
if ((distance>=8) && (distance<=20) )
obj=1;
/*
Serial.print("Distance=");
Serial.println(distance);*/

}

