void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
switch(temp)
{
  case 0:
  left();
    u8g.firstPage();  
  do 
  {
    draw(5);
  } while( u8g.nextPage() );
    
    Serial.println("up and love");
}


}
