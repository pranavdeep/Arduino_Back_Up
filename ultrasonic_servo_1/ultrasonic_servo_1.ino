#include <Servo.h>

int trigPin = 5;
int echoPin = 6;

Servo myservo,myservo2;//myservo-horizontal//myservo2-vertical servo

// defines variables
long duration;
int distance,temp,temp1,pos,i=0;
const long interval = 1000;
unsigned long previousMillis = 0; 
unsigned long currentMillis=0; 
bool flag=false;

void setup() 
{
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); 
myservo.attach(10); 
}

void loop() 
{
  checktime();
  //currentMillis = millis();
   usCheck();
  if(temp==0)
  Serial.println("Object Unidentified");
}
  

void search()
{
  
  if (temp==1) 
  {
    
    //if time is not completed
    //move the servo to its left slowly and try to identify the object
      //usCheck();
      //this condition checks if object is found or not 
      //temp1 is used to toogle pulses between right and left so that servo alternatively moves left left for the specified angles
    while( (flag==false) && (temp1==0) )
    {// check left   
      for(i=100; i<=150; i+=1)//changing from 135 to 120 
      {   
      myservo.write(i);
      //myservo.write(90);
      temp1=1;
          //delay(15);
      }
     /* if(i>=150)
      {
      temp1=1;
      
      Serial.println("Making temp1=1");*/
      usCheck();
      checktime();
      //}
      
      Serial.println("Servo checking on left");
      //temp1=1;
      //usCheck();
    }
    while( (flag==false) && (temp1==1) )
    {// check right     
      for (i=85 ; i>=35 ; i-=1 )
      {
      myservo.write(i);
      temp1=0;
      //myservo.write(90);
      }
     /* if(i<=35)
      {
      temp1=0;
      Serial.println("Making temp1=0");
      //myservo.write(90);*/
      usCheck();
      checktime();
      //}
      
      Serial.println("Servo checking on right");
      //usCheck();
    }
    if(flag==true)
    {
    Serial.println("Object found");
    myservo.write(90);
    }
  }
  /*else if (temp==0)
  {
    while(!flag)
    {
      myservo.write(105);
      Serial.println("Object not identified yet");
      usCheck();
    }
  }*/
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

}


void usCheck()
{
  if(temp==1)
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
  flag=false;
  
  if(flag==false)
  {
    search();
  }
  }
  else if(temp==0)
  {
    ultrasonic();
    if ((distance>=8) && (distance<=20) )
  {
    Serial.println("Object identified");
    temp=1;
    flag=true;    
    myservo.write(90);
  }
  }
checktime();
}

void checktime()

{
   currentMillis = millis();
   Serial.println("Entered check time");
     if  (currentMillis - previousMillis >= 100000) //&& (temp== 1) )
    {
       previousMillis = currentMillis;
       temp=0;
       flag=false;
       myservo.write(90);
       Serial.println("Time lapse, Missed object");
  }
 
}
