	#ifndef LEDMANAGER_H
	#define LEDMANAGER_H
	#include <Arduino.h>
	#include <VirtualTimer.h>

	class ledManager
	{
	private:
	  //variables privadas
	  VirtualTimer TimerG;
	  VirtualTimer TimerW;
	  unsigned long blinkGTime;

	uint8_t ledPin;

	public:
	 //variables publicas

	//constructor
	ledManager();
	//metodos
	void begin();
	void greenOn();
	void greenOf();
	void ledGreenLoop();
	void ledWhiteOn();
	void blinkG(unsigned long ms);


	};
	extern ledManager ledmanager;
	#endif
