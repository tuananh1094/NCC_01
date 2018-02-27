/*****************************************************************************
  *Ten Tep          :     ds1302.h
  *Ngay             :     21/2/2017
  *Tac Gia          :     MCA team
  *Cong Ty          :     MCA
  *Webside          :     mca.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Lap trinh giao tiep vs cac ngoai vi
                          DS1302

  ******************************************************************************/
#ifndef _DS1302_H_
#define _DS1302_H_      21022017

#include "main.h"

void ds1302_init(void);

void serial_write(uint8_t dat);
uint8_t serial_read(void);

uint8_t ds1302_read_data(uint8_t add);
void ds1302_write_data(uint8_t add, uint8_t data);
/*_______________________Ham cai dat thoi gian__________________________*/
void ds1302_set_time(uint8_t hour, uint8_t min, uint8_t sec, uint8_t date, 
                     uint8_t mon, uint8_t year, uint8_t day);
/*__________________________Ham doc thoi gian___________________________*/
void ds1302_get_time(uint8_t *hour, uint8_t *min, uint8_t *sec, uint8_t *date, 
                     uint8_t *mon, uint8_t *year, uint8_t *day);
#endif

/*------------------------------KET THUC FILE-------------------------------
 _________________________________MCA Team__________________________________*/ 