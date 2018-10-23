int roll = 8; // defines the channels that are connected
int pitch=9;
int throttle = 10;// to pins 10 and 11 of arduino respectively
int yaw=11;


int roll_value ; // Used later to 
int throttle_value ; // store values
int pitch_value ; // Used later to 
int yaw_value ; // store values


void setup() {
  // put your setup code here, to run once:
pinMode (roll, INPUT);// initialises the channels
   pinMode (throttle, INPUT);// as inputs
   pinMode (pitch, INPUT);// initialises the channels
   pinMode (yaw, INPUT);// as inputs
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
    Serial.println("   ");
    delay(1000);

}
