/**
 * @file water_level_indication.h
 * @author Faadil Batcha
 * @brief Header file for Water Level Indication with Ultrasonic & Bluetooth sensor operations
 *
 */

#ifndef WATER_LEVEL_INDICATION_H_INCLUDED
#define WATER_LEVEL_INDICATION_H_INCLUDED

/**
* @brief Initialize USART & enable transmitter and receiver
* @param[in] uint16_t 
*/
void USARTInit(uint16_t );

/**
* @brief helps to read a char from the PC
* @return UDR0
*/
char USARTReadChar();

/**
* @brief helps to write a char/sentence to the PC
* @param[in] char *
*/
void USARTWriteChar(char *;

#endif // WATER_LEVEL_INDICATION_H_INCLUDED
