int a=A0;
int b=A2;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(a,INPUT);
pinMode(b,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int x=digitalRead(A0);
int y=digitalRead(A1);
Serial.print("x=");
Serial.println(x);
Serial.print("y=");
Serial.println(y);


}
