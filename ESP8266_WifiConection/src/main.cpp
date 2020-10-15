#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Net_manager.h>
#include <Boot_button.h>
#include <EepromDataStored.h>
// #include <ledControl.h>
#include <ThingSpeakManager.h>
 
// Sustituir con datos de vuestra red
 
void setup()
{
  net_manager.begin();
  eepromdatastored.begin();
  boot_button.begin(0);
  thingspeakmanager.begin(1184389, "D8ANNOIX09XAG7F4");
  // ledcontrol.begin(2);
 
}
 
void loop() 
{
  net_manager.loop();
  boot_button.loop();
  thingspeakmanager.loop(1);
  // ledcontrol.ledLoop();
 
}