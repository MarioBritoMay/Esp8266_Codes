	#ifndef LEDCONTROL_H
	#define LEDCONTROL_H
	#include <Arduino.h>
	#include "TimerMs.h"

	TimerMs timer;

	class ledControl
	{
	private:
	  //variables privadas
	  unsigned long blinkTime;
	  uint8_t ledPin;

	public:
	 //variables publicas

	//constructor
	ledControl();
	//metodos
	void begin(uint8_t _pin);
	void ledLoop();
	void blinkLed(unsigned long ms);
	void ledOn();
	void ledOff();


	};
	extern ledControl ledcontrol;
	#endif
