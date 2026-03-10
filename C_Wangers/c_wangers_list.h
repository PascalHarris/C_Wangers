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
 @brief Inserts a new node at the beginning of the doubly linked list.
 @discussion Allocates a new node, copies the data, and updates head and previous pointers. The new node becomes the new head.
 @param head_ref A pointer to the head pointer of the list.
 @param new_data A pointer to the data to be stored in the new node.
 @param data_size The size of the data in bytes.
 */
void push(Node** head_ref, void *new_data, size_t data_size);

/**
 @brief Inserts a new node before a specified node in the list.
 @discussion Allocates and inserts a new node before `next_node`. Updates surrounding pointers and head if necessary.
 @param head_ref A pointer to the head pointer of the list.
 @param next_node The node before which the new node will be inserted.
 @param new_data A pointer to the data to be stored in the new node.
 @param data_size The size of the data in bytes.
 @return `true` if insertion succeeds, `false` if `next_node` is NULL.
 */
bool insert_before(struct Node** head_ref, struct Node* next_node, void *new_data, size_t data_size);

/**
 @brief Inserts a new node after a specified node in the list.
 @discussion Allocates and inserts a new node after `prev_node`. Updates surrounding pointers accordingly.
 @param prev_node The node after which the new node will be inserted.
 @param new_data A pointer to the data to be stored in the new node.
 @param data_size The size of the data in bytes.
 @return `true` if insertion succeeds, `false` if `prev_node` is NULL.
 */
bool insert_after(struct Node* prev_node, void *new_data, size_t data_size);

/**
 @brief Appends a new node to the end of the doubly linked list.
 @discussion Allocates a new node and traverses to the end of the list to append it. Updates previous pointer.
 @param head_ref A pointer to the head pointer of the list.
 @param new_data A pointer to the data to be stored in the new node.
 @param data_size The size of the data in bytes.
 */
void append(struct Node** head_ref, void *new_data, size_t data_size);

/**
 @brief Deletes a specified node from the doubly linked list.
 @discussion Updates surrounding pointers and frees the node. If the node is the head, updates the head pointer.
 @param head_ref A pointer to the head pointer of the list.
 @param del The node to be deleted.
 @return `true` if deletion succeeds, `false` if `head_ref` or `del` is NULL.
 */
bool delete_node(struct Node** head_ref, struct Node* del);

/**
 @brief Deletes the node at a specified index in the list.
 @discussion Traverses to the node at the given index and deletes it using `delete_node`.
 @param head_ref A pointer to the head pointer of the list.
 @param index The index of the node to delete (1-based).
 @return `true` if deletion succeeds, `false` if index is invalid or node not found.
 */
bool delete_item_at_index(struct Node** head, int index);

/**
 @brief Retrieves the data pointer of the node at a specified index.
 @discussion Traverses the list and returns the data pointer of the node at the given index.
 @param head The head of the list.
 @param index The index of the node to retrieve (0-based).
 @return A pointer to the data, or NULL if index is out of bounds.
 */
void* get_item_in_list_with_index(Node *head, int index);

/**
 @brief Checks whether a given item exists in the list.
 @discussion Compares each node’s data with the target item using type-specific logic.
 @param head The head of the list.
 @param item A pointer to the item to search for.
 @param type The type of the item (`_INT`, `_FLOAT`, `_STRING`).
 @return `true` if the item is found, `false` otherwise.
 */
bool item_exists_in_list(Node *head, void* item, int type);

/**
 @brief Returns the index of the first occurrence of an item in the list.
 @discussion Compares each node’s data with the target item using type-specific logic. Returns the index of the match.
 @param head The head of the list.
 @param item A pointer to the item to search for.
 @param type The type of the item (`_INT`, `_FLOAT`, `_STRING`).
 @return The index of the item if found, or the list length if not found.
 */
int index_of_item_in_list(Node *head, void* item, int type);

/**
 @brief Counts the number of nodes in the list.
 @discussion Recursively traverses the list and returns the total number of nodes.
 @param head The head of the list.
 @return The number of nodes in the list.
 */
int number_of_items_in_list(Node *head);

#endif
