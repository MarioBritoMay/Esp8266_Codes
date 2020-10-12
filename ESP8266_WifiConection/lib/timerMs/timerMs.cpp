#include "timerMs.h"

timerMs::timerMs()
{
    startTime = 0;
    timer = 0;
}

void timerMs::setTimer(unsigned long _ms)
{
    startTime = millis();
    timer = _ms;
}

bool timerMs::timerOver()
{
    unsigned long now = millis();
    if ((unsigned long) (now - startTime) >= timer) 
    return true;
    else
    return false;
}

timerMs timerms;