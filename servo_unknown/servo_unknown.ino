#include <Servo.h>
Servo myservo;  // create servo object to control a servo
               // a maximum of eight servo objects can be created
   // variable to store the servo position
int trigPin = 5;
int echoPin = 6;

long duration;
int distance,temp,temp1,pos,i,obj,crazy=0;
const long interval = 1000;
unsigned long previousMillis = 0; 
unsigned long currentMillis=0; 
bool flag=false;


void setup() {
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
myservo.write(90);
}
void loop() 
{
//checktime();
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
       myservo.write(90);
  }
  else
  {
  flag=false;
  }
  if(flag==false)
  {
    search();
  }
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
    right_turn();
    usCheck();
    }
    if(flag==true)
    {
      Serial.println("Object found");
      myservo.write(90);
      usCheck();
    }
    
  }
}

void right_turn()
{
  if( (temp==0) && (flag==false) )
  left();
  if( (temp==1) && (flag==false) )
  right();
}

void left()
{
if(temp==0) 
{
  for(pos = 0 ;pos <= 720; pos += 1)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    
     myservo.write(105);  // Serial.println("Turning Left");
     // tell servo to go to position in variable 'pos'
     //delay(7);                       // waits 15ms for the servo to reach the position
  }
     if(pos>=720)
  {
    temp=1;
    crazy=1;
    Serial.println(" crazy=1");
    //myservo.write(90); 
    Serial.println(" Left turn completed");
    return;
  }
  }
}


void right()
{
if (temp==1) //&& (flag==false) )
{
  for(pos =720; pos >= 0; pos -= 1)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    
     myservo.write(80);              // tell servo to go to position in variable 'pos'
     //delay(7);                       // waits 15ms for the servo to reach the position
     //Serial.println("Turning Right");
  }
     if(pos<=0)
  {
    temp=0;
    //myservo.write(90); 
    Serial.println(" Right turn completed");
    return;
  }
  }
}


void ultrasonic()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds
distance = (duration/2) / 29.1;
/*
Serial.print("Distance=");
Serial.println(distance);*/

}


 
