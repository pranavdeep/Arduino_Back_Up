
const int trigPin_2 = A3;
const int echoPin_2 = A2;

long duration_2;
int distance_2;

void setup() 
{
pinMode(trigPin_2, OUTPUT); // Sets the trigPin_2 as an Output
pinMode(echoPin_2, INPUT); // Sets the echoPin_2 as an Input
Serial.begin(9600); // Starts the serial communication
}

void loop()
{
ultrasonic_2();
}


void ultrasonic_2()
{
analogWrite(trigPin_2, 0);
delayMicroseconds(25);
analogWrite(trigPin_2, 255);
delayMicroseconds(25);
analogWrite(trigPin_2, 0);
duration_2 = pulseIn(echoPin_2, HIGH);
//distance_2= duration_2*0.034/2;
distance_2 = (duration_2/2) / 29.1;
Serial.print("distance_2: ");
Serial.println(distance_2);
}
