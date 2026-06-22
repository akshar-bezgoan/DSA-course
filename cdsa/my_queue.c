#include "my_queue.h"
#include <stdlib.h>

static int _peek(Queue *self) { return self->first ? self->first->value : -1; }

static void _enqueue(Queue *self, int value) {
    QNode *node = (QNode *)malloc(sizeof(QNode));
    node->value = value; node->next = NULL;
    if (self->length == 0) { self->first = node; self->last = node; }
    else { self->last->next = node; self->last = node; }
    self->length++;
}

static void _dequeue(Queue *self) {
    if (!self->length) return;
    if (self->first == self->last) {
        free(self->first); self->first = NULL; self->last = NULL;
    } else {
        QNode *old = self->first;
        self->first = self->first->next;
        free(old);
    }
    self->length--;
}

static void _destroy(Queue *self) {
    QNode *cur = self->first;
    while (cur) { QNode *next = cur->next; free(cur); cur = next; }
    free(self);
}

Queue *Queue_new() {
    Queue *q  = (Queue *)malloc(sizeof(Queue));
    q->first   = NULL;
    q->last    = NULL;
    q->length  = 0;
    q->peek    = _peek;
    q->enqueue = _enqueue;
    q->dequeue = _dequeue;
    q->destroy = _destroy;
    return q;
}
