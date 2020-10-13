#include <ThingSpeakManager.h>

WiFiClient client;

ThingSpeakManager::ThingSpeakManager()
{

}

void ThingSpeakManager::begin(unsigned long _chanelID, const char * _APIKey)
{
    ThingSpeak.begin(client);
    publishTimer.setTimer(12000);
    channel_ID = _chanelID;
    myAPIKey = _APIKey;
}

void ThingSpeakManager::loop(uint8_t _Field)
{
  if (publishTimer.timerOver() && net_manager.getWifiFlag())
  {
    thingspeakmanager.sendData(_Field);
    publishTimer.setTimer(12000);
  }
}

void ThingSpeakManager::sendData(uint8_t _Field)
{
  uint8_t randomNumber = random(1,100);
  Serial.println("Random number:" + String(randomNumber));
  ThingSpeak.setField(1, randomNumber);
  //lo igualamosa una variable para que guarde el valor del codigo HTTP
  int x = ThingSpeak.writeFields(channel_ID, myAPIKey);
  delay(100);
  //200 codigo http "OK"
  if(x == 200)
    Serial.println("OK");
  else
    Serial.println("Problem updating channel. HTTP error code " + String(x));
}

ThingSpeakManager thingspeakmanager;