#include "stdio.h"
#include "types.h"
#include "evmc6748.h"
#include "evmc6748_timer.h"
#include "evmc6748_i2c.h"
#include "evmc6748_led.h"
#include "evmc6748_dip.h"

int flashLED();
int victory();
int defeat();

int myFunct()
{
	LED_turnOn(LED_1);
	LED_turnOff(LED_2);
	int x;
	x = rand() % 16;

	printf("What is %d in binary?\n", x);

	flashLED();

	int total = calculateSwitches();

	if (total == x)
	{
		victory();
		return 1;
	}
	else
	{
		defeat();
		return 0;
	}
}


int calculateSwitches(){
	uint8_t total;
	uint8_t dipValue1, dipValue2, dipValue3, dipValue4;

	DIP_get(DIP_1,&dipValue1);
	DIP_get(DIP_2,&dipValue2);
	DIP_get(DIP_3,&dipValue3);
	DIP_get(DIP_4,&dipValue4);

	total = dipValue1 + dipValue2*(2) + dipValue3*(4) + dipValue4*(8);

	return total;
}

int flashLED(){
	int i;
	for (i = 0; i < 20; i++)
	{
		LED_toggle(LED_2);
		USTIMER_delay(DELAY_HALF_SEC);
	}
	return 0;
}

int victory()
{
	int i;
	for (i = 0; i < 8; i++)
	{
		LED_toggle(LED_1);
		LED_toggle(LED_2);
		USTIMER_delay(DELAY_QUARTER_SEC);
	}
	return 0;
}

int defeat()
{
	LED_turnOff(LED_1);
	LED_turnOff(LED_2);
	USTIMER_delay(DELAY_1_SEC);
	USTIMER_delay(DELAY_1_SEC);
	return 0;
}
