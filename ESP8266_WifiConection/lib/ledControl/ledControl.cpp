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
    if(timerms.timerOver())
    {
      if(blinkTime > 0) 
      {
        digitalWrite(ledPin, !digitalRead(ledPin));
        timerms.setTimer(blinkTime);
      }
    }
  }

  void ledControl::blinkLed(unsigned long ms)
  {
    digitalWrite(ledPin, 0);
    blinkTime = ms;
    timerms.setTimer(blinkTime);
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