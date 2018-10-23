#include "MQ135.h"
#include "Wire.h"
int dustPin=A0; 
int dustVal=0;
 int ledPower=2; 
 int delayTime=280; 
 int delayTime2=40;
 float offTime=9680; 
const int sensorPin =A1;
int air_quality,gasSensor;
//double c;
//const char* host = "api.devicehub.net";//api.devicehub.net
 void setup()
 { 
 
  Serial.begin(115200);
  pinMode(2, OUTPUT);//ledpower
  digitalWrite(2, 0);
  //pinMode(8, OUTPUT);
  pinMode(ledPower,OUTPUT);
  //pinMode(4, OUTPUT);
    pinMode(sensorPin, INPUT);  //Gas sensor will be an input to the arduino
     pinMode(A0, OUTPUT);//dust sensor data output0
   Wire.begin(8);                // join i2c bus with address #8
   //Wire.onReceive(receiveEvent); // register receive event
   Wire.onRequest(requestEvent); // register request event
     }
 
  /*MQ135 gasSensor = MQ135(A1);
   air_quality = gasSensor.getPPM();
  digitalWrite(ledPower,LOW); // power on the LED 
  delayMicroseconds(delayTime);
  dustVal=analogRead(dustPin); // read the dust value via pin 5 on the sensor 
  delayMicroseconds(delayTime2);
  digitalWrite(ledPower,HIGH); // turn the LED off 
  delayMicroseconds(offTime);
 //delay(300); 
 Serial.print("/*BEFORE LOOP STARTEDDust value=");
 Serial.println(dustVal); */
 
  void loop()
 { 
 MQ135 gasSensor = MQ135(A1);
  air_quality = gasSensor.getPPM();
  // ledPower is any digital pin on the arduino connected to Pin 3 on the sensor
  digitalWrite(ledPower,LOW); // power on the LED 
  delayMicroseconds(delayTime);
  dustVal=analogRead(dustPin); // read the dust value via pin 5 on the sensor 
  delayMicroseconds(delayTime2);
  digitalWrite(ledPower,HIGH); // turn the LED off 
  delayMicroseconds(offTime);
 delay(300); 
   if (air_quality <= 1000)
  {
    Serial.println("Poor Air");
      }
  else if (air_quality <= 2000 && air_quality >= 1000)
  {
    Serial.println("Poor Air");
  }
  else if (air_quality >= 2000 )
  {
    Serial.println("Danger! Move to Fresh Air");
  }
   gasSensor = MQ135(A1);
   air_quality = gasSensor.getPPM();
  // ledPower is any digital pin on the arduino connected to Pin 3 on the sensor
  digitalWrite(ledPower,LOW); // power on the LED 
  delayMicroseconds(delayTime);
  dustVal=analogRead(dustPin); // read the dust value via pin 5 on the sensor 
  delayMicroseconds(delayTime2);
  digitalWrite(ledPower,HIGH); // turn the LED off 
  delayMicroseconds(offTime);
 delay(300); 
 Serial.println(dustVal); 
 }
 void requestEvent() 
 // function that executes whenever data is requested from master
 {
   Wire.write("Air pollution monitoring");//send string on request
      while (0 < Wire.available())
   {
     air_quality= Wire.write(10); // receive byte as a character
        Serial.print("Air quality=");         // print the characte
       Serial.println(air_quality);         // print the character
      gasSensor = Wire.write(10); // receive byte as a character
      Serial.print("Gas sensors=");         // print the characte
       Serial.println(gasSensor);         // print the character
   }
 }
  /*void receiveEvent(int howMany) 
  {// function that executes whenever data is received from master
   while (0 < Wire.available())
   {
     air_quality= Wire.read(); // receive byte as a character
      char c=char(air_quality);
       Serial.print("Value of c=");         // print the characte
       Serial.println(c);         // print the character
      gasSensor = Wire.read(); // receive byte as a character
      char d=char(dustVal);
     Serial.print("Value of d=");         // print the characte
       Serial.println(d);         // print the character
     }*/
