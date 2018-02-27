#include "process.h"

/*-----------------------------VARIABLE LOCAL-----------------------------------
------------------------------------------------------------------------------*/
u8 flagLed = 0, x, BuffLed[4];
u8 fontLed[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0x8f, 0x80, 0x90};
/*-----------------------------INTERRUPT FUNTION--------------------------------
------------------------------------------------------------------------------*/
#pragma vector = TIM4_OVR_UIF_vector
__interrupt void ISR_T4(void)			// period 1ms
{
	TIM4_ClearFlag(TIM4_FLAG_UPDATE);
	IWDG_ReloadCounter();
	
	if(flagLed == 0)
	{
	  	CTR1 = CTR2 = CTR3 = CTR4 = LED_OFF;
		flagLed = 1;
	}
	else
	{
	  	led7Scan(x++);
		if(x == 4) x = 0;
		flagLed = 0;
	}
}

#pragma vector = TIM2_OVR_UIF_vector
__interrupt void ISR_T2(void)			// period 50ms
{
	TIM2_ClearFlag(TIM2_FLAG_UPDATE);
	
}

/*-------------------------------PROCESS FUNTION--------------------------------
------------------------------------------------------------------------------*/
void __mainProcess(void)
{
	
}

/*-------------------------------LED 7 FUNTION----------------------------------
------------------------------------------------------------------------------*/
void led7Out(u8 dat)
{
 	LED7_A = (dat & 0x01) ? 1:0;
	LED7_B = (dat & 0x02) ? 1:0;
	LED7_C = (dat & 0x04) ? 1:0;
	LED7_D = (dat & 0x08) ? 1:0;
	
	LED7_E = (dat & 0x10) ? 1:0;
	LED7_F = (dat & 0x20) ? 1:0;
	LED7_G = (dat & 0x40) ? 1:0;
	LED7_DP = (dat & 0x80) ? 1:0;
}

void led7Scan(u8 num)
{
  	switch(num)
	{
		case 0:
		{
			CTR1 = LED_ON;  
			led7Out(BuffLed[0]);
			break;
		}
		case 1:
		{
			CTR2 = LED_ON; 
			led7Out(BuffLed[1]);
			break;
		}
		case 2:
		{
			CTR3 = LED_ON;  
			led7Out(BuffLed[2]);
			break;
		}
		case 3:
		{
			CTR4 = LED_ON;  
			led7Out(BuffLed[3]);
			break;
		}
	}
}

/*------------------------------BUTTON FUNTION----------------------------------
------------------------------------------------------------------------------*/
u8 set(void)
{
	if(BT_SET == PRESS)
	{
		delay_ms(20);
		if(BT_SET == PRESS)
		{
			while(BT_SET == PRESS);
			return PRESS;
		}
	}
	return NOT_PRESS;
}

u8 up(void)
{
	if(BT_UP == PRESS)
	{
		delay_ms(20);
		if(BT_UP == PRESS)
		{
			while(BT_UP == PRESS);
			return PRESS;
		}
	}
	return NOT_PRESS;
}

u8 down(void)
{
	if(BT_DOWN == PRESS)
	{
		delay_ms(20);
		if(BT_DOWN == PRESS)
		{
			while(BT_DOWN == PRESS);
			return PRESS;
		}
	}
	return NOT_PRESS;
}

u8 ok(void)
{
	if(BT_OK == PRESS)
	{
		delay_ms(20);
		if(BT_OK == PRESS)
		{
			while(BT_OK == PRESS);
			return PRESS;
		}
	}
	return NOT_PRESS;
}

/*--------------------------------BUZZ FUNTION----------------------------------
------------------------------------------------------------------------------*/
void buzz(u8 bip)
{
	while(bip)
	{
		BUZZ = BUZZ_ON;
		delay_ms(100);
		BUZZ = BUZZ_OFF;
		delay_ms(100);
		bip--;
	}
}