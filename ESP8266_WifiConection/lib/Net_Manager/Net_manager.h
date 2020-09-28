#ifndef NET_MANAGER_H
#define NET_MANAGER_H
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <EepromDataStored.h>
#include <ledManager.h>

class Net_manager
{
    private:
    //variables
    String ssidAP;
    unsigned long previousMillis;
	unsigned long currentMillis;
    uint8_t wifi_Status;
    String ssid;
    String password;

    public:
    //contruct
    Net_manager();
   
    //methods
    void begin();
    void loop();
    String getSsid();
    String getPassword();
    void accessPointConnection();
    void serverOn();
    void saveWiFiCredentials();
    String ssidValue();
    String PassValue();
};
extern Net_manager net_manager;
#endif