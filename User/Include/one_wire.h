/*******************************************************************************
  *Ten Tep          :     one_wire.h
  *Ngay             :     24/2/2017
  *Tac Gia          :     MCA team
  *Cong Ty          :     MCA
  *Webside          :     mca.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     1 Wire Protocol 
  ******************************************************************************/

#ifndef _ONE_WIRE_H_
#define _ONE_WIRE_H_     24022017

#include "main.h"

uint8_t onewire_reset(void);
void onewire_write_0(void);
void onewire_write_1(void);

void onewire_write_byte(uint8_t dat);
uint8_t onewire_read_byte(void);

#endif
/*------------------------------KET THUC FILE-----------------------------------
 _________________________________MCA Team_____________________________________*/  