//
//  c_wangers_sort.h
//
//  Created by Pascal Harris on 03/06/2008.
//  Copyright (c) 2008 Pascal Harris, 45RPM Software. All rights reserved.
//

#ifndef CSORT_H_
#define CSORT_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"c_wangers_list.h"

/**
 @brief Swaps the contents of two memory blocks of equal length.
 @discussion Performs a byte-wise swap of two memory regions. Assumes both blocks are at least `len` bytes and valid. Commonly used for swapping primitive values or strings of equal length.
 @param a A pointer to the first memory block.
 @param b A pointer to the second memory block.
 @param len The number of bytes to swap.
 */
void swap(void *a, void *b, size_t len);

/**
 @brief Sorts a doubly linked list using bubble sort.
 @discussion Performs an in-place bubble sort on the list starting at `start`. Supports sorting of integers, floats, and strings based on the `type` parameter. Uses `swap` to exchange node data. For strings, the swap length is based on the longer of the two compared strings.
 @param start A pointer to the head of the list.
 @param type The data type of the list items (`_INT`, `_FLOAT`, `_STRING`).
 @return `true` if sorting was performed, `false` if the list is empty.
 */
bool bubbleSort(struct Node *start, int type);

#endif
