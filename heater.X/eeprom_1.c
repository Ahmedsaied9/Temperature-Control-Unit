#include "eeprom.h"
#include <stdio.h>
#include <stdlib.h>
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
