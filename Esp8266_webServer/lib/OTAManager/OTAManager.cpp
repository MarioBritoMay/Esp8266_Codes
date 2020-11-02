#include "OTAManager.h";

// #define FIRMWARE_VERSION 1
#define UPDATE_JSON_URL "https://hl110.lucushost.org/archivos"//se necesita verificar el servidor

OTAManager::OTAManager()
{

}

void OTAManager::begin()
{
  if (net_manager.getWifiFlag())
  {
    otamanager.CheckUpdates();//funcion para checar actualizaciones, necesita añadirce un control de versiones
  }
}

void OTAManager::CheckUpdates()
{
  t_httpUpdate_return ret = ESPhttpUpdate.update("http://server/file.bin"); //Location of your binary file   
  
  switch(ret) 
  {
    case HTTP_UPDATE_FAILED:
    Serial.println("[update] Update failed.");
    break;
    case HTTP_UPDATE_NO_UPDATES:
    Serial.println("[update] Update no Update.");
    break;
    case HTTP_UPDATE_OK:
    Serial.println("[update] Update ok."); 
    break;
  }
}

OTAManager otamanager;