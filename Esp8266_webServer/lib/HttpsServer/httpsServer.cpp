#include "HttpsServer.h";

HttpsServer::HttpsServer()
{

}

void HttpsServer::begin()
{
    // Create a WiFiClientSecure object.
    Serial.println(host);
    Serial.printf("Using fingerprint '%s'\n", fingerprint.c_str());
    // Set the fingerprint to connect the server.
    httpsClient.setFingerprint(fingerprint.c_str());
    httpsClient.setTimeout(15000); // 15 Seconds
    delay(1000);
    Serial.print("HTTPS Connecting");
    int r=0; //retry counter
    while((!httpsClient.connect(host, httpsPort)) && (r < 30))
    {
        delay(100);
        Serial.print(".");
        r++;
    }
    if(r==30) 
    Serial.println("Connection failed");
    else 
    Serial.println("Connected to web");
}

void HttpsServer::loop()
{
    if (net_manager.getWifiFlag())
    {
        httpsserver.sendData();
        delay(5000);
    }
}

void HttpsServer::sendData()
{
    httpsserver.begin();
    String ADCData, link;
    uint8_t randomNumber = random(1,100);
    ADCData = String(randomNumber);
    Serial.println("Random number:" + ADCData);
    //GET Data
    link = "/comments?postId=" + ADCData;
    Serial.print("requesting URL: ");
    Serial.println(host + link);
    httpsClient.print(String("GET ") + link + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +               
               "Connection: close\r\n\r\n");
    Serial.println("request sent");

     while (httpsClient.connected()) 
     {
        String line = httpsClient.readStringUntil('\n');
        if (line == "\r") 
        {
            Serial.println("headers received");
            break;
        }
    }
    Serial.println("reply was:");
    Serial.println("==========");
    String line;
    while(httpsClient.available())
    {        
        line = httpsClient.readStringUntil('\n');  //Read Line by Line
        Serial.println(line); //Print response
    }
    Serial.println("==========");
    Serial.println("closing connection");
}

HttpsServer httpsserver;