int pin1=A0;
int pin2=A1;


void setup() {

 Serial.begin(9600);
 pinMode(pin1,INPUT_PULLUP);
 pinMode(pin2,INPUT_PULLUP);

if(analogRead(pin1<150))
{
  int pinLeft=pin1;
}
if(analogRead(pin1>800))
{
  int pinRight=pin1;
}


 attachInterrupt(digitalPinToInterrupt(pinLeft), left, FALLING);
  attachInterrupt(digitalPinToInterrupt(pinRight), right, FALLING);

  
}

void loop() {
  // put your main code here, to run repeatedly:
int val1=analogRead(pin1);
int val2=analogRead(pin2);
Serial.print("val=");
Serial.println(val1);
/*delay(250);
Serial.print("xyz=");
Serial.println(val2);*/
}
