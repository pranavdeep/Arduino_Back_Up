#include <Servo.h>
Servo v_servo;
int pos_2,temp = 0; 
  void setup() {
    // put your setup code here, to run once:
    v_servo.attach(9);
    Serial.begin(9600);
    
  }

void loop() {
  // put your main code here, to run repeatedly:
if(temp==0)
  {
    up();
    Serial.println("up");
  }
  else if(temp==1)
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
  for (pos_2 = 0; pos_2 <=135; pos_2 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    v_servo.write(pos_2);              // tell servo to go to pos_2ition in variable 'pos_2'
    delay(35);                       // waits 15ms for the servo to reach the pos_2ition
  }
  temp=1;

}



void straight()
{
  
  int angle=v_servo.read();
  if(angle<90)
  {
    for (pos_2 = angle; pos_2 <=90; pos_2 += 1)
    { // goes from 0 degrees to 180 degrees.
    // in steps of 1 degree
    v_servo.write(pos_2);              // tell servo to go to pos_2ition in variable 'pos_2'
    delay(35);                       // waits 15ms for the servo to reach the pos_2ition
  }
  int angle=v_servo    .read();
  }
  else if(angle>90)
  {
    for (pos_2 = angle; pos_2 >=90; pos_2 -= 1)
    { // goes from 0 degrees to 180 degrees.
    // in steps of 1 degree
    v_servo.write(pos_2);              // tell servo to go to pos_2ition in variable 'pos_2'
    delay(35);                       // waits 15ms for the servo to reach the pos_2ition
     }
     int angle=v_servo.read();
  }
  else if(angle==90)
  {
    v_servo.detach();
    delay(35);
  }
  temp=2;
  }


void down()
{
  for (pos_2 = 90; pos_2 >=80; pos_2 -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    v_servo.write(pos_2);              // tell servo to go to pos_2ition in variable 'pos_2'
    delay(35);                       // waits 15ms for the servo to reach the pos_2ition
  }
    temp=3;

}

