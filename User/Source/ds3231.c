/*******************************************************************************
  *Ten Tep          :     ds3231.c
  *Ngay             :     2/3/2017
  *Tac Gia          :     MCA team
  *Cong Ty          :     MCA
  *Webside          :     mca.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Giao tiep vs IC thoi gian thuc DS3231

******************************************************************************/
#include "ds3231.h"

#if (_DS3231_H_ != 232017)
    #error  "Include sai file ds3231.h"
#endif

void ds3231_write_1byte(uint8_t add, uint8_t dat1)
{
    I2CSOFT_Start();
    I2CSOFT_WriteData(0xD0);
    I2CSOFT_WriteData(add);
    I2CSOFT_WriteData(dat1);
    I2CSOFT_Stop();
}


void ds3231_write_3bytes(uint8_t add, uint8_t dat1, uint8_t dat2, uint8_t dat3)
{
    I2CSOFT_Start();
    I2CSOFT_WriteData(0xD0);
    I2CSOFT_WriteData(add);
    I2CSOFT_WriteData(dat1);
    I2CSOFT_WriteData(dat2);
    I2CSOFT_WriteData(dat3);
    I2CSOFT_Stop();
}

void ds3231_write_4bytes(uint8_t add, uint8_t dat1, uint8_t dat2, uint8_t dat3, uint8_t dat4)
{
    I2CSOFT_Start();
    I2CSOFT_WriteData(0xD0);
    I2CSOFT_WriteData(add);
    I2CSOFT_WriteData(dat1);
    I2CSOFT_WriteData(dat2);
    I2CSOFT_WriteData(dat3);
    I2CSOFT_WriteData(dat4);
    I2CSOFT_Stop();
}

uint8_t ds3231_read(uint8_t add)
{
    uint8_t data_buff;
    
    I2CSOFT_Start();
    I2CSOFT_WriteData(0xD0);
    I2CSOFT_WriteData(add);
    I2CSOFT_Start();
    I2CSOFT_WriteData(0xD1);
    data_buff = I2CSOFT_ReadData(1);
    I2CSOFT_Stop();
    
    return data_buff;
}

void ds3231_init(void)
{
    uint8_t tmp;
    
    I2CSOFT_Init();
    tmp = ds1307_read(0x00);
    if(((tmp >>8)& 0x01)) 
    ds3231_write_1byte(0x00, 0x7F);       // Reset bit CH
}
/*__________________________CAI DAT THOI GIAN______________________________*/
void ds3231_set_time(uint8_t hour, uint8_t min, uint8_t sec)
{
    sec = ((sec/10)<<4)|(sec%10);
    min = ((min/10)<<4)|(min%10);
    hour = ((hour/10)<<4)|(hour%10);
    
    ds3231_write_3bytes(0x00, sec, min , hour);
}

void ds3231_set_date(uint8_t day, uint8_t date, uint8_t mon, uint8_t years)
{
    day = ((day/10)<<4)|(day%10);
    date = ((date/10)<<4)|(date%10);
    mon = ((mon/10)<<4)|(mon%10);
    years = ((years/10)<<4)|(years%10);
    
    ds3231_write_4bytes(0x03, day, date, mon, years);
}


/*____________________________DOC THOI GIAN________________________________*/
void ds3231_get_time(uint8_t *hour, uint8_t *min, uint8_t *sec)
{
    *sec = ds3231_read(0x00);
    *min = ds3231_read(0x01);
    *hour = ds3231_read(0x02);
    
    *sec = ((*sec >>4)*10) + (*sec & 0x0F);
    *min = ((*min >>4)*10) + (*min & 0x0F);
    *hour = ((*hour >>4)*10) + (*hour & 0x0F);
}

void ds3231_get_date(uint8_t *date, uint8_t *mon, uint8_t *years)
{
    *date = ds3231_read(0x04);
    *mon = ds3231_read(0x05);
    *years = ds3231_read(0x06);
    
    *date = ((*date >>4)*10) + (*date & 0x0F);
    *mon = ((*mon >>4)*10) + (*mon & 0x0F);
    *years = ((*years >>4)*10) + (*years & 0x0F);
}

uint8_t ds3231_get_day(void)
{
    uint8_t day;
    day = ds3231_read(0x03);
    day = ((day >>4)*10) + (day & 0x0F);
}
/*______________________________DOC NHIET DO________________________________*/
uint8_t ds3231_get_temp(void)
{
    uint8_t data_buff, data_integer;
    
    data_buff = ds3231_read(0x0E);
    data_buff |= 0x20;
    ds3231_write_1byte(0x0E, data_buff);
    data_integer = ds3231_read(0x11);

    return data_integer;
}

/*------------------------------KET THUC FILE-----------------------------------
 _________________________________MCA Team_____________________________________*/