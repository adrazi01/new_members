#include "mcp_can.h"
#include <SPI.h>

MCP_CAN CAN0(10);    

unsigned char stmp[8] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37}; // Test message


void setup() {
  
  /*Brzina prijenosa*/
  Serial.begin(9600);
  
  /*Pokrecemo CAN kontroler*/
  if (CAN0.begin(CAN_250KBPS) == CAN_OK)  
    Serial.print("CAN Init OK.\n\r\n\r");
  else
    Serial.print("CAN Init Failed.\n\r");
  
}// end setup

void loop() 
{
  /*Salje se podatak oznacem sa id = 0x1FF, CAN_EXITD oznacava prosireni okvir poruke, a
   * data len oznacava duzinu poruke*/
   
  CAN0.sendMsgBuf(0x1FF, CAN_EXTID, 8, stmp);
  
  /*Interval se provodi svaku sekundu*/
  delay(1000);
  
}
