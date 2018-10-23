int xPin=A0;//Connect x pin of adxl335 to pin A0
int yPin=A1;//Connect y pin of adxl335 to pin A1
int x[20],y[20],i=0;
int j=0;
long x_total=0,y_total=0;
double x_avg=0,y_avg=0;
void setup() 
{
  Serial.begin(9600);//Initialise the serial connection
  pinMode(xPin,INPUT);
  pinMode(yPin,INPUT);
}

void loop() 
{
  if(i<20)
  {
  int xval=analogRead(xPin);
  x[i]=xval;
  int yval=analogRead(yPin);
  y[i]=yval;
  i++;
  Serial.print("i=");
  Serial.println(i);
    }
  
  if(i==20)
  {
    for(j=0;j<20;j++)
    {
  /*Serial.print("xval=");
  Serial.println(x[j]);//Use xval to determine threshold for different directions
  
  Serial.print("yval=");
  Serial.println(y[j]); //Use yval to determine threshold for different directions*/
  
       x_total=x_total+x[j];
       y_total=y_total+y[j];
       
    }
    x_avg=x_total/i;
    y_avg=y_total/i;
  }
    if(j==20)
    {
      Serial.print("x_total=");
      Serial.println(x_total);
      Serial.print("y_total=");
      Serial.println(y_total);
        
    Serial.print("x_avg=");
  Serial.println(x_avg);
  
  Serial.print("y_avg=");
  Serial.println(y_avg);
//  break;
    }
    
  delay(1000); //used to display values after 2s delay
  
  Serial.print("\n");//print after 2s in a new line
}
