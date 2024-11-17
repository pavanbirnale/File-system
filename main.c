#include <xc.h>
#include "lcd.h"
#include "ADC.h"
void main() {
    display_manager();
    display("Wecome TO ADC",0);
    __delay_ms(1000);
    display(ADC(0),1);
    while (1);
}
