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
 * swap:
 * @a: (type void*) The first pointer to be swapped.
 * @b: (type void*) The second pointer to be swapped.
 * @len: (type size_t) The size of the data being pointed to.
 *
 * @a must not be %NULL.
 * @b must not be %NULL.
 * @len must not be %NULL.
 *
 * Swaps the first and second pointers. If the pointers point to a string (char*) then
 * the strings _must_ be exactly the same length.
 *
 * Returns: void
 */
void swap(void *a, void *b, size_t len);

/**
 * bubbleSort:
 * @start: (type Node*) A pointer to the first entry in a linked list.
 * @type: (type int) The type of data in the linked list - _INT, _FLOAT, _STRING.
 *
 * @start must not be %NULL.
 * @type must not be %NULL.
 *
 * Bubble sorts the contents of a linked list. Returns false if the sort fails.
 *
 * Returns: bool
 */
bool bubbleSort(struct Node *start, int type);

#endif
