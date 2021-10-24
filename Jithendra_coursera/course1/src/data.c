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
 * @file data.c
 * @brief Converion of data from string to integer and vice-versa
 *
 * This implementation file provides function definition for data
 * type conversions. 
 * 
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "data.h"
#include "memory.h"
#include <stdint.h>
#include <stddef.h>

/***********************************************************
 Function Definitions
***********************************************************/

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    uint8_t count = 0;
    uint8_t negative_value = 0;
    uint8_t rem = 0;

    if(data == 0){
        *(ptr) = '0';
	count++;
	*(ptr + count) = '\0';
	count++;
    }
    if(data < 0){
        negative_value = 1;
	data = data* - 1;
    }
    while(data != 0){
        rem = data % base;
	*(ptr + count) = rem > 9 ? (rem - 10) + 'a' : rem + '0';
	count++;
	data = data/base;
    }

    if(negative_value){
       *(ptr + count) = '-';
       count++;
    }
    count++;
    *(ptr + count) = '\0';

    my_reverse(ptr, (count -1));

    return count;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
     int32_t num = 0;
     uint8_t negative_value = 0;
     if(*ptr == '-'){
       negative_value = 1;
       ptr++;
       digits--;
     }
     digits--;
     for(int i = 0; i< digits; i++){
         num = num * base + *ptr - '0';
	 ptr++;
     }

     if(negative_value){
         num = -num;
     }

     return num;
}

