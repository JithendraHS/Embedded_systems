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
 * @file stats.h
 * @brief Performs analysis on given data set
 *
 * @author Jithendra H.S
 * @date Sept 29, 2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief Prints the statistics of an array including minimum, maximum,
 *        mean and median
 *
 * @param array Array of data consider for analysis
 * @param array_size Size of the data array
 *
 * @return NULL
 */
void print_statistics(unsigned char array[], unsigned int array_size);

/**
 * @brief Prints the given array elements
 *
 * @param array Array of data consider for analysis
 * @param array_size Size of the data array
 *
 * @return NULL
 */
void print_array(unsigned char array[], unsigned int array_size);

/**
 * @brief Find the median for array of data
 *
 * @param array Array of data consider for analysis
 * @param array_size Size of the data array
 *
 * @return median Median value from the array data
 */
unsigned char find_median(unsigned char array[], unsigned int array_size);

/**
 * @brief Find the mean for array of data
 *
 * @param array Array of data consider for analysis
 * @param array_size Size of the data array
 *
 * @return mean Mean value from the array data
 */
unsigned char find_mean(unsigned char array[], unsigned int array_size);

/**
 * @brief Find the maximum value present in array of data
 *
 * @param array Array of data consider for analysis
 * @param array_size Size of the data array
 *
 * @return maximum Maximum value in array data
 */
unsigned char find_maximum(unsigned char array[], unsigned int array_size);

/**
 * @brief Find the minimun value present in array of data
 *
 * @param array Array of data consider for analysis
 * @param array_size Size of the data array
 *
 * @return minimum Minimum value in array data
 */
unsigned char find_minimum(unsigned char array[], unsigned int array_size);

/**
 * @brief Sort the array of data from higher to lower
 *
 * @param array Array of data consider for analysis
 * @param array_size Size of the data array
 *
 * @return array Sorted array
 */
unsigned char sort_array(unsigned char array[], unsigned int array_size);

#endif /* __STATS_H__ */
