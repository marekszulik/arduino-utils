#include "Arduino.h"
#include "Button.h"

Button::Button(int pin) {
  pinMode(pin, INPUT);
  _pin = pin;
  _state = LOW;
  _previousState = LOW;
  _previousDebounceTime = 0;
}

bool Button::isPressed() {
  bool returnValue = false;

  int reading = digitalRead(_pin);

  if (reading != _state) {
    _previousDebounceTime = millis();
  }

  if (millis() - _previousDebounceTime > 100 && reading != _state) {
    _state = reading;
  }

  if (_state == HIGH && _previousState == LOW) {
    returnValue = true;
  }

  _previousState = _state;

  return returnValue;
}
