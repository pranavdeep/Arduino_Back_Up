int touchPin = 2;// connect output from TTP223 to this
int val = 0; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 pinMode(touchPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
val = digitalRead(touchPin);
Serial.print("value=");
Serial.println(val);
/*if(val > 500){
  Serial.println("Touched");
}
  else
  {
    Serial.println("Not Touched");    
  }*/
  //delay(1000);
  
}
