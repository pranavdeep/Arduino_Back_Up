//#include <DHT.h>
//#include <DHT_U.h>

#include <SPI.h>
//#include <DHT.h>



//#define dht_apin 8 // DHT data pin is connected to digital pin
//dht DHT;


volatile boolean process_it;                                   //Flag for checking if the data is recieved from Master i.e. ESP8266
double a;                                                        //Byte to store the processed data
double temp=0, humid=0,c;
int i=0,arr[5];

void setup(void)
{
    Serial.begin(115200);                                     //Set UART baug rate to 115200
    SPCR |= bit(SPE);                                         //Configure ATMEGA328P/Arduino in slave mode
    pinMode(MISO, OUTPUT);                                    //Configure MISO as output, SlaveOut
    process_it = false;                                       //Initialize flag to FALSE
    SPI.attachInterrupt();                                    //Enable interrupts for SPI--> You can do that like this too /*SPCR |= bit (SPIE)*/
}

// SPI interrupt routine
ISR(SPI_STC_vect)
{
    /*DHT.read11(dht_apin);//calling in values from dht sensor*/
  while(i<3)
  {
  temp=44;//DHT.temperature;//saving temperature and humidity values to variables
  humid=22;//DHT.humidity;
  arr[0]=temp;
  arr[1]=humid;
     c = SPDR;                                           //Grab the data byte from the SPI Data Register (SPDR)
    a = c;                                                   //Put the byte into a temporary variable for processing
   SPDR = arr[i];                                            //process the data byte and put it back into the SPDR for the Master to read it
    i++;
    process_it = true; //Set the Flag as TRUE
   Serial.print("i=");
   Serial.println(i);
   Serial.print("SPDR=");
   Serial.println(SPDR);
  }
    
}

void loop(void)
{

   //DHT.read11(dht_apin);//calling in values from dht sensor
    if (process_it)                                         //Check if the data has been processed
    {
        Serial.println("Recieved\r\n");                     //UART - Notify if recived a byte from master
        process_it = false;                                 //Set the Flag to False
    }
}
