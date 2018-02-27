/*****************************************************************************
  *Ten Tep          :     dht11.c
  *Ngay             :     1/3/2017
  *Tac Gia          :     MCA team
  *Cong Ty          :     MCA
  *Webside          :     mca.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Do nhiet do, do am bang cam bien DHT11
===> phai dinh nghia cac chan ket noi voi IC vao file main.h
#define DHT11_DATA_IN      PINE_5
#define DHT11_DATA_OUT     PORTE_5
#define DHT11_DATA_DDR     DDRE_5
******************************************************************************/
#include "dht11.h"

#if (_DHT11_H_ != 132017)
    #error  "Include sai file dht11.h"
#endif

uint8_t dht11_read_temp_humi(float32_t *temp, float32_t *humi)
{
    uint8_t i, j, checksum, data_buff[5];
    
    DHT11_DATA_DDR = 1;     // Output
    DHT11_DATA_OUT = 0;
    delay_ms(18);
    DHT11_DATA_DDR = 0;     // Input
    delay_us(40);
    
    if(DHT11_DATA_IN) return ERROR;       //WAIT DHT11 RESPONSE
    else while(DHT11_DATA_IN == 0);
    
    if(!DHT11_DATA_IN) return ERROR;      //WAIT DHT11 RESPONSE 
    else while(DHT11_DATA_IN == 1);     
    
    for(i=0; i<5; i++)                    // READ DATA FROM DHT11  
    {
        for(j=0; j<8; j++)
        {
            while(DHT11_DATA_IN == 0);
            delay_us(50);
            if(DHT11_DATA_IN == 1)
            {
                data_buff[i] |= 0x01;
                while (DHT11_DATA_IN == 1);
            }
            data_buff[i] <<= 1;
        }
    }
        
    checksum = data_buff[0] + data_buff[1] + data_buff[2] + data_buff[3];    // Checksum
    if(checksum != data_buff[4])    return ERROR;
    
    //READ TEMPERATURE AND HUMIDITY AND STORED IN 'temp' AND 'humi' VARIABLES
    humi = (float32_t)data_buff[1]/256 + data_buff[0];
    temp = (float32_t)data_buff[3]/256 + data_buff[2];
}
