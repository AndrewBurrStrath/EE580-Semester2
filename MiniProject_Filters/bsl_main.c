#include "stdio.h"
#include "types.h"
#include "evmc6748.h"
#include "evmc6748_timer.h"
#include "evmc6748_i2c.h"
#include "evmc6748_led.h"
#include "evmc6748_dip.h"

int lowPassFilter();
int bandPassFilter();
int highPassFilter();

void main(void){
	int score = 0;
	uint8_t dipValue6;
	uint8_t dipValue7;
	uint8_t dipValue8;
	
	//Circular buffer temporary initialisation
	float circularBuffer[900];
	float *cb = circularBuffer;

	I2C_init(I2C0, I2C_CLK_400K);
	USTIMER_init();
	LED_init();
	DIP_init();

	while(1)	{
		DIP_get(DIP_6,&dipValue6);
		DIP_get(DIP_7,&dipValue7);
		DIP_get(DIP_8,&dipValue8);
		
		if(dipValue6)
			lowPassFilter(cb);
		if(dipValue7)
			bandPassFilter(cb);
		if(dipValue8)
			highPassFilter(cb);
	}
}
	
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

