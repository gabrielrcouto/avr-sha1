#include<avr/io.h>
#include<string.h>
#include<stdlib.h>
#include"sha1.c"

void UART_transmit(unsigned char data);
int testSha1();

int main(void)
{
    unsigned char i,message[]="g";
    DDRD=0x00;
    PORTD=0xFF;
    UCSRA=0;
    UCSRB=1<<TXEN; // transmitter enable
    UCSRC=1<<URSEL | 1<<UCSZ1 | 1<<UCSZ0; // 8 data bit, a stop, none parity
    UBRRH=0;
    UBRRL=25; // With this value, the ATMEGA8 using the internal oscillator at 8MHz get a 2400 baud rate
    
    while(1)
    {
        for (i = 0; i < 10; i++) {
            testSha1();
        }
        
        for(i=0;message[i];i++)
        {
            UART_transmit(message[i]);
        }
    } // while(1) end
} // main() end


void UART_transmit(unsigned char data)
{
    while(!(UCSRA & (1<<UDRE)));
    UDR=data;
}

/*
 *  Define patterns for testing
 */
#define TEST1   "abc"

int testSha1()
{
    SHA1Context sha;
    int err;
    uint8_t Message_Digest[20];
    
    err = SHA1Reset(&sha);
    err = SHA1Input(&sha, (const unsigned char *) TEST1, strlen(TEST1));
    err = SHA1Result(&sha, Message_Digest);

    return 0;
}