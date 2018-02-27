/*****************************************************************************
  *Ten Tep          :     user_timer.c
  *Ngay             :     08/01/2017
  *Tac Gia          :     MCA team
  *Cong Ty          :     MCA
  *Webside          :     mca.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Dinh nghia cac Timer trong stm8s
  ******************************************************************************/
#include "user_timer.h"
/*________________________________ TIMER1 ___________________________________*/ 
void TIM1_Configuration()
{
    CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER1,ENABLE);// Cho phep su dung nguon clock cho Timer1
    TIM1_TimeBaseInit(15,TIM1_COUNTERMODE_UP,10000,100);  // tao thoi gian 10ms
    TIM1_ARRPreloadConfig(DISABLE);                     // Tat che do autoreload
    TIM1_ITConfig(TIM1_IT_UPDATE,ENABLE);               // Chon su kien ngat update 
    TIM1_Cmd(ENABLE);                                   // cho phep chay Timer1
}

//void TIM1_PWM()
//{
//    TIM1_TimeBaseInit(15,TIM1_COUNTERMODE_UP,PERIOD,0);
//    TIM1_OC1Init(TIM1_OCMODE_PWM1,TIM1_OUTPUTSTATE_ENABLE,TIM1_OUTPUTNSTATE_ENABLE,DUTY,TIM1_OCPOLARITY_HIGH,TIM1_OCNPOLARITY_LOW,TIM1_OCIDLESTATE_SET,TIM1_OCNIDLESTATE_SET);
//    TIM1_Cmd(ENABLE);
//    TIM1_CtrlPWMOutputs(ENABLE);
//}
/*________________________________ TIMER2 ___________________________________*/
void TIM2_Configuration()
{
    CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER2,ENABLE);// Cho phep su dung nguon clock cho Timer2
    TIM2_ARRPreloadConfig(ENABLE);                          // Bat che do Autoreload
    TIM2_TimeBaseInit(TIM2_PRESCALER_16,50000);             // Bo chia 16, thoi gian 50ms
    TIM2_ITConfig(TIM2_IT_UPDATE,ENABLE);                   // Chon su kien ngat update
    TIM2_Cmd(ENABLE);                                       // cho phep chay Timer2
}
/*________________________________ TIMER3 ___________________________________*/ 
void TIM3_Configuration()
{
    CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER3,ENABLE);// Cho phep su dung nguon clock cho Timer3
    TIM3_ARRPreloadConfig(ENABLE);                          // Bat che do Autoreload
    TIM3_TimeBaseInit(TIM3_PRESCALER_16, 50000);            // Bo chia timer 16, thoi gia  50ms
    TIM3_ITConfig(TIM3_IT_UPDATE,ENABLE);                   // Chon su kien ngat update
    TIM3_Cmd(ENABLE);                                       // cho phep chay Timer3
}
/*________________________________ TIMER4 ___________________________________*/ 
void TIM4_Configuration()
{
    CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER4,ENABLE);// Cho phep su dung nguon clock cho Timer4
    TIM4_ARRPreloadConfig(ENABLE);                          // Bat che do Autoreload
    TIM4_TimeBaseInit(TIM4_PRESCALER_128, 125);             // Bo chia timer 128, thoi gia  2ms
    TIM4_ITConfig(TIM4_IT_UPDATE,ENABLE);                   // Chon su kien ngat update
    TIM4_Cmd(ENABLE);                                       // cho phep chay Timer4
}
