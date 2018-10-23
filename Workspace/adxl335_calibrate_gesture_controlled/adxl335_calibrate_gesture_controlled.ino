const int xInput = A0;
const int yInput = A1;

int xRawMin = 512;
int xRawMax = 512;
 
int yRawMin = 512;
int yRawMax = 512;

int temp;

const int sampleSize = 10;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

int xRaw = ReadAxis(xInput);
int yRaw = ReadAxis(yInput);

/*Serial.println("Enter 1 to begin autocalibration");
temp=Serial.read();*/


  AutoCalibrate(xRaw, yRaw);



}



int ReadAxis(int axisPin)
{
  long reading = 0;
  analogRead(axisPin);
  delay(1);
  for (int i = 0; i < sampleSize; i++)
  {
    reading += analogRead(axisPin);
  }
  return reading/sampleSize;
}


void AutoCalibrate(int xRaw, int yRaw   )
{
  Serial.println("Calibrate");
  if (xRaw < xRawMin)
  {
    xRawMin = xRaw;
  }
  if (xRaw > xRawMax)
  {
    xRawMax = xRaw;
  }
  
  if (yRaw < yRawMin)
  {
    yRawMin = yRaw;
  }
  if (yRaw > yRawMax)
  {
    yRawMax = yRaw;
  }
 
  
}
