int lm1 = 2;// defines pin 3 as connected to the motor
int lm2 = 3;// defines pin 6 as connected to the motor
int rm1= 4;// defines pin 5 as connected to the motor
int rm2 = 5;// defines pin 9 as connected to the motor

int roll = 8; // defines the channels that are connected
int pitch=9;
int throttle = 10;// to pins 10 and 11 of arduino respectively
int yaw=11;

int roll_value ; // Used later to 
int throttle_value ; // store values
int pitch_value ; // Used later to 
int yaw_value ; // store values

void  setup (){
   pinMode (lm1, OUTPUT);// initialises the motor pins
   pinMode (rm1, OUTPUT);
   pinMode (lm2, OUTPUT);
   pinMode (rm2, OUTPUT);// as outputs


   
   pinMode (roll, INPUT);// initialises the channels
   pinMode (throttle, INPUT);// as inputs
   pinMode (pitch, INPUT);// initialises the channels
   pinMode (yaw, INPUT);// as inputs

   
   Serial.begin (9600); // Sets the baud rate to 9600 bps
}

void  loop ()
{
  roll_value = (pulseIn (roll, HIGH)); // Checks the value of roll
  /*Serial.print("roll_value=");
  Serial.println (roll_value); //Prints the channels value on the serial monitor
  delay(250);*/
    throttle_value = (pulseIn (throttle, HIGH)); // Checks the value of throttle
  /*Serial.print("throttle_value=");
  Serial.println (throttle_value); //Prints the channels value on the serial monitor
  delay(250);*/
yaw_value = (pulseIn (yaw, HIGH)); // Checks the value of yaw
pitch_value = (pulseIn (pitch, HIGH)); // Checks the value of pitch



if (throttle_value<=1200)
{
  analogWrite(lm1,0);
    analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,0);
}
if((throttle_value>1200)&&(throttle_value<=1400))
{
  analogWrite(lm1,120);
    analogWrite(lm2,0);
  analogWrite(rm1,120);
  analogWrite(rm2,0);
}
if((throttle_value>1400)&&(throttle_value<=1600))
{
  analogWrite(lm1,130);
    analogWrite(lm2,0);
  analogWrite(rm1,130);
  analogWrite(rm2,0);
}
if(throttle_value> 1600)
{
    analogWrite(lm1,255);
    analogWrite(lm2,0);
  analogWrite(rm1,255);
  analogWrite(rm2,0);
}
if(roll_value>=1600)
{//RIGHT POINT TURN
  analogWrite(lm1,255);
    analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,255);
}
if(roll_value<=1400)
{//LEFT POINT TURN
  analogWrite(lm1,0);
    analogWrite(lm2,255);
  analogWrite(rm1,255);
  analogWrite(rm2,0);
}
if(pitch_value>1550)
{//FORWORD WITH HIGH SPEED
  analogWrite(lm1,255);
    analogWrite(lm2,0);
  analogWrite(rm1,255);
  analogWrite(rm2,0);
}
if(pitch_value<1400)
{
  if((pitch_value>=1180)&&(pitch_value<1400))
  {
    analogWrite(lm1,0);
    analogWrite(lm2,180);
  analogWrite(rm1,0);
  analogWrite(rm2,180);
  }
else
{//REVERSE WITH LOW SPEED
analogWrite(lm1,0);
    analogWrite(lm2,255);
  analogWrite(rm1,0);
  analogWrite(rm2,255);
}//else ends
}//base if ends
if(yaw_value<1400)
{
   if( (yaw_value>=1280) && (yaw_value<=1400) )
{
analogWrite(rm1,180);
    analogWrite(lm2,0);
  analogWrite(lm1,0);
  analogWrite(rm2,0);
}//if ends
else
{
analogWrite(lm1,255);
    analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,0);
}//else ends
}//base yaw if ends
if(yaw_value>1550)
{
   if( (yaw_value>=1550) && (yaw_value<=1700) )
{
analogWrite(lm1,180);
    analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,0);
}
else
{
analogWrite(lm1,255);
    analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,0);
}
}//base yaw ends



}//void loop ends
 
  
