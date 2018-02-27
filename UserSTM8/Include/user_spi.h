/*******************************************************************************
  *Ten Tep          :     user_spi.h
  *Ngay             :     25/01/2016
  *Tac Gia          :     MCA team
  *Cong Ty          :     MCA
  *Webside          :     mca.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     
  ******************************************************************************/
#ifndef _USER_SPI_H_
#define _USER_SPI_H_

#include "main.h"

void spi_init(void);
void spi_write(uint8_t dat);
uint8_t spi_read();
#endif
/*------------------------------KET THUC FILE-------------------------------
 _________________________________MCA Team__________________________________*/ 



