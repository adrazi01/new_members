#include <Arduino.h>

#define CAN_PIN 2

int rpm;
int id;
int len;
int data;

void recieveCanMessage(id, len, data);

void setup()
{
  pinMode(CAN_PIN, INPUT);
}

void loop()
{
  if (id = 1250)
  {
    recieveCanMessage(id, len, data);
  }
}

void recieveCanMessage(id, len, data);
{
  for (int i = 8; i < len, i++)
  {
    rpm[i];
  }
}
