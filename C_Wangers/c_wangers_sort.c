//
// Created by Pascal Harris LC on 20/12/2019.
//

#include "c_wangers_sort.h"

void swap(void *a, void *b, size_t len) { // strings must be the same length
    unsigned char *p = a, *q = b, tmp;
    for (size_t i = 0; i != len; ++i) {
        tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
    }
}

bool bubbleSort(struct Node *start, int type) {
    bool swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;
    size_t size;

    if (start == NULL) {
        return false;
    }

    do {
        swapped = false;
        ptr1 = start;

        while (ptr1->next != lptr) {
            if (type == _STRING) {
                size_t left = strlen((char*)ptr1->data), right = strlen((char*)ptr1->next->data);
                size = left>right?left:right;
            } else {
                size = sizeof(ptr1->data);
            }

            if ( (type == _INT && (*(int*)ptr1->data > *(int*)ptr1->next->data)) ||
                 (type == _FLOAT && (*(float*)ptr1->data > *(float*)ptr1->next->data)) ||
                 (type == _STRING && (strcmp((char*)ptr1->data, (char*)ptr1->next->data) > 0)) ) {
                swap(ptr1->data, ptr1->next->data, size);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return true;
}
