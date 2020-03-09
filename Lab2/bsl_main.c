#include "stdio.h"
#include "types.h"
#include "evmc6748.h"
#include "evmc6748_timer.h"
#include "evmc6748_i2c.h"
#include "evmc6748_led.h"
#include "evmc6748_dip.h"

int myFunct();

void main(void)
{
	int score = 0;
	uint8_t dipValue8;

	I2C_init(I2C0, I2C_CLK_400K);
	USTIMER_init();
	LED_init();
	DIP_init();

	while(1)
	{
		DIP_get(DIP_8,&dipValue8);
		if (dipValue8 == 1)
		{
			if(myFunct()==1)
				score = score + 1;
			else
				score = 0;

			printf("Current score is %d! \n", score);
		}
	}
	/*while (1)
	{
		USTIMER_delay(DELAY_1_SEC);
		DIP_get(DIP_1,&dip_1);
		DIP_get(DIP_2,&dip_2);
		DIP_get(DIP_3,&dip_3);
		DIP_get(DIP_4,&dip_4);
		DIP_get(DIP_5,&dip_5);
		DIP_get(DIP_6,&dip_6);
		DIP_get(DIP_7,&dip_7);
		DIP_get(DIP_8,&dip_8);
		DIP_getAll(&dip_all);
		LED_toggle(LED_1);
		LED_toggle(LED_2);

		printf("==============\n");
		printf("DIPs: %d, %d, %d, %d, %d, %d, %d, %d\n", dip_1,
		dip_2,dip_3,dip_4,dip_5,dip_6,dip_7,dip_8);
		printf("ALL: %d\n",dip_all);
	}*/
}

