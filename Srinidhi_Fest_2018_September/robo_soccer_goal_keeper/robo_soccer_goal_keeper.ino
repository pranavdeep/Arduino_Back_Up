int state = 0;
int lm1 = 3;// defines pin 3 as connected to the motor
int lm2 = 5;// defines pin 6 as connected to the motor
int rm1= 6;// defines pin 5 as connected to the motor
int rm2 = 9;// defines pin 9 as connected to the motor

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600); // Default communication rate of the Bluetooth module

  pinMode (lm1, OUTPUT);// initialises the motor pins
   pinMode (rm1, OUTPUT);
   pinMode (lm2, OUTPUT);
   pinMode (rm2, OUTPUT);// as outputs
}
void loop() {
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    Serial.println("Connection established");
    state = Serial.read(); // Reads the data from the serial port
      state=state-49;

 Serial.println(state);
 if (state == 0) {
  
  Serial.println("up"); // Send back, to the phone, the String "LED: ON"
  forward();
  
 }
 else if (state == 1) 
 {
  Serial.println("down");
  reverse();
   
 } 
 else if (state == 3) 
 {
  Serial.println("right");
  right();
 } 
 else if (state == 2) 
 {
  Serial.println("left");
  left();
   
 } 
 else if(state==-1)
 {
  stop1();
 }
  }
}


void stop1()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
//  digitalWrite(buzzer_out,LOW);
 }//stop1 function ends


void forward()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
//  digitalWrite(buzzer_out,LOW);
 }//stop1 function ends

void reverse()
{
  digitalWrite(lm2,HIGH);
  digitalWrite(lm1,LOW);
  digitalWrite(rm2,HIGH);
  digitalWrite(rm1,LOW);
//  digitalWrite(buzzer_out,LOW);
 }//stop1 function ends

 
void right()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
//  digitalWrite(buzzer_out,LOW);
 }//stop1 function ends
 
void left()
{
  digitalWrite(lm2,HIGH);
  digitalWrite(lm1,LOW);
  digitalWrite(rm2,LOW);
  digitalWrite(rm1,HIGH);
//  digitalWrite(buzzer_out,LOW);
 }//stop1 function ends
