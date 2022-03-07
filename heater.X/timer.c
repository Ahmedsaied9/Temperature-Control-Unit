#include "timer.h"
#include "conf.h"
void timer_init(){
    TMR0IE=1;// timer interrupt enable bit
    GIE=1;//globalinterrupt
    IPEN=0;//disable priority
    PEIE=1;//
    T0CS=0; //
    TMR0ON=1;
    T08BIT=0;//16 bit
    
   
    PSA=0;//prescalar
    T0CONbits.T0PS=7;//256 prescalar
   
    
   TMR0IF=0;//initialize flag to zero
   TMR0=7813;//setting timer to begin the count from 57723 to reach overflow after 1 sec
   //TMR0H=1E;
 
}
//Time of over flow = 4*prescaler*(2^(16 or 8)- TMR0)/(Fosc)
// we want to save sensed value every 1 sec and to consider the average of the last 10 sensed values (which means every 10 sec) 
// so we need to begin count from 57723