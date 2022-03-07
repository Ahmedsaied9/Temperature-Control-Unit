/* 
 * File:   newmain.c
 * Author: dell1
 *
 * Created on April 10, 2021, 4:44 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "conf.h"
#include "adc.h"
//#include "keypad.h"
#include "KeyPad_4_4.h"
//#include "eeprom.h"
#include "lcd.h"
#include "timer.h"
//void __interrupt() adc();
int tens,units;
int set_point;
int temp ;
char txt[16];
char txt_new[16];
int sum=0;
int avg_temp=0;
int num_read=0;
int min_temp=40;
    int max_temp=99;
    
     int result_1 = 0;
      int result_2 = 0;
      int result_3 = 0;
int main() {
   
    TRISD = 0x00;
    TRISC4=0;
    TRISC5=0;
   LCD_Initialize();
   KeyPad_Init();
    /*TMR0IE=1;// timer interrupt enable bit
    GIE=1;//globalinterrupt
    IPEN=0;//disable priority
    PEIE=1;//
    T0CS=0; //
    
    T08BIT=0;//16 bit
    
   
    PSA=0;//prescalar
    T0CONbits.T0PS=7;//256 prescalar
   
    TMR0ON=0;
   TMR0IF=0;//initialize flag to zero
   TMR0=7813;//setting timer to begin the count from 57723 to reach overflow after 1 sec
    */
    char c = -1;
  while(1)
   {
        
    
    //timer_init();
     
    //LATB = 0x00;
    
    LATC4=0;
    LATC5=0;
    
    char input[2];
    exit:
    
    for(int k = 0 ; k<2; k++)
    {input[k]=0;}
    
int    invalid = 0;
   LCDGoto(0,0);
   LCDPutStr("enter your temp");
   __delay_ms(800); 
   LCDPutCmd(LCD_CLEAR);
   //WRITE(0x0000,0);
   //WRITE(0x0001,0);
   for(int i=0;i<2;i++)
   {
       //keypad_fun(i);
       while(c==-1)
       {
           c=Get_Key();
       }
       //while((input[i]>='0' && input[i]<='9'))
       //{)
       if((c>=0 && c<=15))
       {
           input[i]=key_num(c);
           LCDPutChar('5');
       }
           //}
           /*if(input[i]==-1)
       {   LCDPutCmd(LCD_CLEAR);
           __delay_ms(800); 
           LCDPutStr("Invalid Input");
           __delay_ms(800); 
           LCDPutCmd(LCD_CLEAR);
           goto exit;
       }*/
   }
   __delay_ms(1000);
       
       for(int j=0;j<2;j++)
   {  if(j==0)
       //tens=READ( 0x00+j)*10;
       tens = (input[j]-48)*10;
      else
       //units=READ(0x00+j);
          units = input[j]-48;
   }
  set_point=tens+units;
  if(set_point < min_temp || set_point > max_temp)
  {
      LCDGoto(0,0);
   LCDPutCmd(LCD_CLEAR);
      LCDPutStr("OUT of range");
   __delay_ms(800);
   LCDPutCmd(LCD_CLEAR);
   
  }
  else{
      retry:
       result_1 = 0;
       result_2 = 0;
       result_3 = 0;
      LCDGoto(0,0);
      //ADIF=1;
      int result=adc_init();
      LCDPutCmd(LCD_CLEAR);
      sprintf(txt, "Current Temp=%d", result);
      LCDPutStr(txt);
      LCDGoto(0,1);
      sprintf(txt_new, "Desired Temp=%d", set_point);
   
      LCDPutStr(txt_new);
      __delay_ms(1600);
        
        
         //LCDPutCmd(LCD_CLEAR);
      
         //TMR0ON=1;
         /*if(num_read==9)
      {   avg_temp=0;
          avg_temp= READ(0x0010) / 10 ;*/
          if(result>set_point)
          {  LATC4=0;
               LATC5=1;
               LCDPutCmd(LCD_CLEAR); 
               LCDGoto(0,0);
                LCDPutStr("Fan ON");
                __delay_ms(800);
                //LCDPutCmd(LCD_CLEAR);
                //while(result_1>set_point)
                  //  result_1=adc_init();
          }
          else if(result<set_point)
          {   //power on the heater
              LATC5=0;
               LATC4=1; 
                LCDPutCmd(LCD_CLEAR); 
               LCDGoto(0,0);
                LCDPutStr("Heater ON");
                __delay_ms(800);
          //      LCDPutCmd(LCD_CLEAR);
          //while(result_2<set_point)
            //  result_2=adc_init();
          }
                
          else
          {   LATC5=0;
              LATC4=0;
              LCDPutCmd(LCD_CLEAR); 
              LCDGoto(0,0);
                LCDPutStr("Temp as desired");
                __delay_ms(800);
                //while(result_3==set_point)
                  //  result_3=adc_init();
                
              //turn off the fan and the heater
          }
      goto retry;
              
      
      //}
      //else {goto retry;}
         
    }
  
  }
    
  

           

}


  /* void __interrupt() timer(){
   
    if(TMR0IF){
      temp=adc_init();
        sum=sum+temp;
    WRITE(0x0010,sum);
    int temp=adc_init();
      sprintf(txt_new, "t=%d", temp);
      LCDPutStr(txt_new);
      __delay_ms(800);
    num_read++;
    TMR0IF=0;  
    TMR0=7813;
    
    
    }
    
   }
    */
    
    




