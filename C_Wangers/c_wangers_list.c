#include "c_wangers_list.h"

void push(Node** head_ref, void *new_data, size_t data_size) {
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data  = calloc(data_size, sizeof(new_data));
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }

    for (int i=0; i<data_size; i++) {
        *(char *)(new_node->data + i) = *(char *)(new_data + i);
    }

    (*head_ref) = new_node;
}

bool insert_before(struct Node** head_ref, struct Node* next_node, void *new_data, size_t data_size) {
    if (next_node == NULL) {
        return false;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = calloc(data_size, sizeof(new_data));
    for (int i=0; i<data_size; i++) {
        *(char *)(new_node->data + i) = *(char *)(new_data + i);
    }

    new_node->prev = next_node->prev;
    next_node->prev = new_node;
    new_node->next = next_node;

    if (new_node->prev != NULL) {
        new_node->prev->next = new_node;
    } else {
        (*head_ref) = new_node;
    }

    return true;
}

bool insert_after(struct Node* prev_node, void *new_data, size_t data_size) {
    if (prev_node == NULL) {
        return false;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = calloc(data_size, sizeof(new_data));
    for (int i=0; i<data_size; i++) {
        *(char *)(new_node->data + i) = *(char *)(new_data + i);
    }

    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }

    return true;
}

void append(struct Node** head_ref, void *new_data, size_t data_size) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data  = calloc(data_size, sizeof(new_data));
    for (int i=0; i<data_size; i++) {
        *(char *)(new_node->data + i) = *(char *)(new_data + i);
    }

    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;

    return;
}

bool delete_node(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL) {
        return false;
    }

    if (*head_ref == del) {
        *head_ref = del->next;
    }

    if (del->next != NULL) {
        del->next->prev = del->prev;
    }

    if (del->prev != NULL) {
        del->prev->next = del->next;
    }

    free(del);
    return true;
}

bool delete_item_at_index(struct Node** head_ref, int index) {
    if (*head_ref == NULL || index <= 0) {
        return false;
    }

    struct Node* current = *head_ref;

    for (int i = 1; current != NULL && i < index; i++) {
        current = current->next;
    }

    if (current == NULL) {
        return false;
    }

    return delete_node(head_ref, current);
}

void* get_item_in_list_with_index(Node *head, int index) {
    int i=0;
    while (head) {
        if (i == index) {
            return head->data;
        }
        head = head->next;
        i++;
    }
    return NULL;
}

bool item_exists_in_list(Node *head, void* item, int type) {
    while (head) {
        if ( (type == _INT && (*(int*)head->data == *(int*)item)) ||
             (type == _FLOAT && (*(float*)head->data == *(float*)item)) ||
             (type == _STRING && (strcmp((char*)head->data, (char*)item) == 0)) ) {
            return true;
        }
        head = head->next;
    }
    return false;
}

int index_of_item_in_list(Node *head, void* item, int type) {
    int i=0;
    while (head) {
        if ( (type == _INT && (*(int*)head->data == *(int*)item)) ||
             (type == _FLOAT && (*(float*)head->data == *(float*)item)) ||
             (type == _STRING && (strcmp((char*)head->data, (char*)item) == 0)) ) {
            return i;
        }
        head = head->next;
        i++;
    }
    return i;
}

int number_of_items_in_list(Node *head) {
    if (head == NULL) {
        return 0;
    }
    return 1 + number_of_items_in_list(head->next);
}
