/*******************************************************************************
  *Ten Tep          :     user_spi.c
  *Ngay             :     25/01/2016
  *Tac Gia          :     MCA team
  *Cong Ty          :     MCA
  *Webside          :     mca.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     
  ******************************************************************************/
#include "user_spi.h"

/*******************************************************************************
Noi Dung    :   Ham khoi tao SPI
Tham Bien   :   Khong.
Tra Ve      :   Khong.
*******************************************************************************/
void spi_init(void)
{
    SPI_DeInit();   
    SPI_Init(SPI_FIRSTBIT_MSB,SPI_BAUDRATEPRESCALER_64,SPI_MODE_MASTER,SPI_CLOCKPOLARITY_LOW,SPI_CLOCKPHASE_1EDGE,SPI_DATADIRECTION_2LINES_FULLDUPLEX,SPI_NSS_HARD,0x00);
    //SPI_CalculateCRCCmd(DISABLE);
    SPI_Cmd(ENABLE);
}

/*******************************************************************************
Noi Dung    :   Ham gui 1 Byte qua SPI
Tham Bien   :   dat
Tra Ve      :   Khong.
*******************************************************************************/
void spi_write(uint8_t dat)
{
    SPI_SendData(dat);
    while(SPI_GetFlagStatus(SPI_FLAG_TXE)==0);
    SPI_ClearFlag(SPI_FLAG_TXE);
}

/*******************************************************************************
Noi Dung    :   Ham nhan 1 byte qua SPI
Tham Bien   :   Khong.
Tra Ve      :   data_buff.
*******************************************************************************/
uint8_t spi_read()
{
    uint8_t data_buff;
    while(SPI_GetFlagStatus(SPI_FLAG_RXNE)== 0);
    data_buff = SPI_ReceiveData();
    SPI_ClearFlag(SPI_FLAG_RXNE);
    return data_buff;
}
/*------------------------------KET THUC FILE-------------------------------
 _________________________________MCA Team__________________________________*/ 
