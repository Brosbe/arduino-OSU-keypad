#include <Keyboard.h>

const uint8_t analogInPin1 = A3;
const uint8_t analogInPin2 = A2;

int mapped;

bool curPress1;
bool curPress2;

bool prevPress1;
bool prevPress2;


void setup() 
{
  Keyboard.begin();
}

void loop() 
{

  mapInputs();

  if(curPress1 && !prevPress1)
  {
    Keyboard.press(115);
  }

  if(!curPress1 && prevPress1)
  {
    Keyboard.release(115);
  }


  if(curPress2 && !prevPress2)
  {
    Keyboard.press(100);
  }

  if(!curPress2 && prevPress2)
  {
    Keyboard.release(100);
  }

  prevPress1 = curPress1;
  prevPress2 = curPress2;
  
  delay(1);
}

void mapInputs()
{
  //values here can change depending on how you placed your switches or sensors, the types of sensors and what board you use.
  curPress1 = map(analogRead(A3), 244, 429, 1, 128) < 178;
  curPress2 = map(analogRead(A2), 244, 429, 1, 128) < 178;
}