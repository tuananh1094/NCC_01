/*****************************************************************************
  *Ten Tep          :     cd4094.c
  *Ngay             :     20/2/2017
  *Tac Gia          :     MCA team
  *Cong Ty          :     MCA
  *Webside          :     mca.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Lap trinh giao tiep vs cac ngoai vi
                          CD4094
===> phai dinh nghia cac chan ket noi voi IC vao file main.h
#define CD4094_OE       PORTC_5
#define CD4094_STROBE   PORTC_4
#define CD4094_DATA     PORTC_3
#define CD4094_CLK      PORTC_2
  ******************************************************************************/
#include "cd4094.h"

#if (_CD4094_H_ !=  20022017)
    #error "include sai file cd4094.h"
#endif

void cd4094_init(void)
{
    CD4094_DATA = 0;
    CD4094_OE   = 0;
    CD4094_STROBE = 0;
    CD4094_CLK  = 0;
}
void cd4094_write_data(uint8_t data)
{   
    uint8_t i;
    CD4094_STROBE = 1;
    CD4094_OE = 1;
    for(i=0; i<8; i++)
    {
        CD4094_DATA = data & 0x01;
        data >>= 1;
        CD4094_CLK = 1;
        delay_us(1);
        CD4094_CLK = 0;
    } 
}

/*------------------------------KET THUC FILE-------------------------------
 _________________________________MCA Team__________________________________*/ 

