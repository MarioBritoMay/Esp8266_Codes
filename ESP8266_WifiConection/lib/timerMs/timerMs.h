#ifndef TIMERMS_H
#define TIMERMS_H
#include <Arduino.h>

class TimerMs
{
private:
    unsigned long startTime;
    unsigned long timer;
public:
    TimerMs();
    TimerMs(unsigned long _ms);
    void setTimer(unsigned long _ms);
    bool timerOver();
    

};

#endif