#include "my_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

static SLLNode *_node(int value) {
    SLLNode *n = (SLLNode *)malloc(sizeof(SLLNode));
    n->value = value; n->next = NULL;
    return n;
}

static SLLNode *_traverse(LinkedList *self, int index) {
    SLLNode *cur = self->head;
    for (int i = 0; i < index; i++) cur = cur->next;
    return cur;
}

static void _append(LinkedList *self, int value) {
    SLLNode *node    = _node(value);
    self->tail->next = node;
    self->tail       = node;
    self->length++;
}

static void _prepend(LinkedList *self, int value) {
    SLLNode *node = _node(value);
    node->next    = self->head;
    self->head    = node;
    self->length++;
}

static void _insert(LinkedList *self, int index, int value) {
    if (index >= self->length) { _append(self, value); return; }
    SLLNode *node   = _node(value);
    SLLNode *leader = _traverse(self, index - 1);
    node->next      = leader->next;
    leader->next    = node;
    self->length++;
}

static void _remove(LinkedList *self, int index) {
    if (index >= self->length) {
        SLLNode *leader = _traverse(self, self->length - 2);
        free(leader->next);
        leader->next = NULL;
        self->tail   = leader;
    } else {
        SLLNode *leader = _traverse(self, index - 1);
        SLLNode *target = leader->next;
        leader->next    = target->next;
        free(target);
    }
    self->length--;
}

static void _print(LinkedList *self) {
    SLLNode *cur = self->head;
    printf("[");
    while (cur) { printf("%d", cur->value); if (cur->next) printf(", "); cur = cur->next; }
    printf("]\n");
}

static void _destroy(LinkedList *self) {
    SLLNode *cur = self->head;
    while (cur) { SLLNode *next = cur->next; free(cur); cur = next; }
    free(self);
}

LinkedList *LinkedList_new(int value);

static LinkedList *_reverse(LinkedList *self) {
    LinkedList *rev = LinkedList_new(self->head->value);
    SLLNode    *cur = self->head->next;
    while (cur) { rev->prepend(rev, cur->value); cur = cur->next; }
    return rev;
}

static void _wire(LinkedList *l) {
    l->append  = _append;
    l->prepend = _prepend;
    l->insert  = _insert;
    l->remove  = _remove;
    l->print   = _print;
    l->reverse = _reverse;
    l->destroy = _destroy;
}

LinkedList *LinkedList_new(int value) {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    SLLNode    *node = _node(value);
    list->head   = node;
    list->tail   = node;
    list->length = 1;
    _wire(list);
    return list;
}
