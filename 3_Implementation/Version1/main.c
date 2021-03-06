/**
 * @file main.c
 * @author Faadil Batcha
 * @brief 
 * @version 0.1
 * @date 2021-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef UBRR0L
#define UBRR0L UBRRL
#define UBRR0H UBRRH
#define UCSR0A UCSRA
#define UCSR0B UCSRB
#define UCSR0C UCSRC
#define UCSR0A UCSRA
#define UDRE0  UDRE
#define UDR0   UDR
#define RXC0   RXC
#define TXC0   TXC
#define RXCIE0 RXCIE
#define RXEN0  RXEN
#define TXEN0  TXEN
#define UCSZ00 UCSZ0
#define UDRIE0 UDRIE
#endif

#include <avr/io.h>
//#include <water_level_indication.h>
//#include <util/delay.h>
//#include "uart.h"
/*#include <HCSR04.h>
#include <NXTBluetooth.h>

#define ULTRASONIC_TRIG_PIN 12
#define ULTRASONIC_ECHO_PIN 13
HCSR04 ultrasonic(ULTRASONIC_TRIG_PIN,ULTRASONIC_ECHO_PIN);
NXTBluetooth bluetooth(2, 3, 1, 10);*/

void USARTInit(uint16_t );
char USARTReadChar();
void USARTWriteChar(char *);
unsigned char mydata;
int i,duration=0,distance=0;
//String message; //Bluetooth message

void USARTInit(uint16_t ubrr_value)
{
    //Set Baud rate
    UBRR0L = ubrr_value;
    UBRR0H = (ubrr_value>>8)&0X00ff ;
    UCSR0C = (1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);

    //Enable Transmitter Receiver
    UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}

char USARTReadChar()
{
    //Wait until data is available
    while(!(UCSR0A & (1<<RXC0)))
    {
        //DO NOTHING
    }
    return UDR0;
}

void USARTWriteChar(char *data)
{
    //wait until transmitter is ready
    while (!(UCSR0A & (1<<UDRE0)))
    {
        //DO  NOTHING
    }
    //TO WRITE THE DATA TO USART BUFFER
    UDR0 = *data;
}


int main(void)
{
    USARTInit(103);
    DDRB |= (1<<DDB2)|(1<<DDB3)|(1<<DDB0)|(1<<DDB4); /*B2&B3 are indicator LED's,B0 is Ultrasonic Sensor Trigger O/P,B4 Motor load*/
    DDRB &= ~(1<<DDB1);                              /*B1 is Ultrasonic Sensor Echo I/P*/
    while(1){
        USARTInit(103);
        //duration = pulseIn(PORTB1,HIGH);
        //distance = (duration/2)*2.91;
        mydata = USARTReadChar();
        if (mydata=='A')
        {
            PORTB |=(1<<PORTB2);
            PORTB |=(1<<PORTB4);
            PORTB &=~(1<<PORTB3);
            /*for (i = 0; i < 10; i += 1) {                                    //FOR BLUETOOTH MESSAGE TRANSFER
                message = String("Motor Turned On " + String(i + 1) + "!");
            }*/
            USARTWriteChar("Water level's low, Motor Turned On");/*If interfaced, Message will be sent to Connected Bluetooth user*/
            //bluetooth.write(message, i);
            //Loads
        }
        else if(mydata=='B'){
            PORTB &=~(1<<PORTB2);
            PORTB &=~(1<<PORTB4);
            PORTB |=(1<<PORTB3);
            /*for (i = 0; i < 10; i += 1) {                                    //FOR BLUETOOTH MESSAGE TRANSFER
                message = String("Motor Turned Off " + String(i + 1) + "!");
            }*/
            USARTWriteChar("Water level's High, Motor Turned Off");/*If interfaced, Message will be sent to Connected Bluetooth user*/
            //bluetooth.write(message, i);    /*note that messages can't exede 59 characters including the null terminator*/
        }
        //bluetooth.update();
    }
    return 0;
}

