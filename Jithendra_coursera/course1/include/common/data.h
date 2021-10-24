/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief Contains declaration of functions for some data
 *        manipulation
 *
 * This header file provides an abstraction of some very 
 * basic data manipulation. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include <stdint.h>
#include <stddef.h>

#define BASE_16 16
#define BASE_10 10
#ifndef __DATA_H__
#define __DATA_H__


/**
 * @brief Convert data from a standard integer type into
 *        an ASCII string
 *
 * This function should be able to support bases 2 to 16 
 * by specifying the integer value of the base you wish to 
 * convert to (base). Copy the converted character string to 
 * the uint8_t* pointer passed in as a parameter (ptr).
 *
 * @param data  data value that want convert from interger to 
 *              ASCII string
 * @param ptr holds the converted data
 * @param base Maximum base of the data
 *
 * @return pointer to converted string
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Convert data from an ASCII string to interger
 *
 * This function should be able to convert data from an ASCII 
 * string to interger.
 *
 * @param ptr holds the string data converted to be integer
 * @param digits This holds converted interger value
 * @param base Maximum base of the interger
 *
 * @return pointer to converted interger
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif
