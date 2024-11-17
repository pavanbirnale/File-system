#ifndef LCD_H
#define LCD_H
#include <xc.h>
#define _XTAL_FREQ 8000000
#define rs LATCbits.LATC0   // Assuming you're using PORTC for RS
#define rw LATCbits.LATC1   // Assuming you're using PORTC for RW
#define en LATCbits.LATC2   // Assuming you're using PORTC for EN
#define ldata PORTD         // Assuming you're using PORTD for data lines

// Function prototypes
void lcd_init(void);
void lcd_cmd(unsigned char val);
void lcd_data(unsigned char data);
void lcd_str(const char *str);

#endif /* LCD_H */
