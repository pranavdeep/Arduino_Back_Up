#include <Wire.h>

#include <MPU6050.h>
MPU6050 sensor ;

int16_t ax, ay, az ;
int16_t gx, gy, gz;


void setup() {
  // put your setup code here, to run once:
Wire.begin ( );

Serial.begin  (9600);
Serial.println (sensor.testConnection ( ) ? "Successfully Connected" : "Connection failed"); 
delay (1000); 

Serial.println ( "Taking Values from the sensor" );
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor.getMotion6 (&ax, &ay, &az, &gx, &gy, &gz);
ax = map(ax, -17000, 17000, -1500, 1500); //     change the range of the ax value from -17000/17000 to -1500/1500
  Serial.print("ax=");
  Serial.print(ax);
  Serial.print("  ");
  ay = map(ay, -17000, 17000, -1500, 1500); 
  Serial.print("ay=");
  Serial.print(ay);
  Serial.print("  ");
  az = map(az, -17000, 17000, -1500, 1500); 
  Serial.print("az=");
  Serial.println(az);
  delay(1000);
}
