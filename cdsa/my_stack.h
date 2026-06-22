#ifndef MY_STACK_H
#define MY_STACK_H

#include "my_array.h"

typedef struct StackNode {
    int              value;
    struct StackNode *next;
} StackNode;

typedef struct StackLL StackLL;

struct StackLL {
    StackNode *top;
    StackNode *bottom;
    int        length;

    int  (*peek)   (StackLL *self);
    void (*push)   (StackLL *self, int value);
    void (*pop)    (StackLL *self);
    void (*destroy)(StackLL *self);
};

StackLL *StackLL_new();

typedef struct StackA StackA;

struct StackA {
    Array *data;
    int    length;

    int  (*peek)   (StackA *self);
    void (*push)   (StackA *self, int value);
    void (*pop)    (StackA *self);
    void (*destroy)(StackA *self);
};

StackA *StackA_new();

#endif
