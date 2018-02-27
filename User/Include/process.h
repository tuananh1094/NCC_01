#ifndef _PROCESS_H_
#define _PROCESS_H_

#include "main.h"

void __mainProcess(void);

void led7Out(u8 dat);
void led7Scan(u8 num);
void led7OutTime(u8 hour, u8 min);

u8 set(void);
u8 up(void);
u8 down(void);
u8 ok(void);

void buzz(u8 bip);

void readRom(void);

#endif