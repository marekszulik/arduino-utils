#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button
{
  public:
    Button(int pin);
    bool isPressed();
  private:
    int _pin;
    int _state;
    int _previousState;
    int _previousDebounceTime;
  };

#endif
