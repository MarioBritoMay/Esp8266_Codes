#include "TimerMs.h"

TimerMs::TimerMs()
{
    TimerMs(1000);
}

TimerMs::TimerMs(unsigned long _ms)
{
    startTime = 0;
    timer = 0;
    setTimer(_ms);
}

void TimerMs::setTimer(unsigned long _ms)
{
    startTime = millis();
    timer = _ms;
}

bool TimerMs::timerOver()
{
    unsigned long now = millis();
    if ((unsigned long) (now - startTime) >= timer) 
    return true;
    else
    return false;
}