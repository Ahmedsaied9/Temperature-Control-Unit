#include "KeyPad_4_4.h"

void KeyPad_Init(void) {
    TRISB = 0xF0;
    LATB = 0xFF;
}

char Get_Key(void) {
  
      LATB = 0xFF;
        char Key = -1;
    for (char r = 0; r < 4; r++) {
        LATB &= ~(1 << r);
        for (char c = 0; c < 4; c++) {
            if (!(PORTB & (1 << (c + 4)))) {
                Key = r * 4 + c;
                while (!(PORTB & (1 << (c + 4))));
            }
        }
        __delay_ms(200);
        LATB |= (1 << r);
    }
        
           return Key;
 
}

char key_num(char k) {
    switch (k) {
        case 0: return '7';
            break;
        case 1: return '8';
            break;
        case 2: return '9';
            break;
        case 3: return '/';
            break;
        case 4: return '4';
            break;
        case 5: return '5';
            break;
        case 6: return '6';
            break;
        case 7: return '*';
            break;
        case 8: return '1';
            break;
        case 9: return '2';
            break;
        case 10: return '3';
            break;
        case 11: return '-';
            break;
        case 12: return 'c';
            break;
        case 13: return '0';
            break;
        case 14: return '=';
            break;
        case 15: return '+';
            break;
    }
}