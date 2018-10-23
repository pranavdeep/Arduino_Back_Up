int i;
int arr[15];
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
if(i<10)
{
  arr[i]=i+1;
  i++;
  printFunction();
}
}
void printFunction()
{
  for(i=1;i<=10;i++)
  {
  Serial.print("  ");
  Serial.println(arr[i]);
  i++;
}
}
