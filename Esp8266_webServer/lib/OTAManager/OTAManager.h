#ifndef OTAMANAGER_H
#define OTAMANAGER_H
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClientSecure.h>

class OTAManager
{
    private:
    // Define the hostname, the port number and the fingerprint.
    WiFiClientSecure httpsClient;
    const char *host = "";
    String fingerprint= "";
    const int httpsPort = 443;

    public:
    //contruct
    OTAManager();
    void begin();
    void loop();
    void sendData();
    //methods
   
};
extern OTAManager otamanager;

#endif