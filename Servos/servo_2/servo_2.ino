#include <Servo.h>
#define SERVO_PIN 9
#define XJOY_PIN A1                  //X axis reading from joystick will go into analog pin A1
Servo myservo ;
int previousMillis=0;
 int pos=0;
void setup()
{
 Serial.begin(9600);
  myservo.attach(9);
  myservo.write(0); 
  delay(200);  
  myservo.write(180); 
  delay(175);
//  test();

//myservo.write(45);

}

void loop()
{
   myservo.write(90); 
 /* int currentMillis=millis();
  
  
if(currentMillis-previousMillis>=280)
{
   previousMillis = currentMillis;
   myservo.write(103);
   Serial.println("abc");
   delay(15);
}
else
{
   myservo.write(80);
   Serial.println("xyz");
   delay(30);
}
   

delay(275);
*/
}
