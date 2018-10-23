int lm1 = 10;
int lm2 = 9;
int rm1 = 6;
int rm2 = 5;



int ss1 = 13;
int ss2 = 12;
int ss3 = 11;
int ss4 = 8;
int ss5 = 7;
int ss6 = 4;
int ss7 = 3;
int ss8 = 2;
int a, b, c, d, e, f, g, h;

void setup()
{


  pinMode(lm1, OUTPUT);

  pinMode(lm2, OUTPUT);

  pinMode(rm1, OUTPUT);

  pinMode(rm2, OUTPUT);

  pinMode(ss1, INPUT);

  pinMode(ss2, INPUT);

  pinMode(ss3, INPUT);

  pinMode(ss4, INPUT);

  pinMode(ss5, INPUT);

  pinMode(ss6, INPUT);

  pinMode(ss7, INPUT);

  pinMode(ss8, INPUT);



  Serial.begin(9600);



}

void readsensors() {

  a = digitalRead(ss1);

  b = digitalRead(ss2);



  c = digitalRead(ss3);



  d = digitalRead(ss4);

  e = digitalRead(ss5);



  f = digitalRead(ss6);



  g = digitalRead(ss7);

  h = digitalRead(ss8);





}



void loop()
{

WELCOME :
  readsensors();
  if (a == HIGH && h == HIGH && ( d == LOW || e == LOW ) )
  {
    straight();
  }

  else if ( (a == LOW || b == LOW) && (d == LOW || e == LOW) && (g == LOW || h == LOW) )
  {
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(20);

    if ( (digitalRead(ss1) == LOW && digitalRead(ss2) == LOW) && ( digitalRead(ss4) == LOW && digitalRead(ss5) == LOW ) && ( digitalRead(ss7) == LOW && digitalRead(ss8) == LOW ) ) {



      digitalWrite(lm1, HIGH);

      digitalWrite(lm2, LOW);

      digitalWrite(rm1, HIGH);

      digitalWrite(rm2, LOW);

      delay(210);



      leftturn();

    }

    else {

      goto WELCOME;

    }

  }



  //making changes just down here if not working go for prev version opt 4



  else if ((a == LOW || b == LOW) && (e == LOW || d == LOW) && (h == HIGH || g == HIGH) )

  {

    digitalWrite(lm1, HIGH);

    digitalWrite(lm2, LOW); //re-CHANGED TO straight

    digitalWrite(rm1, HIGH);

    digitalWrite(rm2, LOW);

    delay(25);

    if ( (digitalRead(ss1) == LOW && digitalRead(ss2) == LOW) && ( digitalRead(ss4) == LOW || digitalRead(ss5) == LOW ) && ( digitalRead(ss7) == HIGH || digitalRead(ss8) == HIGH ))

    {

      Serial.println("check");

      digitalWrite(lm1, HIGH);

      digitalWrite(lm2, LOW);

      digitalWrite(rm1, HIGH);

      digitalWrite(rm2, LOW);

      delay(210);

      leftturn();

    }

    else {

      goto WELCOME;

    }

  }



  else if ( a == HIGH && (g == LOW || h == LOW) && (e == LOW || d == LOW))

  {

    digitalWrite(lm1, HIGH);

    digitalWrite(lm2, LOW);

    digitalWrite(rm1, HIGH);

    digitalWrite(rm2, LOW);

    delay(25);







    if ( (digitalRead(ss1) == HIGH && digitalRead(ss2) == HIGH) && ( digitalRead(ss4) == LOW && digitalRead(ss5) == LOW ) && ( digitalRead(ss7) == LOW || digitalRead(ss8) == LOW ) ) {



      digitalWrite(lm1, HIGH);

      digitalWrite(lm2, LOW);

      digitalWrite(rm1, HIGH);

      digitalWrite(rm2, LOW);

      delay(210);



      if ( ( digitalRead(ss4) == LOW || digitalRead(ss5) == LOW ) && ( digitalRead(ss8) == HIGH ) && (digitalRead(ss1) == HIGH )) {



        straight();

      }



      else if ( (digitalRead(ss1) == HIGH && digitalRead(ss2) == HIGH) && ( digitalRead(ss4) == HIGH && digitalRead(ss5) == HIGH ) && ( digitalRead(ss7) == HIGH && digitalRead(ss8) == HIGH )) {

        rightturn();

      }



    }



    else if ( (digitalRead(ss1) == LOW && digitalRead(ss2) == LOW) && ( digitalRead(ss4) == LOW && digitalRead(ss5) == LOW ) && ( digitalRead(ss7) == LOW && digitalRead(ss8) == LOW )) {

      digitalWrite(lm1, HIGH);

      digitalWrite(lm2, LOW);

      digitalWrite(rm1, HIGH);

      digitalWrite(rm2, LOW);

      delay(210);



      leftturn();

    }



    else {

      goto WELCOME;

    }

  }



  else if (a == HIGH && b == HIGH && c == HIGH && d == HIGH && e == HIGH && f == HIGH && g == HIGH && h == HIGH )

  {

    digitalWrite(lm1, HIGH);

    digitalWrite(lm2, LOW);

    digitalWrite(rm1, HIGH);

    digitalWrite(rm2, LOW);

    delay(25);

    if (a == HIGH && b == HIGH && c == HIGH && d == HIGH && e == HIGH && f == HIGH && g == HIGH && h == HIGH  )
    {



      digitalWrite(lm1, HIGH);

      digitalWrite(lm2, LOW);

      digitalWrite(rm1, HIGH);

      digitalWrite(rm2, LOW);

      delay(210);

      turnover();//added turnover

    }

    else {

      goto WELCOME;

    }

  }











}





void straight()

{

  if ( digitalRead(ss5) == HIGH || digitalRead(ss3) == LOW ) {

    digitalWrite(lm1, HIGH);

    digitalWrite(lm2, LOW);

    digitalWrite(rm1, HIGH);

    digitalWrite(rm2, LOW);

    delay(1);

    digitalWrite(lm1, LOW);

    digitalWrite(lm2, LOW);

    digitalWrite(rm1, HIGH);

    digitalWrite(rm2, LOW);

    delay(1);

    return;

  }

  if (digitalRead(ss4) == HIGH || digitalRead(ss6) == LOW ) {

    digitalWrite(lm1, HIGH);

    digitalWrite(lm2, LOW);

    digitalWrite(rm1, HIGH);

    digitalWrite(rm2, LOW);

    delay(1);

    digitalWrite(lm1, HIGH);;//changing from 230 to HIGH

    digitalWrite(lm2, LOW);

    digitalWrite(rm1, LOW);

    digitalWrite(rm2, LOW);

    delay(1);

    return;

  }

  digitalWrite(lm1, HIGH);

  digitalWrite(lm2, LOW);

  digitalWrite(rm1, HIGH);

  digitalWrite(rm2, LOW);

  delay(1);



}



void leftturn() {

  while (digitalRead(ss1) == HIGH)

  {

    Serial.println("1");

    digitalWrite(lm1, LOW);

    digitalWrite(lm2, HIGH);

    digitalWrite(rm1, HIGH);

    digitalWrite(rm2, LOW);

    delay(1);//making changes here

    /*digitalWrite(lm1, LOW);

      digitalWrite(lm2, LOW);

      digitalWrite(rm1, LOW);

      digitalWrite(rm2, LOW);

      delay(1);*/

  }

  while (digitalRead(ss5) == HIGH || digitalRead(ss4) == HIGH)

  {

    Serial.println("2");

    digitalWrite(lm1, LOW);

    digitalWrite(lm2, HIGH);//CHANGED 240 TO HIGH

    digitalWrite(rm1, HIGH);//CHANGED 240 TO HIGH

    digitalWrite(rm2, LOW);

    delay(1);

    /*digitalWrite(lm1, LOW);

      digitalWrite(lm2, LOW);

      digitalWrite(rm1, LOW);

      digitalWrite(rm2, LOW);

      delay(1);*/

  }

  if (digitalRead(ss5) == LOW) {

    digitalWrite(lm1, LOW);

    digitalWrite(lm2, LOW);

    digitalWrite(rm1, LOW);

    digitalWrite(rm2, LOW);

    delay(2);



    /*digitalWrite(lm1, LOW);

      digitalWrite(lm2, LOW);

      digitalWrite(rm1, LOW);

      digitalWrite(rm2, LOW);

      delay(1);*/

  }



}



void turnover() {

  while (digitalRead(ss8) == HIGH) {

    digitalWrite(lm1, HIGH);

    digitalWrite(lm2, LOW);

    digitalWrite(rm1, LOW);

    digitalWrite(rm2, HIGH);

    delay(1);

    /*digitalWrite(lm1, LOW);

      digitalWrite(lm2, LOW);

      digitalWrite(rm1, LOW);

      digitalWrite(rm2, LOW);

      delay(1);*/

  }



  while (digitalRead(ss4) == HIGH || digitalRead(ss5) == HIGH) { //changed from ss5 and ss6

    digitalWrite(lm1, HIGH);

    digitalWrite(lm2, LOW);

    digitalWrite(rm1, LOW);

    digitalWrite(rm2, HIGH);//CHANGED FROM 240 TO HIGH

    delay(1);

    /*digitalWrite(lm1, LOW);

      digitalWrite(lm2, LOW);

      digitalWrite(rm1, LOW);

      digitalWrite(rm2, LOW);

      delay(1);*/

  }

  if (digitalRead(ss4) == LOW) {

    digitalWrite(lm1, LOW);

    digitalWrite(lm2, LOW);//CHANGED FROM 240 TO HIGH

    digitalWrite(rm1, LOW);

    digitalWrite(rm2, LOW);

    delay(2);

    /*digitalWrite(lm1, LOW);

      digitalWrite(lm2, LOW);

      digitalWrite(rm1, LOW);

      digitalWrite(rm2, LOW);

      delay(1);*/

  }



}



void rightturn() {

  while (digitalRead(ss8) == HIGH) {

    digitalWrite(lm1, HIGH);

    digitalWrite(lm2, LOW);

    digitalWrite(rm1, LOW);

    digitalWrite(rm2, HIGH);

    delay(1);

    /*digitalWrite(lm1, LOW);

      digitalWrite(lm2, LOW);

      digitalWrite(rm1, LOW);

      digitalWrite(rm2, LOW);

      delay(1);*/

  }



  while (digitalRead(ss4) == HIGH || digitalRead(ss5) == HIGH) {

    digitalWrite(lm1, HIGH);

    digitalWrite(lm2, LOW);

    digitalWrite(rm1, LOW);

    digitalWrite(rm2, HIGH);//CHANGED FORM 240 TO HIGH

    delay(1);

    /*digitalWrite(lm1, LOW);

      digitalWrite(lm2, LOW);

      digitalWrite(rm1, LOW);

      digitalWrite(rm2, LOW);

      delay(1);*/

  }

  if (digitalRead(ss4) == LOW) {

    digitalWrite(lm1, LOW);

    digitalWrite(lm2, LOW);

    digitalWrite(rm1, LOW);//LOOKS ODD SO CHANGED TO LOW

    digitalWrite(rm2, LOW);

    delay(1);

    /*digitalWrite(lm1, LOW);

      digitalWrite(lm2, LOW);

      digitalWrite(rm1, LOW);

      digitalWrite(rm2, LOW);

      delay(1);*/

  }



}
