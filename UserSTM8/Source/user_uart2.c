/*****************************************************************************
  *Ten Tep          :     user_uart2.c
  *Ngay             :     23/01/2017
  *Tac Gia          :     MCA Team
  *Cong Ty          :     MCA
  *Webside          :     mca.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     
  ******************************************************************************/

#include "user_uart2.h"

#if (_USER_UART2_H_ != 23012017)
    #error "Include sai file user_uart2.h"
#endif
/*******************************************************************************
Noi Dung    :   Ham khoi tao uart
Tham Bien   :   khong.
Tra Ve      :   Khong.
*******************************************************************************/
void uart2_init(void)
{
    UART2_DeInit();
    UART2_Init(9600,UART2_WORDLENGTH_8D,UART2_STOPBITS_1,UART2_PARITY_NO,UART2_SYNCMODE_CLOCK_DISABLE,UART2_MODE_TXRX_ENABLE);
    UART2_Cmd(ENABLE);
}
/*******************************************************************************
Noi Dung    :   Ham gui 1 ky tu qua uart
Tham Bien   :   chr
Tra Ve      :   Khong.
*******************************************************************************/
void uart2_putchar(uint8_t chr)
{
    UART2_SendData8(chr);
    while(UART2_GetFlagStatus(UART2_FLAG_TC)==0);
    UART2_ClearFlag(UART2_FLAG_TC);
}
/*******************************************************************************
Noi Dung    :   Ham gui chuoi ky tu len uart
Tham Bien   :   *s
Tra Ve      :   Khong.
*******************************************************************************/
void uart2_puts(uint8_t *s)
{
    uint8_t n,i;
    n = strlen(s);
    for(i=0;i<n;i++)
    {
        uart2_putchar(s[i]);
    }
}

/*******************************************************************************
Noi Dung    :   Ham nhan 1 ky tu
Tham Bien   :   khong
Tra Ve      :   Data_buff
*******************************************************************************/
uint8_t uart2_getchar(void)
{
    uint8_t Data_buff;
    while(UART2_GetFlagStatus(UART2_FLAG_RXNE) == 0);
    Data_buff = UART2_ReceiveData8();
    UART2_ClearFlag(UART2_FLAG_RXNE);
    return Data_buff;
}


/*------------------------------KET THUC FILE-------------------------------
 _________________________________MCA Team__________________________________*/ 