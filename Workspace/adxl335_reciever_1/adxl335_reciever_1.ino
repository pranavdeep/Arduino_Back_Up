#include <VirtualWire.h>
const int datain = 12;

 
 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  
vw_set_ptt_inverted(true);
    vw_set_rx_pin(datain);
    vw_setup(2000);
    pinMode(LED_BUILTIN, OUTPUT);
       vw_rx_start();
   
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN; 
 
    if (vw_get_message(buf, &buflen))
    {
      if(buf[0]=='1')
      {  
        Serial.println("1");

       digitalWrite(LED_BUILTIN,HIGH);
      }  
      if(buf[0]=='0')
      {
       Serial.println("0");

       digitalWrite(LED_BUILTIN,LOW);
      }
    }
    else
    Serial.println("No input");
}
