int lm1 = 3;// defines pin 3 as connected to the motor
int lm2 = 5;// defines pin 6 as connected to the motor
int rm1= 6;// defines pin 5 as connected to the motor
int rm2 = 9;// defines pin 9 as connected to the motor

int roll = A0; // defines the channels that are connected
int pitch=A1;
int throttle = A2;
int yaw=A3;


int roll_value ; // Used later to 
int throttle_value ; // store values
int pitch_value ; // Used later to 
int yaw_value ; // store values
//int buzzer_value;
void  setup (){
   pinMode (lm1, OUTPUT);// initialises the motor pins
   pinMode (rm1, OUTPUT);
   pinMode (lm2, OUTPUT);
   pinMode (rm2, OUTPUT);// as outputs
   //pinMode (buzzer_out,OUTPUT);

   
   pinMode (roll, INPUT);// initialises the channels
   pinMode (throttle, INPUT);// as inputs
   pinMode (pitch, INPUT);// initialises the channels
   pinMode (yaw, INPUT);// as inputs
   //pinMode (buzzer_in,INPUT);
   
   Serial.begin (9600); // Sets the baud rate to 9600 bps
}
void  loop ()
{
  roll_value = (pulseIn (roll, HIGH)); // Checks the value of roll
  throttle_value = (pulseIn (throttle, HIGH)); // Checks the value of throttle
  yaw_value = (pulseIn (yaw, HIGH)); // Checks the value of yaw
  pitch_value = (pulseIn (pitch, HIGH)); // Checks the value of pitch
//  buzzer_value=(pulseIn (buzzer_in,HIGH));
  
//stop1();
//delay(1);

/*if(buzzer_value >=1200)
{
  digitalWrite(buzzer_out,HIGH);
  
}//buzzer if ends*/

Serial.print("roll_value=");
  Serial.print(roll_value); //Prints the channels value on the serial monitor
  Serial.print("   ");
  Serial.print("pitch_value=");
  Serial.print(pitch_value); //Prints the channels value on the serial monitor
      Serial.print("  ");
Serial.print("yaw_value=");
  Serial.print(yaw_value);
    Serial.println("   ");



if (throttle_value<=1200)
{
  stop1();
}
if((throttle_value>1200)&&(throttle_value<=1400))
{//if no=1
  Serial.println("abcdefg");
  analogWrite(lm1,140);
    analogWrite(lm2,0);
  analogWrite(rm1,140);
  analogWrite(rm2,0);
}

if((throttle_value>1400)&&(throttle_value<=1550))
{//if no=2
  analogWrite(lm1,165);
    analogWrite(lm2,0);
  analogWrite(rm1,165);
  analogWrite(rm2,0);
}

if((throttle_value>1550)&&(throttle_value<=1650))
{//if no=3
  analogWrite(lm1,180);
    analogWrite(lm2,0);
  analogWrite(rm1,180);
  analogWrite(rm2,0);
}

if(throttle_value> 1650)
{//if no=3
    analogWrite(lm1,255);
    analogWrite(lm2,0);
  analogWrite(rm1,255);
  analogWrite(rm2,0);
}
//throttle ends





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

//roll if ends





if( (pitch_value<1400) && (roll_value<1400) )
{
   analogWrite(lm1,0);
    analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,255);
}
if( (pitch_value<1400) && (roll_value>1550) )
{
   analogWrite(lm1,0);
    analogWrite(lm2,255);
  analogWrite(rm1,0);
  analogWrite(rm2,0);
}
//reverse left and reverse right ends



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
    if(roll_value<1400)
    {
      analogWrite(lm1,0);
    analogWrite(lm2,255);
  analogWrite(rm1,0);
  analogWrite(rm2,255);
    }
    else if(roll_value>1600)
    {
      analogWrite(lm1,0);
    analogWrite(lm2,255);
  analogWrite(rm1,0);
  analogWrite(rm2,255);
    }
    else
    {
    analogWrite(lm1,0);
    analogWrite(lm2,180);
  analogWrite(rm1,0);
  analogWrite(rm2,180);
  }//else for roll ends
  }//if of pitch ends
else
{//REVERSE WITH LOW SPEED
    analogWrite(lm1,0);
    analogWrite(lm2,255);
  analogWrite(rm1,0);
  analogWrite(rm2,255);
}//else ends
}//base if ends


//pitch ends



if(yaw_value>1550)
{
   if( (yaw_value>=1550) && (yaw_value<=1650) )
{
  
   analogWrite(lm1,165);
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


if(yaw_value<1400)
{
   if( (yaw_value>=1280) && (yaw_value<=1400) )
{
analogWrite(rm1,165);
    analogWrite(lm2,0);
  analogWrite(lm1,0);
  analogWrite(rm2,0);
}//if ends
else
{
analogWrite(rm1,255);
    analogWrite(lm2,0);
  analogWrite(lm1,0);
  analogWrite(rm2,0);
}//else ends
}//base yaw if ends

}//void loop ends


void stop1()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
//  digitalWrite(buzzer_out,LOW);
 }//stop1 function ends


//}
