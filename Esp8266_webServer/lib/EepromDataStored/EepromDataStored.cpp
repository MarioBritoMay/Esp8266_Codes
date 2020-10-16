#include "EepromDataStored.h"

EepromDataStored::EepromDataStored()
{

}

void EepromDataStored::begin()
{
    EEPROM.begin(MEMORY_SIZE);
    Serial.println("");
    eepromdatastored.printSsidPass();
}

void EepromDataStored::printSsidPass()
  {
    //print the SSID and Password saved
    eepromdatastored.read(1).toCharArray(ssidread, 50);
    eepromdatastored.read(51).toCharArray(passread, 50);
    Serial.println(ssidread);
    Serial.println(passread);
  }

void EepromDataStored::saveSSID(String ssid)
  {
    // Serial.println(a);
    int address = 1;
    int ssidLength = ssid.length();
    char inchar [50];
    ssid.toCharArray(inchar, ssidLength + 1);
    for (int i = 0; i < ssidLength; i++)
    {
      EEPROM.write(address + i, inchar[i]);  //(EEPROM address, value)
    }
    for (int i = ssidLength; i < LIMIT_INPUT; i++)
    {
      EEPROM.write(address + i, 255);
    }
    EEPROM.commit();
  }

void EepromDataStored::savePassword(String password)
  {
    // Serial.println(b);
    int address = 51;
    int passLength = password.length();
    char inchar[50];
    password.toCharArray(inchar, passLength + 1);
    for (int i = 0; i < passLength; i++)
    {
      EEPROM.write(address + i, inchar[i]);
    }
    for (int i = passLength; i < LIMIT_INPUT; i++)
    {
      EEPROM.write(address + i, 255);
    }
    EEPROM.commit();
  }

String EepromDataStored::read(int address)
{
    byte lectura;
    String strlectura = "";
    for (int i = address; i < address + LIMIT_INPUT; i++)
    {
      lectura = EEPROM.read(i);
      if (lectura != 255 && lectura != 0)
      {
          strlectura += (char)lectura;
      }
    }
    return strlectura;
}
EepromDataStored eepromdatastored;