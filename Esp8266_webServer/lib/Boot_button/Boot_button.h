#ifndef BOOT_BUTTON_H
#define BOOT_BUTTON_H
#include <Arduino.h>
#include <Net_manager.h>


class Boot_button
{
    private:
    //private variables
    uint8_t buttonPin;
    uint8_t buttonPushBegin;
    unsigned long previousMillis;
	unsigned long currentMillis;

    public:
    //construct
    Boot_button();
    //Methods
    void begin(uint8_t _pin);
    void loop();
};


extern Boot_button boot_button;
#endif