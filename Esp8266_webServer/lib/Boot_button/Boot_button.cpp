#include <Boot_button.h>

Boot_button::Boot_button()
{
    buttonPushBegin = 0;
}

void Boot_button::begin(uint8_t _pin)
{
    buttonPin = _pin;
    pinMode(buttonPin, INPUT_PULLUP);
}

void Boot_button::loop() 
{
    if (!digitalRead(buttonPin))
    {
        if (!buttonPushBegin)
        {
            previousMillis = millis();
            buttonPushBegin = 1;
        }
        else if (buttonPushBegin && (currentMillis-previousMillis) > 5000)
        {
            net_manager.accessPointConnection();
            buttonPushBegin = 0;
            
        }
        currentMillis = millis();
    }
    else 
    {
        previousMillis = millis();
    }
}
Boot_button boot_button;