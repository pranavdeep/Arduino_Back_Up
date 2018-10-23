
int emg=3;
void setup() {
  // put your setup code here, to run once:
  pinMode(emg,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int a=analogRead(emg);
Serial.print("a=");
Serial.println(a);
//delay(500);

}
