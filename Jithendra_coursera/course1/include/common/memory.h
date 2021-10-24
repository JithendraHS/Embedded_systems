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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Move data from source mem address to dest mem address
 *
 * The behavior should handle overlap of source and destination. 
 * Copy should occur, with no data corruption. 
 *
 * @param src  Pointer to the source mem address
 * @param dst  Pointer to the destination mem address
 * @param length size of the mem data under move
 *
 * @return pointer to the destination address
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copy data from source mem address to dest mem address
 *
 * The behavior should handle overlap of source and destination.
 * Copy should occur, with no data corruption.
 *
 * @param src  Pointer to the source mem address
 * @param dst  Pointer to the destination mem address
 * @param length size of the mem data under copy
 *
 * @return pointer to the destination address
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);


/**
 * @brief Set all locations of given length memory to a given value.
 * 
 * The behavior should handle overlap of source.
 * Copy should occur, with no data corruption.
 *
 * @param src  Pointer to the source mem address
 * @param length size of the mem data under set
 * @param value The value to be assign to the memory
 *
 * @return pointer to the source address
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Set all locations of given length memory to a zero.
 *
 * The behavior should handle overlap of source.
 * Copy should occur, with no data corruption.
 *
 * @param src  Pointer to the source mem address
 * @param length size of the mem data under set
 *
 * @return pointer to the source address
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverse the order of all bytes
 *
 * The behavior should handle overlap of source.
 * Copy should occur, with no data corruption.
 *
 * @param src  Pointer to the source addresss
 * @param length size of the mem data under reverse process
 *
 * @return pointer to the source address
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Reserve memory of given length
 *
 * The behavior should handle overlap of source.
 * Copy should occur, with no data corruption.
 *
 * @param length size of the mem need to reserve
 * 
 * @return pointer to memory allocated
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Reset the memory
 *
 * The behavior should handle overlap of source.
 * Copy should occur, with no data corruption.
 *
 * @param src Pointer to the source address
 *
 * @return NULL
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
