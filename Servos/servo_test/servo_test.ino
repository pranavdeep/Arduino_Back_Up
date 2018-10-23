int servoPin = A2;     // Control pin for servo motor
int minPulse = 500;   // Minimum servo position
int maxPulse = 2500;  // Maximum servo position
int pulse = 0;        // Amount to pulse the servo

int lastPulse = 0;    // the time in milliseconds of the last pulse
int refreshTime = 20; // the time needed in between pulses

int analogValue = 0;  // the value returned from the analog sensor
int analogPin = 0;    // the analog pin that the sensor's on

void setup() {
  pinMode(servoPin, OUTPUT);  // Set servo pin as an output pin
  pulse = minPulse;           // Set the motor position value to the minimum
  Serial.begin(9600);
}

void loop() {
  analogValue = analogRead(analogPin);      // read the analog input
  pulse = (analogValue / 10) * 19 + 500;    // convert the analog value
                                            // to a range between minPulse
                                            // and maxPulse. 

  // pulse the servo again if rhe refresh time (20 ms) have passed:
  if (millis() - lastPulse >= refreshTime) {
    analogWrite(servoPin, 255);   // Turn the motor on
    delayMicroseconds(pulse);       // Length of the pulse sets the motor position
    analogWrite(servoPin, 0);    // Turn the motor off
    lastPulse = millis();           // save the time of the last pulse
  }
}
