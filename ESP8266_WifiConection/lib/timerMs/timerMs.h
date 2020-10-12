#ifndef TIMERMS_H
#define TIMERMS_H
#include <Arduino.h>

class timerMs
{
private:
    unsigned long startTime;
    unsigned long timer;
public:
    timerMs();
    void setTimer(unsigned long _ms);
    bool timerOver();
    

};

extern timerMs timerms;
#endif