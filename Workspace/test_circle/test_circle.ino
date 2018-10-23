
int RADIUS=7;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
for (int i = 0; i < RADIUS*2; i++)
{
    for (int j = 0; j < RADIUS*2; j++)
    {
         if (i * i + j * j == RADIUS * RADIUS)
         {
               Serial.println("0");
          } else {
               Serial.println(" ");
          }

          if (j == RADIUS*2)
          {
                Serial.print("\n");
          }
    }
}

}






void loop() {
  // put your main code here, to run repeatedly:


}
