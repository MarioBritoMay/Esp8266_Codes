#ifndef EEPROMDATASTORED_H
#define EEPROMDATASTORED_H
#include <Arduino.h>
#include <EEPROM.h>

#define MEMORY_SIZE 110
#define LIMIT_INPUT 50

class EepromDataStored
{
private:
    
public:
//construct
  EepromDataStored();
//variables
  char ssidread[50];
  char passread[50];
//methods
  void begin();
  void printSsidPass();
  void saveSSID(String ssid);
  void savePassword(String password);
  String read(int address);
};

extern EepromDataStored eepromdatastored;
#endif