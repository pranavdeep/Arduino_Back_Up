#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

int currentMillis,previousMillis,temp=0;

void setup() {
  // put your setup code here, to run once:
 myservo1.attach(9);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
currentMillis=millis();
test();
}


void test()
{
  if(currentMillis-previousMillis>=5000)
  {
    currentMillis=previousMillis;
    temp=0;
  }
  else
  {
  temp=1;
  }
  if(temp==0)
  {
  for (pos = 0; pos <= 180; pos += 10) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(2);                       // waits 15ms for the servo to reach the position
    if(pos==180)
    return;
  }
    //delay(1);
  for (pos = 180; pos >= 0; pos -= 10) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15ms for the servo to reach the position
    Serial.println(pos);
    if(pos==0)
    return;
  }
  }
  else if(temp==1)
  {
    myservo1.write(90);
    
  
  }
}

