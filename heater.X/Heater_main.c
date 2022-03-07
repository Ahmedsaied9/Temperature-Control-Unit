/* 
 * File:   Heatermain.c
 * Author: dell1
 *
 * Created on April 10, 2021, 4:44 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "conf.h"
#include "adc.h"
#include "KeyPad_4_4.h"
#include "lcd.h"
#include "timer.h"

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
    
    char c = -1;
  while(1)
   {
        
    
    
    
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
   
   for(int i=0;i<2;i++)
   {
       
       while(c==-1)
       {
           c=Get_Key();
       }
       
       if((c>=0 && c<=15))
       {
           input[i]=key_num(c);
           LCDPutChar('5');
       }
          
   }
   __delay_ms(1000);
       
       for(int j=0;j<2;j++)
   {  if(j==0)
       
       tens = (input[j]-48)*10;
      else
       
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
     
      int result=adc_init();
      LCDPutCmd(LCD_CLEAR);
      sprintf(txt, "Current Temp=%d", result);
      LCDPutStr(txt);
      LCDGoto(0,1);
      sprintf(txt_new, "Desired Temp=%d", set_point);
   
      LCDPutStr(txt_new);
      __delay_ms(1600);
        
        
        
          if(result>set_point)
          {  LATC4=0;
               LATC5=1;
               LCDPutCmd(LCD_CLEAR); 
               LCDGoto(0,0);
                LCDPutStr("Fan ON");
                __delay_ms(800);
                
          }
          else if(result<set_point)
          {   //power on the heater
              LATC5=0;
               LATC4=1; 
                LCDPutCmd(LCD_CLEAR); 
               LCDGoto(0,0);
                LCDPutStr("Heater ON");
                __delay_ms(800);
         
          }
                
          else
          {   LATC5=0;
              LATC4=0;
              LCDPutCmd(LCD_CLEAR); 
              LCDGoto(0,0);
                LCDPutStr("Temp as desired");
                __delay_ms(800);
               
                
              //turn off the fan and the heater
          }
      goto retry;
              
      
     
    }
  
  }
    
}
