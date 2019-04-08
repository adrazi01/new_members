#include <SPI.h>
#include <mcp_can.h>

MCP_CAN CAN(10);

unsigned char len = 0;
unsigned char buf[8];
unsigned int canID;
uint16_t rpm;

static void rpmFromCAN();

void setup()
{
  Serial.begin(115200);

    while(CAN_OK != CAN.begin(CAN_1000KBPS))
    {
       Serial.println("CAN BUS Shield init fail");
       Serial.println("Init CAN BUS Shield again");
       delay(100);
    }
    
    Serial.println("CAN BUS Shield init ok!");

  attachInterrupt(10, rpmFromCAN, FALLING);
}



void loop()
{
}

static void rpmFromCAN(){
     CAN.readMsgBuf(&len, buf);
     canID = 1250;

     Serial.print(" Length is: ");
     Serial.println(len);
        
     if (len > 4) {
       for(int i = 0; i<len; i++) {
            
         Serial.write(buf[i]);
            
            rpm = buf[2];
            rpm = rpm << 8;
            rpm += buf[3];
         }
         Serial.println(rpm);
     }
  }
