#include <Servo.h>
Servo myservo,myservo2;
int temp,pos=0;
void setup()
{
  myservo.attach(10); 
  myservo2.attach(9); 
  Serial.begin(9600);

}

void loop()
{
  if(temp==0)
  {
    up();
    Serial.println("up");
  }
  else if(temp==1)
  {
    down();
    Serial.println("down");
  }
  else if(temp==2)
{
 left();
}
else if(temp==3)
{
  right();
}
else
stop1();

}

void stop1()
{
  Serial.println("stop");
  myservo2.write(90); 
  myservo.write(90); 
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


void down()
{
  for (pos = 135; pos >=90; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(35);                       // waits 15ms for the servo to reach the position
  }
    temp=2;

}

void left()
{
  temp=3;
  myservo.write(105);
  Serial.println("left");
  delay(1200);
}


void right()
{
 temp=4;
  myservo.write(80);
  Serial.println("right");
  delay(1700);
}
