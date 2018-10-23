
int a=5,b=9,c;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
a=-5;
Serial.print("a=");
Serial.println(a);
delay(250);
c=abs(a);
b=abs(b);
Serial.print("abs of b=");
Serial.println(b);
delay(250);
Serial.print("abs of a=");
Serial.println(c);
delay(2000);


}
