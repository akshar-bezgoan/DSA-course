#ifndef MY_QUEUE_H
#define MY_QUEUE_H

typedef struct QNode {
    int          value;
    struct QNode *next;
} QNode;

typedef struct Queue Queue;

struct Queue {
    QNode *first;
    QNode *last;
    int    length;

    int  (*peek)   (Queue *self);
    void (*enqueue)(Queue *self, int value);
    void (*dequeue)(Queue *self);
    void (*destroy)(Queue *self);
};

Queue *Queue_new();

#endif
