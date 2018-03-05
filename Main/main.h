/*****************************************************************************
  *Ten Tep          :     main.h
  *Ngay             :     24/12/2016
  *Tac Gia          :     Nguyen Tuan Anh
  *Cong Ty          :     MCA
  *Webside          :     mca.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Khai bao cac thu vien.
  *                      Cau hinh mot so chuc nang cho trinh bien dich.
  *                      Cau hinh mot so chuc nang cho CHIP.
  *                      Dinh nghia I/O.
  *
  *
  *****************************************************************************/

#ifndef __MAIN_H
#define __MAIN_H    24122016    

#define FLASH_ADDR _Pragma("location=\"FLASH\"")
/*    Kieu So Nguyen Co Dau    */
typedef  long  int    int32_t;
typedef  int          int16_t;
typedef  char         int8_t;

/*	Kieu So Nguyen Khong Dau */
typedef unsigned long  uint32_t;
typedef unsigned int   uint16_t;
typedef unsigned char  uint8_t;
/*	Kieu So Thuc */
typedef   float            float32_t;

/******************************************************************************
  COMPILER LIB - COMPILER LIB - COMPILER LIB - COMPILER LIB - COMPILER LIB
******************************************************************************/
#include "stdio.h"
#include "string.h"
/******************************************************************************
  FW LIB - FW LIB - FW LIB - FW LIB - FW LIB - FW LIB - FW LIB - FW LIB - FW LIB 
******************************************************************************/
#include "defstm8s.h"
#include "stm8s_clk.h"
#include "stm8s_iwdg.h"
#include "stm8s_tim2.h"
#include "stm8s_tim4.h"
#include "stm8s_flash.h"
/******************************************************************************
  USERSTM8 LIB - USERSTM8 LIB - USERSTM8 LIB - USERSTM8 LIB - USERSTM8 LIB 
******************************************************************************/
#include "user_delay.h"
#include "user_gpio.h"
#include "user_iwdg.h"
#include "user_timer.h"
#include "user_eeprom.h"
/******************************************************************************
  USER LIB - USER LIB - USER LIB - USER LIB - USER LIB - USER LIB - USER LIB
******************************************************************************/
#include "process.h"
/******************************************************************************
DEFINE GPIO - DEFINE GPIO - DEFINE GPIO - DEFINE GPIO - DEFINE GPIO - DEFINE GPIO
******************************************************************************/
//______________________I/O A ____________________________
//______________________I/O B ____________________________
//______________________I/O C ____________________________
//______________________I/O D ____________________________
//______________________I/O E ____________________________
//______________________I/O F ____________________________
//______________________I/O G ____________________________
//______________________I/O H ____________________________
//______________________I/O I ____________________________
/******************************************************************************
USER DEFINE - USER DEFINE - USER DEFINE - USER DEFINE - USER DEFINE - USER DEFI 
******************************************************************************/
#define LED7_A			PORTB_7
#define LED7_B			PORTB_5
#define LED7_C			PORTB_0
#define LED7_D			PORTB_2
#define LED7_E			PORTB_3
#define LED7_F			PORTB_6
#define LED7_G			PORTB_4
#define LED7_DP			PORTB_1

#define CTR1			PORTC_1
#define CTR2			PORTE_5
#define CTR3			PORTE_6
#define CTR4			PORTE_7
#define CTRP			PORTC_2

#define BT_SET			PIND_7
#define BT_UP			PIND_6
#define BT_DOWN			PIND_5
#define BT_OK			PIND_4

#define BUZZ			PORTA_5
#define RELAY			PORTA_6

#define LED_ON			0
#define LED_OFF			1

#define BUZZ_ON			1
#define BUZZ_OFF		0

#define PRESS			0
#define	NOT_PRESS		1

#define RELAY_ON		0
#define RELAY_OFF		1

#endif

/*------------------------------KET THUC FILE-------------------------------
 _________________________________MCA Team__________________________________*/  