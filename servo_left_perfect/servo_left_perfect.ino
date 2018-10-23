#include <Servo.h>
Servo myservo;  // create servo object to control a servo
               // a maximum of eight servo objects can be created
int pos,temp = 0;    // variable to store the servo position
void setup() {
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
myservo.write(90);
}
void loop() 
{
  if(temp==0)
  left();
  if(temp==1)
  right();
}
  /*for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees
  {
     myservo.write(pos);              // tell servo to go to position in variable 'pos'
     delay(15);                       // waits 15ms for the servo to reach the position
  }*/
void left()
{
if(temp==0)
{
  for(pos = 0 ;pos <= 1080; pos += 1)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    Serial.println(pos);
     myservo.write(105);   
     // tell servo to go to position in variable 'pos'
     //delay(7);                       // waits 15ms for the servo to reach the position
  }
     if(pos>=480)
  {
    temp=1;
    myservo.write(90); 
    return;
  }
  }
}

void right()
{
if(temp==1)
{
  for(pos =1080; pos >= 0; pos -= 1)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    Serial.println(pos);
     myservo.write(80);              // tell servo to go to position in variable 'pos'
     //delay(7);                       // waits 15ms for the servo to reach the position
  }
     if(pos<=0)
  {
    temp=0;
    myservo.write(90); 
    return;
  }
  }
}
