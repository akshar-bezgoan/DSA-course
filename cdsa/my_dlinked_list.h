#ifndef MY_DLINKED_LIST_H
#define MY_DLINKED_LIST_H

typedef struct DLLNode {
    int             value;
    struct DLLNode *prev;
    struct DLLNode *next;
} DLLNode;

typedef struct DLinkedList DLinkedList;

struct DLinkedList {
    /* data */
    DLLNode *head;
    DLLNode *tail;
    int      length;

    /* methods */
    void (*append) (DLinkedList *self, int value);
    void (*prepend)(DLinkedList *self, int value);
    void (*insert) (DLinkedList *self, int index, int value);
    void (*remove) (DLinkedList *self, int index);
    void (*print)  (DLinkedList *self);
    void (*destroy)(DLinkedList *self);
};

DLinkedList *DLinkedList_new(int value);

#endif
