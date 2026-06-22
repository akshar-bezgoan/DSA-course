#ifndef MY_ARRAY_H
#define MY_ARRAY_H

#include <stdlib.h>

typedef struct Array Array;

struct Array {
    /* data */
    int *data;
    int  length;
    int  capacity;

    /* methods */
    int  (*get)    (Array *self, int index);
    void (*append) (Array *self, int item);
    int  (*pop)    (Array *self);
    void (*delete) (Array *self, int index);
    void (*destroy)(Array *self);
};

Array *Array_new();

#endif
