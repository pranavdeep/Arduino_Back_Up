#include <Servo.h>
Servo h_l_servo,h_r_servo,v_l_servo,v_r_servo;
int pos=45,temp = 0; 


void setup()
{
  //3-left hor,5-right hor
//6-left ver,9 right ver

  h_l_servo.attach(3);
  h_r_servo.attach(5);
  v_l_servo.attach(6);
  v_r_servo.attach(9);
  Serial.begin(9600);
  //h_l_servo.write(pos); 
  v_l_servo.write(0); 
  //`h_r_servo.write(pos); 
  v_r_servo.write(130); 
  
}

void loop()
{
  //if(temp==0)
 // move_2();
 move_1();
}


void move_1()
{
  for (pos = 0; pos <= 90; pos += 1)
  { 
    h_l_servo.write(pos);  
    h_r_servo.write(pos);     
    delay(10);                       
  }
  for (pos = 90; pos >= 0; pos -= 1) 
  { 
     h_l_servo.write(pos);  
     h_r_servo.write(pos);delay(10); 
  }
}

void move_2()
{
  
  for (pos =130; pos <= 180; pos += 1)
  { 
    //v_l_servo.write(pos);  
    v_r_servo.write(pos);     
    delay(10);                       
  }
 
 temp++; 
 /*for (pos = 200; pos >= 130; pos -= 1) 
  { 
     v_r_servo.write(pos);     
     delay(10); 
  } */
}

