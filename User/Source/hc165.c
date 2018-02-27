/*****************************************************************************
  *Ten Tep          :     hc165.c
  *Ngay             :     20/2/2017
  *Tac Gia          :     MCA team
  *Cong Ty          :     MCA
  *Webside          :     mca.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Lap trinh giao tiep vs cac ngoai vi
                          74HC165 mo rong ngo vao
#define HC165_CLK       PORTG_0
#define HC165_SH_LD     PORTC_7
#define HC165_DATA      PINC_6
  ******************************************************************************/
#include "hc165.h"

#if (_HC165_H_ !=  20022017)
    #error "include sai file hc165.h"
#endif

void hc165_init(void)
{
    HC165_CLK = 0;
    HC165_SH_LD = 1;
}

uint8_t hc165_read_data(void)
{
    uint8_t data_buff = 0,i;
    HC165_SH_LD = 0;
    delay_ms(5);
    HC165_SH_LD = 1;
    delay_ms(5);
    for(i=0;i<8;i++)
    {
        data_buff<<= 1;
        data_buff |= HC165_DATA;
 
        HC165_CLK = 1;
        delay_ms(5);
        HC165_CLK = 0;;
    }  
    return data_buff;
}
/*------------------------------KET THUC FILE-------------------------------
 _________________________________MCA Team__________________________________*/ 