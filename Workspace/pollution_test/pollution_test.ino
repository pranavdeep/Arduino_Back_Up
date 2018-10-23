#include "MQ135.h"
const int sensorPin = 3;
int air_quality;
void setup()
{
  Serial.begin(9600);
  //delay(10);
  pinMode(2, OUTPUT);
  digitalWrite(2, 0);
  pinMode(8, OUTPUT);
  //esp8266.begin(115200); // your esp's baud rate might be different
  pinMode(sensorPin, INPUT);        //Gas sensor will be an input to the arduino

}
void loop()
{
  delay(1000);
  MQ135 gasSensor = MQ135(A0);
  float air_quality = gasSensor.getPPM();
  Serial.println(air_quality);
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
}


