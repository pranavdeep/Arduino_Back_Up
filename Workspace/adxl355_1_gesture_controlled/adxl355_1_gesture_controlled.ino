/*Created by: Pranav Deep Indrakanti
 * #Gesture Controlled Bot
 Connect x pin on ADXL335 to A5, y pin to A4, z pin to A3 */
 
const int ap1 = A5; 
const int ap2 = A4;
const int ap3 = A3;

int x = 0;  
int y = 0;   
int z = 0;       
    

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
 pinMode(ap1, INPUT);
  pinMode(ap2, INPUT);
  pinMode(ap3, INPUT);
  
}

void loop() {
  //analogReference(EXTERNAL);    //connect 3.3v to AREF
  // read the analog in value:
  x = analogRead(ap1);   
          
   y = analogRead(ap2);  
                  
  z = analogRead(ap3);   
  
 
  
  // print the results to the serial monitor:
  Serial.print("Xsensor1 = " );                       
  //Serial.print(x);   
  Serial.print(x);   
  Serial.print("\t  ");      
     
 
  Serial.print("Ysensor2 = " );                       
 Serial.print(y);  
     
  Serial.print("\t  ");      
  
  Serial.print("Zsensor3 = " );                       
  Serial.print(z);      
  //Serial.print("\t ");      
     

 Serial.println("");
  //delay(1000);       
  if( (x>=75 && x<=90) && (y>=80 && y<=90) && (z>=95 && z<=105) )
  {
    stop1();
  }
  else if( (x>=90 && x<=102) && (y>=80 && y<=90) && (z>=75 && z<=90) )
  {
    forward();
  }
   else if( (x>=60 && x<=75) && (y>=80 && y<=90) && (z>=85 && z<=100) )
  {
    reverse();
  }             
  else if( (x>=75 && x<=90) && (y>=60 && y<=75) && (z>=85 && z<=100) )
  {
    right_turn();
  }     
  else if( (x>=75 && x<=90) && (y>=90 && y<=100) && (z>=85 && z<=100) )
  {
    left_turn();
  } 
  else
  {
    stop1();  
  }
delay(500);
}





void stop1()
{
  Serial.println("Rest");
  
}

void forward()
{
  Serial.println("Forward");
  
}

void reverse()
{
  Serial.println("Reverse");
  
}

void left_turn()
{
  Serial.println("left_turn");
}
void right_turn()
{
  Serial.println("right_turn");
}

