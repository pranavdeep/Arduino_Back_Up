
int state = 0;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}
void loop() {
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    Serial.println("Connection established");
    state = Serial.read(); // Reads the data from the serial port
      state=state-49;

 Serial.println(state);
 if (state == 0) {
  digitalWrite(LED_BUILTIN, LOW); // Turn LED OFF
  Serial.println("LED: OFF"); // Send back, to the phone, the String "LED: ON"
  
 }
 else if (state == "1") {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("LED: ON");
  
 } 
  }
}
