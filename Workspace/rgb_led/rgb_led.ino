
 
int  ir=A1;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ir,INPUT);

}

void loop() {
int val=analogRead(ir);
Serial.println(val);
}
