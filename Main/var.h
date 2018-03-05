/*****************************************************************************
  *Ten Tep          :     var.h
  *Ngay             :     24/12/2016
  *Tac Gia          :     MCA team
  *Cong Ty          :     MCA
  *Webside          :     mca.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Khai bao cac bien toan cuc su dung trong Project
  ******************************************************************************/

#ifndef __VAR_H
#define __VAR_H

u8 flagLed = 0, x = 0, BuffLed[4] = {0xc0, 0xc0, 0xc0, 0xc0};
u8 fontLed[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

u16 count_50ms, countBlink, countSet  = 0;

u16 total; 
u8 hourRam, minRam, sec;

#endif  

/*------------------------------KET THUC FILE-------------------------------
 _________________________________MCA Team__________________________________*/ 