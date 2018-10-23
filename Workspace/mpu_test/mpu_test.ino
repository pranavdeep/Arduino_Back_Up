#include <Wire.h>      //include the required libraries
#include<I2Cdev.h>
#include<MPU6050.h>

MPU6050 mpu;            //create an instance of the MPU6050 named mpu
int16_t ax, ay, az;     //declare 6 16 bit integer variables
int16_t gx, gy, gz;
//int led = 8;            //give the led pin a name

void setup() 
{
  Serial.begin(9600);
  Serial.println("Initialize MPU");
  mpu.initialize();      //initialise the sensor
}

void loop() 
{
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);  //read 6 values into 6 variables
  ax = map(ax, -17000, 17000, -1500, 1500); //     change the range of the ax value from -17000/17000 to -1500/1500
  Serial.print("ax=");
  Serial.print(ax);
  Serial.print("  ");
  ay = map(ay, -17000, 17000, -1500, 1500); 
  Serial.print("ay=");
  Serial.println(ay);
  delay(1000);
  /*if (ax > 300 && ax < 400)  //if the ax value is between 301 aand 399
  {
    analogWrite(led, 255);    //turn on the LED (an odd way to do it, but it will work)
  }
  else {
    digitalWrite(led, LOW);   //otherwise turn it off (an odd way to do it, but it will work)
  }*/
}
