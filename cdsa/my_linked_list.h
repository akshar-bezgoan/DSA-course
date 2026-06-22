#ifndef MY_LINKED_LIST_H
#define MY_LINKED_LIST_H

typedef struct SLLNode {
    int             value;
    struct SLLNode *next;
} SLLNode;

typedef struct LinkedList LinkedList;

struct LinkedList {
    SLLNode *head;
    SLLNode *tail;
    int      length;

    void        (*append) (LinkedList *self, int value);
    void        (*prepend)(LinkedList *self, int value);
    void        (*insert) (LinkedList *self, int index, int value);
    void        (*remove) (LinkedList *self, int index);
    void        (*print)  (LinkedList *self);
    LinkedList *(*reverse)(LinkedList *self);
    void        (*destroy)(LinkedList *self);
};

LinkedList *LinkedList_new(int value);

#endif
