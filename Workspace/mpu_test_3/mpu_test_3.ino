#include <helper_3dmath.h>
#include <MPU6050.h>
#include <MPU6050_6Axis_MotionApps20.h>
#include <MPU6050_9Axis_MotionApps41.h>

#include <Wire.h>

#define period 10000

MPU6050 mpu;

int count=0;
char okFlag=0;

byte degree[8] = {
  0b00000,
  0b00110,
  0b01111,
  0b00110,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  Serial.println("Initialize MPU6050");
  /*while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }*/
  count=0;
  mpu.calibrateGyro();
  mpu.setThreshold(3);
}
void accelShow()
{

  
  Vector rawAccel = mpu.readRawAccel();
  Vector normAccel = mpu.readNormalizeAccel();
  
  Serial.print(" Xnorm = ");
  Serial.print(normAccel.XAxis);
  Serial.print(" Ynorm = ");
  Serial.print(normAccel.YAxis);
  Serial.print(" Znorm = ");
  Serial.println(normAccel.ZAxis);
  delay(200);
}
void loop() {
  // put your main code here, to run repeatedly:
   long st=millis();
 while(millis()<st+period)
    {
      
      accelShow();
    }
}
