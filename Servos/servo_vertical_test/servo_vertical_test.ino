#include <Servo.h>
Servo myservo2;
int pos,temp = 0; 
void setup() {
  // put your setup code here, to run once:
  myservo2.attach(9); 
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
if(temp==0)
  {
    up();
    Serial.println("up");
  }
  else if(temp==2)
  {
    down();Serial.println("down");
  }
  else 
  {
    straight();
    Serial.println("fdfafds");
  }
  
  //Serial.println("elsewhere");
}

void up()
{
  for (pos = 0; pos <=135; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(35);                       // waits 15ms for the servo to reach the position
  }
  temp=1;

}



void straight()
{
  temp=2;
  int angle=myservo2.read();
  if(angle<90)
  {
    for (pos = angle; pos <=90; pos += 1)
    { // goes from 0 degrees to 180 degrees.
    // in steps of 1 degree
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(35);                       // waits 15ms for the servo to reach the position
  }
  int angle=myservo2    .read();
  }
  else if(angle>90)
  {
    for (pos = angle; pos >=90; pos -= 1)
    { // goes from 0 degrees to 180 degrees.
    // in steps of 1 degree
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(35);                       // waits 15ms for the servo to reach the position
     }
     int angle=myservo2.read();
  }
  else if(angle==90)
  {
    myservo2.detach();
    delay(35);
  }
  
  }


void down()
{
  for (pos = 90; pos >=20; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(35);                       // waits 15ms for the servo to reach the position
  }
    temp=2;

}

