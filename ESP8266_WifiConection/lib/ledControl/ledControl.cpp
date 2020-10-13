  #include <ledControl.h>

  ledControl::ledControl()
  {
    
  }

  void ledControl::begin(uint8_t _pin)
  {
    ledPin = _pin;
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, 1);
  }

  void ledControl::ledLoop()
  {
    if(timer.timerOver())
    {
      if(blinkTime > 0) 
      {
        digitalWrite(ledPin, !digitalRead(ledPin));
        timer.setTimer(blinkTime);
      }
    }
  }

  void ledControl::blinkLed(unsigned long ms)
  {
    digitalWrite(ledPin, 0);
    blinkTime = ms;
    timer.setTimer(blinkTime);
  }

  void ledControl::ledOn()
  {
    digitalWrite(ledPin,1);
  }

  void ledControl::ledOff()
  {
      digitalWrite(ledPin,0);
  }

  ledControl ledcontrol;