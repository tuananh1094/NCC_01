/*******************************************************************************
  *Ten Tep          :     one_wire.c
  *Ngay             :     24/2/2017
  *Tac Gia          :     MCA team
  *Cong Ty          :     MCA
  *Webside          :     mca.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     1 Wire Protocol 

Phai dinh nghia chan ket noi vao file main.h
#define ONEWIRE_DATA_IN     PINC_1
#define ONEWIRE_DATA_OUT    PORTC_1
#define ONEWIRE_DDR         DDRC_1
//Phai config CRC2_1 = 0 de tranh do chip
  ******************************************************************************/
#include "one_wire.h"

#if (_ONE_WIRE_H_ != 24022017)
    #error ("Include sai file one_wire.h")
#endif

uint8_t onewire_reset(void)
{   
    uint8_t temp;
    ONEWIRE_DDR = 1;        //Output
    ONEWIRE_DATA_OUT = 0;
    delay_us(480);
	
	//ONE_DATA_OUT = 1;   
    ONEWIRE_DDR = 0;        //Input
    delay_us(70);
    temp = ONEWIRE_DATA_IN;
    delay_us(410);
    
    return temp;            // = 0 : success, 1: not success 
}

void onewire_write_0(void)
{
    ONEWIRE_DDR = 1;        //Output
    ONEWIRE_DATA_OUT = 0;
    delay_us(60);
    ONEWIRE_DDR = 0;        //Input
    delay_us(10);
}

void onewire_write_1(void)
{
    ONEWIRE_DDR = 1;        //Output
    ONEWIRE_DATA_OUT = 0;
    delay_us(6);
    ONEWIRE_DDR = 0;        //Input
    delay_us(64);
}

void onewire_write_byte(uint8_t dat)
{
    uint8_t i;
    for(i=0; i<8; i++)
    {
        if(dat & 0x01) onewire_write_1();
        else    onewire_write_0();
        dat >>= 1;
    }
}

uint8_t onewire_read_byte(void)
{
    uint8_t data_buff, i, temp;
    for(i=0; i< 8; i++)
    {
        data_buff >>= 1;
        
        ONEWIRE_DDR = 1;        //Output
        ONEWIRE_DATA_OUT = 0;
        delay_us(6);
        ONEWIRE_DDR = 0;        //Input
        delay_us(9);
        temp = ONEWIRE_DATA_IN;
        delay_us(55);
        if(temp)
        data_buff |= 0x80;    
    }
    return data_buff;
}
/*------------------------------KET THUC FILE-----------------------------------
 _________________________________MCA Team_____________________________________*/  