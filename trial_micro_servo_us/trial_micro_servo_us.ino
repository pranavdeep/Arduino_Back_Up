

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
 usCheck();
  if(obj==0)
  Serial.println("Object Unidentified");
}

void usCheck()
{
  if(obj==1)
  {
    ultrasonic();
    if ((distance>=0 ) && (distance<=20) )
  {
    Serial.println("Object stays in the same place");
    //temp=1;
    flag=true; 
       //myservo.write(90);
  }
  else
  flag=false;
  
  if(flag==false)
    search();
 
  }
  else if(obj==0)
  {
    ultrasonic();
    if ((distance>=8) && (distance<=20) )
  {
    Serial.println("Object identified");
    obj=1;
    //flag=true;    
    myservo.write(90);
  }
  }
  
}

void search()
{
  if(obj==1)
  {
    while(flag==false)
    {
      if(check==0)
      anti_clock_wise();
      else if(check==1)
      clock_wise();
    }
    if(flag==true)
    {
      Serial.println("Object found");
      //
      myservo.write(90);
      
    }
    usCheck();
  }
}

void anti_clock_wise()
{
  usCheck();
  for (pos = 90; ((pos <= 180) && (flag==false) ); pos += 1) 
  { 
    Serial.println("Rotating ackwise");
    myservo.write(pos);              
    //delay(15);                       
  }
 
  //usCheck();
  if(pos>=180)
  check=1;
}
void clock_wise()
{
  usCheck();
  for (pos = 180; ((pos >= 0) && (flag==false)  ); pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    //delay(15);                       // waits 15ms for the servo to reach the position
    Serial.println("Rotating clockwise");
  }
  //usCheck();
  if(pos<=0)
  check=0;
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
/*
Serial.print("Distance=");
Serial.println(distance);*/

}

