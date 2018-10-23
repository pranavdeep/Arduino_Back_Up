#include <Servo.h>
Servo esc_signal;
int state = 0;
int i=55;;
void setup()
{
  esc_signal.attach(11);  //Specify here the pin number on which the signal pin of ESC is connected.
  esc_signal.write(30);   //ESC arm command. ESCs won't start unless input speed is less during initialization.
  delay(3000);            //ESC initialization delay.
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available() > 0)
  {
    state = Serial.read();
    Serial.println("Connection established");
    if (state == 0) 
    {
      esc_signal.write(i);
      Serial.println("Motor spinning");   
      delay(15);
    }  
    else
    {
      esc_signal.write(0); 
      Serial.println("Motor Not spinning");   
    }
}
}
