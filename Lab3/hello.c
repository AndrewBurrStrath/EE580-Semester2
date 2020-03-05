//---------------------------------------------------------
// main example 3
//---------------------------------------------------------
#include "hellocfg.h"			//BIOS include file
#include "framework.h"
# include <math.h>

int16_t volatile mask = 0xffff;
float c[107];
#define pi 3.14159265358979323846;
//---------------------------------------------------------
//---------------------------------------------------------
void main(void)
{
	int i;
	for(i=0; i<107; i++){
		c[i] = sin(2*3.1415*i/107);
	}
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
	static unsigned int f = 450;


	s16 = read_audio_sample();


	static float frank[107];
	static float modulated[107];

	int start = 0;

	frank[start] = s16;

	modulated[start] = frank[start] * c[start];
	write_audio_sample(modulated[start]);

	if (start == 0)
	{
		start = 106;
	}
	else
	{
		start --;
	}

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



}


