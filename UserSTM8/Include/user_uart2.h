/*****************************************************************************
  *Ten Tep          :     user_uart2.h
  *Ngay             :     23/01/2017
  *Tac Gia          :     MCA Team
  *Cong Ty          :     MCA
  *Webside          :     mca.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Dinh nghia su dung chuc nang uart
  ******************************************************************************/

#ifndef _USER_UART2_H_
#define _USER_UART2_H_  23012017

#include "main.h"

void uart2_init(void);
void uart2_putchar(uint8_t chr);
void uart2_puts(uint8_t *s);
uint8_t uart2_getchar(void);

#endif

/*------------------------------KET THUC FILE-------------------------------
 _________________________________MCA Team__________________________________*/ 