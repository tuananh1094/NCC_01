/*****************************************************************************
  *Ten Tep          :     ds1302.c
  *Ngay             :     21/2/2017
  *Tac Gia          :     MCA team
  *Cong Ty          :     MCA
  *Webside          :     mca.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Lap trinh giao tiep vs cac ngoai vi
                          DS1302
// Phai dinh nghia cac chan ket noi vao file main.h
#define DS1302_CLK      PORTD_4
#define DS1302_CE       PORTD_3
#define DS1302_OUT      PORTD_2
#define DS1302_IN       PIND_2
  ******************************************************************************/
#include "ds1302.h"

#if (_DS1302_H_!= 21022017 )
    #error  "Include sai file ds1302.h"
#endif

void ds1302_init(void)
{
    uint8_t temp;
   
    DS1302_CLK = 0;
    DS1302_CE  = 0;
    ds1302_write_data(0x8E,0);
    //ds1302_write_data(0x90,0xa4);
    temp = ds1302_read_data(0x81);
    if(temp & 0x80 == 1)
    ds1302_write_data(0x80,0);
}

void serial_write(uint8_t dat)
{
    uint8_t i;
    
    DDRD_2 = 1;
    for(i=0; i<8; i++)
    {
        if((dat & 0x01)== 0x01)
            DS1302_OUT = 1;  
        else
            DS1302_OUT = 0;   
        dat >>= 1;
        DS1302_CLK = 1;
        //delay_us(5);
        DS1302_CLK = 0;
        //delay_us(5);
    }
}

uint8_t serial_read(void)
{
    uint8_t i, data_buff;
    
    DDRD_2 = 0;
    for(i=0; i<8; i++)
    {
       data_buff |= DS1302_IN << i;
       DS1302_CLK = 1; 
       delay_us(2);
       DS1302_CLK = 0;
       delay_us(2);   
       
    }
    DDRD_2 = 1;
    return data_buff;
}

void ds1302_write_data(uint8_t add, uint8_t data)
{    
    data = ((data/10)<<4)|(data%10);
    DS1302_CE = 1;
    serial_write(add);
    serial_write(data);
    DS1302_CE = 0;
}

uint8_t ds1302_read_data(uint8_t add)
{
    uint8_t dat_buff;
    
    DS1302_CE = 1;
    serial_write(add);
    dat_buff = serial_read();
    DS1302_CE = 0;
    
    dat_buff = ((dat_buff>>4)*10) + (dat_buff& 0x0F);
    return dat_buff;
}
/*_______________________Ham cai dat thoi gian__________________________*/
void ds1302_set_time(uint8_t hour, uint8_t min, uint8_t sec, uint8_t date, uint8_t mon, uint8_t year, uint8_t day)
{
    ds1302_write_data(0x84,hour);
    ds1302_write_data(0x82,min);
    ds1302_write_data(0x80,sec);
    
    ds1302_write_data(0x86,date);
    ds1302_write_data(0x88,mon);
    ds1302_write_data(0x8C,year);
    
    ds1302_write_data(0x8A,day);
}

/*__________________________Ham doc thoi gian___________________________*/
void ds1302_get_time(uint8_t *hour, uint8_t *min, uint8_t *sec, uint8_t *date, uint8_t *mon, uint8_t *year, uint8_t *day)
{
    uint8_t temp;
    
    temp = ds1302_read_data(0x85);
    ds1302_write_data(0xC0,temp);
    *hour = ds1302_read_data(0xC1);
        
        
    temp = ds1302_read_data(0x83);
    ds1302_write_data(0xC2,temp);    
    *min = ds1302_read_data(0xC3);
    
    temp = ds1302_read_data(0x81);
    ds1302_write_data(0xC4,temp);
    *sec = ds1302_read_data(0xC5);
    
    temp = ds1302_read_data(0x87);
    ds1302_write_data(0xC6,temp);
    *date = ds1302_read_data(0xC7);
    
    temp = ds1302_read_data(0x89);
    ds1302_write_data(0xC8,temp);
    *mon = ds1302_read_data(0xC9);
    
    temp = ds1302_read_data(0x8D);
    ds1302_write_data(0xCA,temp);
    *year = ds1302_read_data(0xCB);
    
    temp = ds1302_read_data(0x8B);
    ds1302_write_data(0xCC,temp);
    *day = ds1302_read_data(0xCD);
}

/*------------------------------KET THUC FILE-------------------------------
 _________________________________MCA Team__________________________________*/ 