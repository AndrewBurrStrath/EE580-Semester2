//---------------------------------------------------------
// main example 3
//---------------------------------------------------------
#include "hellocfg.h"			//BIOS include file
#include "framework.h"

int16_t volatile mask = 0xffff;

//---------------------------------------------------------
//---------------------------------------------------------
void main(void)
{
	initAll();
	return;  		// return to BIOS scheduler
}


//---------------------------------------------------------
//---------------------------------------------------------
void dipPRD(void)
{
	uint8_t dip_status8;

	DIP_get(DIP_8, &dip_status8);

	if(dip_status8)
	{
		mask = 0xffff;
		LED_turnOn(LED_2);
	}
	else
	{
		mask = 0x0000;
		LED_turnOff(LED_2);
	}

	LED_toggle(LED_1);
}


//---------------------------------------------------------
//---------------------------------------------------------
void audioHWI(void)
{
	int16_t s16;

	s16 = read_audio_sample();
	if (MCASP->RSLOT)
	{
		// THIS IS THE LEFT CHANNEL!!!
		//s16 = process(s16);
		s16 &= mask;
	}
	else {
		// THIS IS THE RIGHT CHANNEL!!!
		//s16 = process(s16);
		s16 &= mask;
	}
	write_audio_sample(s16);
}

