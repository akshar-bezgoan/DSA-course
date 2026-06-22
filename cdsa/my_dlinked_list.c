#include "my_dlinked_list.h"
#include <stdio.h>
#include <stdlib.h>

static DLLNode *_node(int value) {
    DLLNode *n = (DLLNode *)malloc(sizeof(DLLNode));
    n->value = value; n->prev = NULL; n->next = NULL;
    return n;
}

static DLLNode *_traverse(DLinkedList *self, int index) {
    DLLNode *cur = self->head;
    for (int i = 0; i < index; i++) cur = cur->next;
    return cur;
}

static void _append(DLinkedList *self, int value) {
    DLLNode *node    = _node(value);
    node->prev       = self->tail;
    self->tail->next = node;
    self->tail       = node;
    self->length++;
}

static void _prepend(DLinkedList *self, int value) {
    DLLNode *node    = _node(value);
    node->next       = self->head;
    self->head->prev = node;
    self->head       = node;
    self->length++;
}

static void _insert(DLinkedList *self, int index, int value) {
    if (index >= self->length) { _append(self, value); return; }
    DLLNode *node   = _node(value);
    DLLNode *leader = _traverse(self, index - 1);
    DLLNode *after  = leader->next;
    leader->next    = node;
    node->prev      = leader;
    node->next      = after;
    if (after) after->prev = node;
    self->length++;
}

static void _remove(DLinkedList *self, int index) {
    if (index >= self->length) {
        DLLNode *leader = _traverse(self, self->length - 2);
        free(leader->next);
        leader->next = NULL;
        self->tail   = leader;
    } else {
        DLLNode *leader = _traverse(self, index - 1);
        DLLNode *target = leader->next;
        DLLNode *after  = target->next;
        leader->next    = after;
        if (after) after->prev = leader;
        free(target);
    }
    self->length--;
}

static void _print(DLinkedList *self) {
    DLLNode *cur = self->head;
    printf("[");
    while (cur) { printf("%d", cur->value); if (cur->next) printf(", "); cur = cur->next; }
    printf("]\n");
}

static void _destroy(DLinkedList *self) {
    DLLNode *cur = self->head;
    while (cur) { DLLNode *next = cur->next; free(cur); cur = next; }
    free(self);
}

DLinkedList *DLinkedList_new(int value) {
    DLinkedList *list = (DLinkedList *)malloc(sizeof(DLinkedList));
    DLLNode     *node = _node(value);
    list->head    = node;
    list->tail    = node;
    list->length  = 1;
    list->append  = _append;
    list->prepend = _prepend;
    list->insert  = _insert;
    list->remove  = _remove;
    list->print   = _print;
    list->destroy = _destroy;
    return list;
}
