/*****************************************************************************
  *Ten Tep          :     dht11.h
  *Ngay             :     1/3/2017
  *Tac Gia          :     MCA team
  *Cong Ty          :     MCA
  *Webside          :     mca.vn
  *Phien Ban        :     V1.0
  *Tom Tat          :     Do nhiet do, do am bang cam bien DHT11
===> phai dinh nghia cac chan ket noi voi IC vao file main.h
#define DHT11_DATA_IN      PINE_5
#define DHT11_DATA_OUT     PORTE_5
******************************************************************************/
#ifndef _DHT11_H_
#define _DHT11_H_       132017

#include "main.h"

#define ERROR       0
#define SUCCESS     1

uint8_t dht11_read_temp_humi(float32_t *temp, float32_t *humi);

#endif

/*------------------------------KET THUC FILE-------------------------------
 _________________________________MCA Team__________________________________*/ 

