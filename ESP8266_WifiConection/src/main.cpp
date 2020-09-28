#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Net_manager.h>
#include <Boot_button.h>
#include <EepromDataStored.h>
 
// Sustituir con datos de vuestra red
 
void setup()
{
  net_manager.begin();
  eepromdatastored.begin();
  boot_button.begin(0);
 
}
 
void loop() 
{
  net_manager.loop();
  boot_button.loop();
}