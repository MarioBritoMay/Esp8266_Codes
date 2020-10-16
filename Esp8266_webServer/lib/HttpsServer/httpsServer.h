#ifndef HTTPSSERVER_H
#define HTTPSSERVER_H
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClientSecure.h>
#include <ESP8266HTTPClient.h>
#include <Net_manager.h>

class HttpsServer
{
    private:
    // Define the hostname, the port number and the fingerprint.
    WiFiClientSecure httpsClient;
    const char *host = "jsonplaceholder.typicode.com";
    String fingerprint= "f6233eac7a1d036315e24f57b610232e2253514e";
    const int httpsPort = 443;

    public:
    //contruct
    HttpsServer();
    void begin();
    void loop();
    void sendData();
    //methods
   
};
extern HttpsServer httpsserver;

#endif