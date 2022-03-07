/* 
 * File:   KeyPad_4_4.h
 * Author: Khaled
 *
 * Created on 22 ?????, 2019, 01:08 ?
 */

#ifndef KEYPAD_4_4_H
#define	KEYPAD_4_4_H

#include "conf.h"

//#define KeyPadPortDirection TRISB
//#define KeypadPort LATB

void KeyPad_Init(void);
char Get_Key(void);
char key_num(char k);


#endif	/* KEYPAD_4_4_H */

