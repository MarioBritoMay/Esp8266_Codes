  #include <ledManager.h>

  ledManager::ledManager()
  {

  }

  void ledManager::begin()
  {
    pinMode(15, OUTPUT);
    digitalWrite(15,1);
  }

  void ledManager::ledGreenLoop()
  {
    if(TimerG.expired())
    {
      if(blinkGTime > 0) 
      {
        digitalWrite(15, !digitalRead(15));
        TimerG.countdown_ms(blinkGTime);
      }
    }
  }

  void ledManager::blinkG(unsigned long ms)
  {
    digitalWrite(15, 0);
    blinkGTime = ms;
    TimerG.countdown_ms(blinkGTime);
  }

  void ledManager::greenOn()
  {
    digitalWrite(15,1);
  }

  void ledManager::greenOf()
  {
      digitalWrite(15,0);
  }

  ledManager ledmanager;