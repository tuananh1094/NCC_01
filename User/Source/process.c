#include "process.h"

/*-----------------------------VARIABLE LOCAL-----------------------------------
------------------------------------------------------------------------------*/
typedef enum {STOP, RUN} status;
extern u8 flagLed, x , BuffLed[];
extern u8 fontLed[];

status flagRun = STOP, blinkSet = STOP;
extern u16 count_50ms, countBlink, countSet;

extern u16 total; 
extern u8 hourRam, minRam, sec;

__no_init u8 hourRom @0x4000;
__no_init u8 minRom  @0x4001;
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

	if(flagRun == RUN)
	{
		count_50ms++;
		if(count_50ms%2 == 0) CTRP = ~CTRP;
		if(count_50ms == 4)			// timer 1s
		{
			count_50ms = 0;
			sec++;
			if(sec == 60)
			{
				sec = 0;
				total--;
			}
		}
		
	}
	if(blinkSet == RUN)
	{
		countBlink ++;
		if(countBlink == 4)
		{
			switch(countSet)
			{
				case 0:
				{
				  	BuffLed[0] = BuffLed[1] = 0xFF;
					break;
				}
				case 1:
				{
				  	BuffLed[2] = BuffLed[3] = 0xFF;
					break;
				}
			}
		}
		if(countBlink == 8)
		{
		  	countBlink = 0;
			switch(countSet)
			{
				case 0:
				{
				  	BuffLed[0] = fontLed[hourRam/10];
					BuffLed[1] = fontLed[hourRam%10];
					BuffLed[2] = fontLed[minRam/10];
					BuffLed[3] = fontLed[minRam%10];
					break;
				}
				case 1:
				{
				  	BuffLed[0] = fontLed[hourRam/10];
					BuffLed[1] = fontLed[hourRam%10];
				  	BuffLed[2] = fontLed[minRam/10];
					BuffLed[3] = fontLed[minRam%10];
					break;
				}
			}
		}
	}
	
	//
}

/*-------------------------------PROCESS FUNTION--------------------------------
------------------------------------------------------------------------------*/
void __mainProcess(void)
{
	static u8 count;
	if(ok() == PRESS)
	{
		buzz(1);
		count ++;
		if(count == 2) count = 0;
	}
	if(count == 1)
	{
		flagRun = RUN;
		RELAY = RELAY_ON;
		led7OutTime(total/60, total%60);
		if(total == 0)
		{
			RELAY = RELAY_OFF;
			flagRun = STOP;
			count = 0;
			total =  hourRam*60 + minRam;
			led7OutTime(0, 0);
			buzz(10);
			CTRP = LED_ON;
		}
	}
	
	else 
	{	
		flagRun = STOP;
		RELAY = RELAY_OFF;
		if(set() == PRESS)
		{	
			__setFuntion();
		}
	}
	
}

/*---------------------------------SET FUNTION----------------------------------
------------------------------------------------------------------------------*/
void __setFuntion(void)
{
    status flagSet = STOP;
	u8 tmp;

	buzz(1);
	CTRP = LED_ON;
	
	blinkSet = RUN;
	flagSet = RUN;
	flagRun = STOP;
	countSet = 0;
	led7OutTime(hourRam, minRam);
	while(flagSet)
	{
		if(set() == PRESS)
		{
			buzz(1);
			countSet++;
			if(countSet == 2) countSet = 0;
		}
		if(countSet == 0)
		{
//			if(up() == PRESS)
//			{
//				buzz(1);
//				hourRam++;
//				if(hourRam == 100) hourRam = 0;
//			}
//			else if(down() == PRESS)
//			{
//				buzz(1);
//				if(hourRam == 0) hourRam = 100;
//				hourRam--;
//			}
		  	if(BT_UP == PRESS)
			{
				delay_ms(10);
				if(BT_UP == PRESS)
				{
					buzz(1);
					blinkSet = STOP;
					while(BT_UP == PRESS)
					{
						tmp++;
						delay_ms(10);
						if(tmp == 10)
						{
							tmp = 9;
							hourRam++;
							delay_ms(90);
							if(hourRam == 100) hourRam = 0;
						}
						led7OutTime(hourRam, minRam);
					}
					tmp = 0;
					hourRam++;
					if(hourRam == 100) hourRam = 0;
					blinkSet = RUN;
				}
			}
			else if(BT_DOWN == PRESS)
			{
				delay_ms(10);
				if(BT_DOWN == PRESS)
				{
					buzz(1);
					blinkSet = STOP;
					while(BT_DOWN == PRESS)
					{
						tmp++;
						delay_ms(10);
						if(tmp == 10)
						{
							tmp = 9;
							if(hourRam == 0) hourRam = 100;
							hourRam--;
							delay_ms(90);
							
						}
						led7OutTime(hourRam, minRam);
					}
					tmp = 0;
					if(hourRam == 0) hourRam = 100;
					hourRam--;
					blinkSet = RUN;
				}
			}
		}
		else if (countSet == 1)
		{
		  	if(BT_UP == PRESS)
			{
				delay_ms(10);
				if(BT_UP == PRESS)
				{
					buzz(1);
					blinkSet = STOP;
					while(BT_UP == PRESS)
					{
						tmp++;
						delay_ms(10);
						if(tmp == 10)
						{
							tmp = 9;
							minRam++;
							delay_ms(90);
							if(minRam == 60) minRam = 0;
						}
						led7OutTime(hourRam, minRam);
					}
					tmp = 0;
					minRam++;
					if(minRam == 60) minRam = 0;
					blinkSet = RUN;
				}
			}
			else if(BT_DOWN == PRESS)
			{
				delay_ms(10);
				if(BT_DOWN == PRESS)
				{
					buzz(1);
					blinkSet = STOP;
					while(BT_DOWN == PRESS)
					{
						tmp++;
						delay_ms(10);
						if(tmp == 10)
						{
							tmp = 9;
							if(minRam == 0) minRam = 60;
							minRam--;
							delay_ms(90);
							
						}
						led7OutTime(hourRam, minRam);
					}
					tmp = 0;
					if(minRam == 0) minRam = 60;
					minRam--;
					blinkSet = RUN;
				}
			}
//			if(up() == PRESS)
//			{
//				buzz(1);
//				minRam++;
//				if(minRam == 100) minRam = 0;
//			}
//			else if(down() == PRESS)
//			{
//				buzz(1);
//				if(minRam == 0) minRam = 100;
//				minRam--;
//			}
		}
		
		if(ok() == PRESS)
		{
			buzz(3);
			hourRom  = hourRam;
			minRom = minRam;
			total =  hourRam*60 + minRam; 
			flagSet = STOP;
			countSet = 0;
			blinkSet = STOP;
			led7OutTime(total/60, total%60);
		}
	}
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

void led7OutTime(u8 hour, u8 min)
{
	BuffLed[0] = fontLed[hour/10];
	BuffLed[1] = fontLed[hour%10];
	BuffLed[2] = fontLed[min/10];
	BuffLed[3] = fontLed[min%10];
}
/*------------------------------BUTTON FUNTION----------------------------------
------------------------------------------------------------------------------*/
u8 set(void)
{
	if(BT_SET == PRESS)
	{
		delay_ms(10);
		if(BT_SET == PRESS)
		{
			while(BT_SET == PRESS);
			return PRESS;
		}
	}
	return NOT_PRESS;
}
////////////////////////////////////////////////////////////////////////////////
u8 up(void)
{
	if(BT_UP == PRESS)
	{
		delay_ms(10);
		if(BT_UP == PRESS)
		{
			while(BT_UP == PRESS);
			return PRESS;
		}
	}
	return NOT_PRESS;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
u8 down(void)
{
	if(BT_DOWN == PRESS)
	{
		delay_ms(10);
		if(BT_DOWN == PRESS)
		{
			while(BT_DOWN == PRESS);
			return PRESS;
		}
	}
	return NOT_PRESS;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
u8 ok(void)
{
	if(BT_OK == PRESS)
	{
		delay_ms(10);
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

/*--------------------------------ROM FUNTION-----------------------------------
------------------------------------------------------------------------------*/
void readRom(void)
{
	if(hourRom == 0xFF) hourRom = 0;
	if(minRom == 0xFF) minRom =  0;
	hourRam = hourRom;
	minRam = minRom;
	total =  hourRam*60 + minRam; 
	led7OutTime(hourRam, minRam);
}
/*-----------------------------------the end----------------------------------*/