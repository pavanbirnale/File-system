#include <xc.h>
#define _XTAL_FREQ 48000000        // Define the Clock frequency in Hz
#define baud_rate 9600             // Define baud rate

void UART_Init();
void UART_Tx(unsigned char x);
void UART_SendString(const unsigned char *str);

void main() {
    UART_Init();                   // Initialize UART
    UART_SendString("Hello, UART!"); // Send test string

    while (1);                     // Infinite loop to keep main active
}

void UART_Init() {
    // Calculate Baud_val based on defined baud_rate
    int Baud_val = (int)((_XTAL_FREQ / (64.0 * baud_rate)) - 1);

    TRISC6 = 0;                    // TX pin set as output
    TRISC7 = 1;                    // RX pin set as input
    SPBRG = Baud_val;              // Set baud rate
    TXSTA = 0x20;                  // Enable transmitter
    RCSTA = 0x90;                  // Enable serial port & receiver
}

void UART_Tx(unsigned char x) {
    while (!TXIF);                 // Wait until TX buffer is ready
    TXREG = x;                     // Load data into TX register
}

void UART_SendString(const unsigned char *str) {
    while (*str) {
        UART_Tx(*str++);           // Transmit each character in the string
    }
}
