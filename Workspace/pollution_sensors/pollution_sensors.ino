#include "MQ135.h"
#include "MQ2.h"
/*int dustPin=A0; 
int dustVal=0;
 int ledPower=2; 
 int delayTime=280; 
 int delayTime2=40;
 float offTime=9600;*/ 
const int sensorPin = A0;
int air_quality;
 void setup()
 { 
  Serial.begin(115200);
 /* pinMode(2, OUTPUT);
  digitalWrite(2, 0);
  pinMode(8, OUTPUT);
  pinMode(ledPower,OUTPUT);
  pinMode(4, OUTPUT);*/
    pinMode(sensorPin, INPUT);        //Gas sensor will be an input to the arduino
//pinMode(ledPin, OUTPUT);
//  digitalWrite(ledPin, LOW);
 
  }
 void loop()
 { 
  MQ2 gasSensor = MQ2(A0);
 // air_quality = gasSensor.getPPM();
  Serial.print("gasSensor");
  Serial.println(MQ2gasSensor);
  if (air_quality <= 1000)
  {
    Serial.println("Poor Air");
    delay(100);
  }
  else if (air_quality <= 2000 && air_quality >= 1000)
  {
    Serial.println("Poor Air");
    delay(100);
  }
  else if (air_quality >= 2000 )
  {
    Serial.println("Danger! Move to Fresh Air");
    delay(100);
  }
  // ledPower is any digital pin on the arduino connected to Pin 3 on the sensor
  /*digitalWrite(ledPower,LOW); // power on the LED 
  delayMicroseconds(delayTime);
  dustVal=analogRead(dustPin); // read the dust value via pin 5 on the sensor 
  delayMicroseconds(delayTime2);
  digitalWrite(ledPower,HIGH); // turn the LED off 
  delayMicroseconds(offTime);
 delay(300); 
 Serial.print("Dust value=");
 Serial.println(dustVal); */
 }
 
