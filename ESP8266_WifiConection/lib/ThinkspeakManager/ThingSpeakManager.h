#ifndef THINGSPEAKMANAGER_H
#define THINGSPEAKMANAGER_H
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include "TimerMs.h"

TimerMs publishTimer;

class ThingSpeakManager
{
private:
    unsigned long channel_ID;
    const char * myAPIKey;
public:
    ThingSpeakManager();
    void begin(unsigned long _chanelID, const char * _myAPIKey);
    void loop(uint8_t _Field);
    void sendData(uint8_t _Field);
  
};

extern ThingSpeakManager thingspeakmanager;
#endif