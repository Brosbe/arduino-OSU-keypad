#include <Keyboard.h>
//might try and optimize this further later
int mapped;

//when pressed, there is a small buffer to check whether the value has changed enough.
const int pressBuffer = 1;

const int treshold = 120;

int prevPress1;
int prevPress2;

bool isPressed1;
bool isPressed2;

void setup()
{
  Keyboard.begin();
  int prevPress1 = treshold;
  int prevPress2 = treshold;
}

void loop() 
{
  mapInputs(A3);

  if (!Buffercheck(mapped, prevPress1)) 
  {
    if (mapped <= treshold) 
    {
      if (mapped < prevPress1 && !isPressed1) 
      {
        Keyboard.press(115);
        isPressed1 = true;
      }

      else if (mapped > prevPress1 && isPressed1) 
      {
        Keyboard.release(115);
        isPressed1 = false;
      }
    } 
    else
    {
     Keyboard.release(115);
     isPressed1 = false;
    }    
 
    prevPress1 = mapped;
    
  }

  mapInputs(A2);
  if (!Buffercheck(mapped, prevPress2)) 
  {
    if (mapped <= treshold) 
    {
      if (mapped < prevPress2 && !isPressed2) 
      {
        Keyboard.press(100);
        isPressed2 = true;
      }

      else if (mapped > prevPress2 && isPressed2) 
      {
        Keyboard.release(100);
        isPressed2 = false;
      }
    } 
    else
    {
     Keyboard.release(100);
     isPressed2 = false;
    }    
    prevPress2 = mapped;
  }
  delay(1);
}

bool Buffercheck(int input1, int input2) 
{
  switch (input1 - input2)
  {
    case pressBuffer:
    case -pressBuffer:
      return true;
   default:
     return false;
  }
}

void mapInputs(uint8_t analogpin)
{
  //values here can change depending on how you placed your switches or sensors, the types of sensors and what board you use.
  mapped = map(analogRead(analogpin), 244, 429, 1, 128);
}