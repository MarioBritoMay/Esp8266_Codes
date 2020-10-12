#include "Net_manager.h"
#include <htmlPage.h>
#define SERVER_PORT 80

ESP8266WebServer server(SERVER_PORT);
String message = "";
void configurePage()
{
    server.send(200, "text/html",  htmlPage +  message + htmlPageEnd); 
}

Net_manager::Net_manager()
{
    ssidAP = "ESP_red";
    wifi_Status = 0;
}

void Net_manager::begin()
{
    previousMillis = millis();
    Serial.begin(9600);
}

void Net_manager::loop()
{
    currentMillis = millis();
    if (currentMillis - previousMillis > 3000)
    {
      if (WiFi.status() != WL_CONNECTED)
      {
        previousMillis = millis();
        wifi_Status = false;
        Serial.print(".");
        ledcontrol.blinkLed(250);
        WiFi.mode(WIFI_STA);  //para que no inicie el SoftAP en el modo normal
        WiFi.begin(net_manager.getSsid(), net_manager.getPassword()); 
      }
    }
    if (WiFi.status() == WL_CONNECTED && wifi_Status == false)
    {
      Serial.println("");
      Serial.println("WiFi connected");
      wifi_Status = true;
      Serial.print("IP_address: "); 
      Serial.println(WiFi.localIP());
      ledcontrol.ledOff();
    }
}

String Net_manager::getSsid()
{
    ssid = eepromdatastored.read(1);
    return ssid;
}

String Net_manager::getPassword()
{
    password = eepromdatastored.read(51);
    return password;
}

void Net_manager::accessPointConnection()
{
    serverOn();
    Serial.print("Setting soft-AP ... ");
    boolean result = WiFi.softAP(ssidAP);//mando nombre de la red creada, se le puede añadir la contraseña
    if(result)
    {
        Serial.print("Soft-Ap mode Sucess ");
        ledcontrol.ledOn();
    }
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("IP:");
    Serial.println(myIP);
    while(true)
    {
      server.handleClient();
    }
}

void Net_manager::serverOn()
{
    server.on("/", configurePage);
    server.on("/configuration", std::bind(&Net_manager::saveWiFiCredentials, this));
    server.begin();
    Serial.println("HTTP server started");
}

void Net_manager::saveWiFiCredentials()
{
    eepromdatastored.saveSSID(net_manager.ssidValue());
    eepromdatastored.savePassword(net_manager.PassValue());
    eepromdatastored.printSsidPass();
    message = "Saved configuration...";
    configurePage();
    delay (500);
    ESP.restart();//reset
}

String Net_manager::ssidValue()
{
    String ssid= server.arg("ssid");
    return ssid;
}

String Net_manager::PassValue()
{
    String pass= server.arg("pass");
    return pass;
}

Net_manager net_manager;