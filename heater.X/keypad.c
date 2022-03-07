#include "keypad.h"

void keypad_fun(int x){
    
 
   TRISB = 0x0F;
   int y = 0;

    
   



    //while (1) {
        
        LATB=0b10000000;
        __delay_ms(100);
        if(PORTBbits.RB3==1){
            
            LCDPutChar('1');
            
            WRITE(0x0000+x,7);
            while(PORTBbits.RB3);
        y++; 
        }
      
        else if(PORTBbits.RB2==1){
            
            LCDPutChar('2');
            WRITE(0x0000+x,8);
            while(PORTBbits.RB2);
        y++;        
       // x=8; 
        } 
    
        else if(PORTBbits.RB1==1){
             
            LCDPutChar('3');
            WRITE(0x0000+x,9);
            while(PORTBbits.RB1);
        y++;
            //x=9; 
        }
        
    
     else if(PORTBbits.RB0==1){
          
            LCDPutStr("Invalid Input");
            __delay_ms(800);
            invalid++;
             LCDPutCmd(LCD_CLEAR);
            while(PORTBbits.RB0);
            y++;
         }
        
    
    
     LATB=0b01000000;
     __delay_ms(100);
        if(PORTBbits.RB3==1){
             
            LCDPutChar('4');
            WRITE(0x0000+x,4);
            while(PORTBbits.RB3);
          y++;
            // x=4;
        }
      
        else if(PORTBbits.RB2==1){
             
            LCDPutChar('5');
            WRITE(0x0000+x,5);
            while(PORTBbits.RB2);
            y++;
            //x=5;  
         } 
    
        else if(PORTBbits.RB1==1){
          
            LCDPutChar('6');
            WRITE(0x0000+x,6);
            while(PORTBbits.RB1);
             y++;
            //x=6; 
        }
        
    
     else if(PORTBbits.RB0==1){
           
            LCDPutStr("Invalid Input");
            __delay_ms(800);
            invalid++;
             LCDPutCmd(LCD_CLEAR);
            while(PORTBbits.RB0);
            y++;
         }
     LATB=0b00100000;
    __delay_ms(100);
        if(PORTBbits.RB3==1){
            
            LCDPutChar('7');
            WRITE(0x0000+x,1);
            while(PORTBbits.RB3);
        y++;
            //x=1; 
        }
      
        else if(PORTBbits.RB2==1){
            
            LCDPutChar('8');
            WRITE(0x0000+x,2);
            while(PORTBbits.RB2);
            y++;
            //x=2; 
         } 
    
        else if(PORTBbits.RB1==1){
             
            LCDPutChar('9');
            WRITE(0x0000+x,3);
            while(PORTBbits.RB1);
             y++;
            //x=3; 
        }
        
    
     else if(PORTBbits.RB0==1){
            
           LCDPutStr("Invalid Input");
            __delay_ms(800);
             LCDPutCmd(LCD_CLEAR);
            invalid++;
            while(PORTBbits.RB0);
            y++;
     }
    
     LATB=0b00010000;
     __delay_ms(100);
        if(PORTBbits.RB3==1){
            
            LCDPutStr("Invalid Input");
            __delay_ms(800);
             LCDPutCmd(LCD_CLEAR);
            invalid++;
           y++; 
            while(PORTBbits.RB3);
           
            // x=100;
        }
      
        else if(PORTBbits.RB2==1){
             
            LCDPutChar('0');
            WRITE(0x0000+x,0);
            y++;
            while(PORTBbits.RB2);
                
         } 
    
        else if(PORTBbits.RB1==1){
            
            LCDPutStr("Invalid Input");
            __delay_ms(800);
             LCDPutCmd(LCD_CLEAR);
            invalid++;
            y++;
            while(PORTBbits.RB1);
            
         }
        
    
     else if(PORTBbits.RB0==1){
            
            LCDPutStr("Invalid Input");
            __delay_ms(800);
             LCDPutCmd(LCD_CLEAR);
            invalid++;
            y++;
            while(PORTBbits.RB0);
         }
    

 

    // if(x!=1000){return x;}
     
   if(y)
       return ;
    }

//} 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //while(1)
    
  /*if(LATB==1)
    {
        if(PORTBbits.RB4)
        {   LCDPutChar('7');
        
        WRITE(0x0000+x,7);
        while(PORTBbits.RB4);
        
        }
        else if(PORTBbits.RB5)
        {LCDPutChar('8');
          
        WRITE(0x0000+x,8);
        while(PORTBbits.RB5);
        }
        else if(PORTBbits.RB6)
        {LCDPutChar('9');
        
        WRITE(0x0000+x,9);  
        while(PORTBbits.RB5);
        }
       
    
        else if(PORTBbits.RB7)
        {LCDPutChar('/');
           
        LCDPutCmd(LCD_CLEAR);
        
        LCDPutStr("ERROR");
        __delay_ms(200);
        while(PORTBbits.RB7);
        }
        
    
    }
    if(LATB==2)
    {
    
    if(PORTBbits.RB4)
    {  LCDPutChar('4');
          
      WRITE(0x0000+x,4);  
      while(PORTBbits.RB4);
    }  
    else if(PORTBbits.RB5)
    { LCDPutChar('5');
      WRITE(0x0000+x,5);     
        while(PORTBbits.RB5);
    }  
    else if(PORTBbits.RB6)
    {  LCDPutChar('6');
      
       WRITE(0x0000+x,6);
       while(PORTBbits.RB6);
    }   
        
    
    else if(PORTBbits.RB7)
    { LCDPutChar('*');
      __delay_ms(100);    
        
      LCDPutCmd(LCD_CLEAR);
      LCDPutStr("ERROR");  
      __delay_ms(100);  
    
    while(PORTBbits.RB7);
    
    }
    
    } 
    if(LATB==4){
    
    if(PORTBbits.RB4)
    {     LCDPutChar('1');
         WRITE(0x0000+x,1);  
        while(PORTBbits.RB4);
    }   
    else if(PORTBbits.RB5)
    {   LCDPutChar('2');
           
        WRITE(0x0000+x,2);
        while(PORTBbits.RB5);
    }   
    else if(PORTBbits.RB6)
    {  LCDPutChar('3');
        WRITE(0x0000+x,3);   
        
        while(PORTBbits.RB6);
    }   
    
    else if(PORTBbits.RB7)
    {   LCDPutChar('-');
           
    __delay_ms(1000);
        
    LCDPutCmd(LCD_CLEAR);
    LCDPutStr("ERROR");
    __delay_ms(1000);
    while(PORTBbits.RB7);
    }
    }
     if(LATB==8)
     {
    
          if(PORTBbits.RB4)
          {LCDPutChar('O');
          __delay_ms(1000); 
          LCDPutCmd(LCD_CLEAR);
          LCDPutStr("ERROR");
          __delay_ms(1000);
          while(PORTBbits.RB4);
          }
          else if(PORTBbits.RB5)
          {LCDPutChar('0');
           WRITE(0x0000+x,0);
        
        while(PORTBbits.RB5);
          }
          else  if(PORTBbits.RB6)
          {LCDPutChar('=');
          __delay_ms(1000);
          LCDPutCmd(LCD_CLEAR);
          LCDPutStr("ERROR");
          __delay_ms(1000);
        while(PORTBbits.RB6);
          }
    
          else if(PORTBbits.RB7)
          {LCDPutChar('+');
           __delay_ms(1000);
          WRITE(0x0000+x,"+");
           LCDPutCmd(LCD_CLEAR);
           LCDPutStr("ERROR");
           __delay_ms(1000);
          while(PORTBbits.RB7);
          }    
        
     } 
    //return 0; }
 
*/
