#define ir A0
void setup() {
  // put your setup code here, to run once:
pinMode(ir,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int a=analogRead(ir);
Serial.println(a);
}
