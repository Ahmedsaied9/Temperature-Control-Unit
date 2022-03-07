/* 
 * File:   eeprom.c
 * Author: dell1
 *
 * Created on September 6, 2019, 5:27 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "eeprom.h"
/*
 * 
 */
int READ(int x){

    EEADR=x;
    EEPGD=0;
    CFGS=0;
    RD=1;
    
    return EEDATA;

}
void WRITE(int y,int m){
    EEADR=y;
    EEDATA=m;
    CFGS=0;
    EEPGD=0;
    WREN=1;
    GIE=0;
    EECON2=0X55;
    EECON2=0XAA;
    WR=1;
    GIE=1;
    WREN=0;
    
    
    
    



}
