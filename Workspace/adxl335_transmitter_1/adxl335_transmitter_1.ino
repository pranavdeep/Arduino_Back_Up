#include <VirtualWire.h>

//#define dataout A0
char *data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
//pinMode(dataout, OUTPUT);
vw_set_ptt_inverted(true);
  vw_set_tx_pin(12);
    vw_setup(4000);

}

void loop() {
  // put your main code here, to run repeatedly:
data="1";
  vw_send((uint8_t *)data, strlen(data));
  vw_wait_tx();
Serial.println("1");
delay(2000);
  data="0";
  vw_send((uint8_t *)data, strlen(data));
  vw_wait_tx();
  Serial.println("0");

    delay(2000);

}
