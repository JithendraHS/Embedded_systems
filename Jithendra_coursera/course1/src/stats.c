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
 * @file stats.c
 * @brief Performs analysis on given data set
 *
 * @author Jithendra H.S
 * @date Sept 29, 2021
 *
 */



#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

/*
int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  
  print_statistics(test, SIZE);
 return 0; 
}
*/

/* Add other Implementation File Code Here */
void print_statistics(unsigned char array[], unsigned int array_size){
  /* sorting array for further use */
  sort_array(array, array_size);
  PRINTF("Maximum value from array of values is %d\n", find_maximum(array, array_size));
  PRINTF("Minimum value from array of values is %d\n", find_minimum(array, array_size));
  PRINTF("Mean value from array of values is %d\n", find_mean(array, array_size));
  PRINTF("Median value from array of values is %d\n", find_median(array, array_size));
  PRINTF("Sorted array is: ");
  print_array(array, array_size);
   
   return;
}

void print_array(unsigned char array[], unsigned int array_size){
#if defined(VERBOSE)	
   int index = 0;
   PRINTF("index  array_value\n");
   for(index = 0; index < array_size; index++){
       PRINTF("%20d%8s%d\n", index, "", array[index]);
   }
#endif
   return;
}

unsigned char find_median(unsigned char array[], unsigned int array_size){
    /* Array size is even */
    if((array_size % 2)==0){
        return (array[((array_size - 1)/2)+1] + array[(array_size - 1)/2])/2;
    }
    return array[(array_size-1)/2];
}

unsigned char find_mean(unsigned char array[], unsigned int array_size){
   int total = 0;
   for(int i=0; i<array_size; i++){
     total += array[i];
   }
   return (unsigned char)(total/array_size);
}

unsigned char find_maximum(unsigned char array[], unsigned int array_size){
    return array[0];
}

unsigned char find_minimum(unsigned char array[], unsigned int array_size){
    return array[array_size -1];
}

void sort_array(unsigned char array[], unsigned int array_size){
    for(int i=0; i < array_size-1; i++){
       for(int j=i; j<array_size; j++){
          if(array[i] < array[j]){
             int temp = array[i];
             array[i] = array[j];
             array[j] = temp;
          }
       } 
    }
    return;
}
