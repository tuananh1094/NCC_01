/*****************************************************************************
  *Ten Tep          :     user_gpio.c
  *Ngay             :     24/12/2015
  *Tac Gia          :     MCA Team
  *Cong Ty          :     MCA
  *Webside          :     mca.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Dinh nghia cac ham cau hinh GPIO trong STM8
  ******************************************************************************/

#include "user_gpio.h"
#if (__USER_GPIO_H!=24122016)  
    #error "Include Sai #File user_gpio.h"
#endif

/***************************************************************
|________|_______|_______|_____________|
|        |       |       |             |
|REGISTER| MODE  | VALUE | DESCRIPTION |
|________|_______|_______|_____________|
|        |       |       |             |
|  CR1   | Input |   0   |  Floating   |
|________|_______|_______|_____________|
|        |       |       |             |
|  CR1   | Input |   1   |   Pull Up   |
|________|_______|_______|_____________|
|        |       |       |             |
|  CR1   |Output |   0   |  Open Drain |
|________|_______|_______|_____________|
|        |       |       |             |
|  CR1   |Output |   1   |  Push Pull  |
|________|_______|_______|_____________|
|________|_______|_______|_____________|
|        |       |       |             |
|  CR2   | Input |   0   |  Interrupt  |
|        |       |       |   Disable   | 
|________|_______|_______|_____________|
|        |       |       |             |
|  CR2   | Input |   1   |   Interrupt |
|        |       |       |    Enable   |
|________|_______|_______|_____________|
|        |       |       |             |
|  CR2   |Output |   0   | OutPut 2Mhz |
|________|_______|_______|_____________|
|        |       |       |             |
|  CR2   |Output |   1   |OutPut 10Mhz |
|________|_______|_______|_____________|
***************************************************************/

/*******************************************************************************
Noi Dung    :   Cau hinh GPIO.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
*******************************************************************************/

void GPIO_Configuration(void)
{
/********************************* PORTA *************************************/
    DDRA=0x00;
    CRA1=0xFF;
    CRA2=0x00;
    PORTA=0xFF;
/********************************* PORTB *************************************/
    DDRB=0xFF;
    CRB1=0xFF;
    CRB2=0xFF;  
    PORTB=0xFF;
/********************************* PORTC *************************************/
    DDRC=0xFF;
    CRC1=0xFF;
    CRC2=0xFF;
    PORTC=0xFF;
/********************************* PORTD *************************************/
    DDRD=0xFF;
    CRD1=0xFF;
    CRD2=0xFF;
    PORTD=0xEF;
/********************************* PORTE *************************************/
    DDRE=0xFF;
    CRE1=0xFF;
    CRE2=0xFF;
    PORTE=0xFF;
/********************************* PORTF *************************************/
/********************************* PORTG *************************************/
    DDRG=0xFF;
    CRG1=0xFF;
    CRG2=0xFF;
    PORTG=0xFF;
}

/*------------------------------KET THUC FILE-------------------------------
 _________________________________MCA Team__________________________________*/