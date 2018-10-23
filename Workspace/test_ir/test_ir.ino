#define ir 3
#define led 13
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ir,INPUT);
pinMode(led,OUTPUT);
pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int val=digitalRead(ir);
Serial.println(val);
if (val==LOW)
{
  digitalWrite(led,HIGH);
  digitalWrite(LED_BUILTIN,HIGH);

}
if (val==HIGH)
{
  digitalWrite(led,LOW);
  digitalWrite(LED_BUILTIN,LOW);

}
}
