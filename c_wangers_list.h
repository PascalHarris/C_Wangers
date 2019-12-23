//
//  c_wangers_list.h
//
//  Created by Pascal Harris on 03/06/2008.
//  Copyright (c) 2008 Pascal Harris, 45RPM Software. All rights reserved.
//

#ifndef CLIST_H_
#define CLIST_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/** Definition of types for storage */
#define _INT 1
#define _STRING 2
#define _FLOAT 3
#define _LONG 4

typedef struct Node {
    void *data;
    struct Node *prev;
    struct Node *next;
} Node;

/**
 * push:
 * @head_ref: (type Node**) A pointer reference to the first entry in a linked list.
 * @new_data: (type void*) A pointer to the data which will be added into the linked list.
 * @data_size: (type size_t) The size of the data which will be added into the linked list.
 *
 * @head_ref must not be %NULL.
 * @new_data must not be %NULL.
 * @data_size must not be %NULL.
 *
 * Pushes a data item onto the start of a linked list
 *
 * Returns: void
 */
void push(Node** head_ref, void *new_data, size_t data_size);

/**
 * insert_before:
 * @head_ref: (type Node**) A pointer reference to the first entry in a linked list.
 * @next_node: (type Node*) A pointer to the entry in a linked list that the data will be inserted before.
 * @new_data: (type void*) A pointer to the data which will be added into the linked list.
 * @data_size: (type size_t) The size of the data which will be added into the linked list.
 *
 * @head_ref must not be %NULL.
 * @next_node must not be %NULL.
 * @new_data must not be %NULL.
 * @data_size must not be %NULL.
 *
 * Inserts a data item into a linked list before the given node. Returns false if the insert fails.
 *
 * Returns: bool
 */
bool insert_before(struct Node** head_ref, struct Node* next_node, void *new_data, size_t data_size);

/**
 * insert_after:
 * @prev_node: (type Node*) A pointer to the entry in a linked list that the data will be inserted after.
 * @new_data: (type void*) A pointer to the data which will be added into the linked list.
 * @data_size: (type size_t) The size of the data which will be added into the linked list.
 *
 * @prev_node must not be %NULL.
 * @new_data must not be %NULL.
 * @data_size must not be %NULL.
 *
 * Inserts a data item into a linked list after the given node. Returns false if the insert fails.
 *
 * Returns: bool
 */
bool insert_after(struct Node* prev_node, void *new_data, size_t data_size);

/**
 * append:
 * @head_ref: (type Node**) A pointer reference to the first entry in a linked list.
 * @data: (type void*) A pointer to the data which will be added into the linked list.
 * @data_size: (type size_t) The size of the data which will be added into the linked list.
 *
 * @head_ref must not be %NULL.
 * @new_data must not be %NULL.
 * @data_size must not be %NULL.
 *
 * Appends a data item onto the end of a linked list
 *
 * Returns: void
 */
void append(struct Node** head_ref, void *new_data, size_t data_size);

bool delete_node(struct Node** head_ref, struct Node* del);

bool delete_item_at_index(struct Node** head, int index);

void* get_item_in_list_with_index(Node *head, int index);

bool item_exists_in_list(Node *head, void* item, int type);

int index_of_item_in_list(Node *head, void* item, int type);

int number_of_items_in_list(Node *head);

#endif
