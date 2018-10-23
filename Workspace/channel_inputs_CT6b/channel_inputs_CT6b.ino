int roll =3 ; // defines the channels that are connected
int pitch=5;
int throttle =6 ;// to pins 10 and 11 of arduino respectively
int yaw=9;
//int buzzer_in=12;

int roll_value ; // Used later to 
int throttle_value ; // store values
int pitch_value ; // Used later to 
int yaw_value ; // store values
int buzzer_value;

void setup() {
  // put your setup code here, to run once:
pinMode (roll, INPUT);// initialises the channels
   pinMode (throttle, INPUT);// as inputs
   pinMode (pitch, INPUT);// initialises the channels
   pinMode (yaw, INPUT);// as inputs
//   pinMode (buzzer_in,INPUT);
   Serial.begin (9600); // Sets the baud rate to 9600 bps

}

void loop() {
  // put your main code here, to run repeatedly:
roll_value = (pulseIn (roll, HIGH)); // Checks the value of roll
Serial.print("roll_value=");
  Serial.print(roll_value); //Prints the channels value on the serial monitor
  delay(200);
  Serial.print("   ");
pitch_value = (pulseIn (pitch, HIGH)); // Checks the value of roll
Serial.print("pitch_value=");
  Serial.print(pitch_value); //Prints the channels value on the serial monitor
  delay(200);
    Serial.print("  ");

throttle_value = (pulseIn (throttle, HIGH)); // Checks the value of roll
Serial.print("throttle_value=");
  Serial.print(throttle_value); //Prints the channels value on the serial monitor
  delay(200);
    Serial.print("   ");

yaw_value = (pulseIn (yaw, HIGH)); // Checks the value of roll
Serial.print("yaw_value=");
  Serial.print(yaw_value); //Prints the channels value on the serial monitor
  delay(200);
    Serial.print("   ");
    delay(200);


//    buzzer_value=(pulseIn (buzzer_in,HIGH));
  Serial.print("buzz_value=");
  Serial.print(buzzer_value); //Prints the channels value on the serial monitor
  delay(200);
    Serial.println("   ");
    delay(1000);

}
