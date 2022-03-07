/* 
 * File:   adc.c
 * Author: dell1
 *
 * Created on April 10, 2021, 4:45 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "adc.h"
#include "lcd.h"
/*
 * 
 */
int  adc_init(){
   GIE = 1;
    //PEIE = 1;
    //IPEN=0;
    //ADIE = 1;
    
   // ADIF=0;
    
    TRISA0=1; //ip port A0
     ANS0 = 1;
    
    ADCON0bits.CHS = 0; //channel 0 for sensor 
    ADCON1bits.VCFG = 0;//voltage is internally by vdd
   
    ADON = 1; 
    ADFM = 1;// Right justify or left justify
    ADCON2bits.ACQT = 0b001; //2 TAD
    ADCON2bits.ADCS = 0b110; //FOSC/64
   while(1){
       ADCON0bits.GO_DONE = 1;
        
        
        while (ADCON0bits.GO_DONE);
        int result0 = ADRES * 5 / 10.23;//convert analog to digital
         ADRES = 0;
        return result0;
   }
    
        
    
    
    
}
