#include <VirtualWire.h>
void setup() {
  vw_set_ptt_inverted(true); // Required for DR3100
    vw_set_rx_pin(0);
    vw_setup(4000);  // Bits per sec
    pinMode(8, OUTPUT);

    vw_rx_start();
}

void loop() {
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
      if(buf[0]=='1'){

  
   digitalWrite(8,1);
      }  
   if(buf[0]=='0'){
      digitalWrite(8,0);
   }
}

}
