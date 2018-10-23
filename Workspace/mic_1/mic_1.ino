int m[6],led[6],reading[6];
m[0]=A0;
  m[1]=A1;
  m[2]=A2;
  m[3]=A3;
  m[4]=A6;
  m[5]=A7;
  for(int i=5,j=0;i<11;i++,j++)
  {
    led[j]=i;
  }

void setup()
{
  for(int j=0;i<6;j++)
  {
    pinMode(led[j],OUTPUT);
  }
  Serial.begin(9600);
}

void loop()
{
  
  while(i<6)
  {
    reading[i]=analogRead(m[i]);
    if(reading[i]>500)
    {
      digitalWrite(led[i],HIGH);
    }
    else
    {
      digitalWrite(led[i],LOW);
    }
  } 

}
