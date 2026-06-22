#include "my_stack.h"
#include <stdlib.h>

static int _ll_peek(StackLL *self) { return self->top ? self->top->value : -1; }

static void _ll_push(StackLL *self, int value) {
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->value = value;
    node->next  = NULL;
    if (self->length == 0) { self->top = node; self->bottom = node; }
    else { node->next = self->top; self->top = node; }
    self->length++;
}

static void _ll_pop(StackLL *self) {
    if (!self->top) return;
    StackNode *old = self->top;
    self->top = self->top->next;
    free(old);
    self->length--;
}

static void _ll_destroy(StackLL *self) {
    StackNode *cur = self->top;
    while (cur) { StackNode *next = cur->next; free(cur); cur = next; }
    free(self);
}

StackLL *StackLL_new() {
    StackLL *s  = (StackLL *)malloc(sizeof(StackLL));
    s->top      = NULL;
    s->bottom   = NULL;
    s->length   = 0;
    s->peek     = _ll_peek;
    s->push     = _ll_push;
    s->pop      = _ll_pop;
    s->destroy  = _ll_destroy;
    return s;
}

static int _a_peek(StackA *self) {
    return self->length ? self->data->get(self->data, self->length - 1) : -1;
}

static void _a_push(StackA *self, int value) {
    self->data->append(self->data, value);
    self->length++;
}

static void _a_pop(StackA *self) {
    if (self->length > 0) { self->data->pop(self->data); self->length--; }
}

static void _a_destroy(StackA *self) {
    self->data->destroy(self->data);
    free(self);
}

StackA *StackA_new() {
    StackA *s  = (StackA *)malloc(sizeof(StackA));
    s->data    = Array_new();
    s->length  = 0;
    s->peek    = _a_peek;
    s->push    = _a_push;
    s->pop     = _a_pop;
    s->destroy = _a_destroy;
    return s;
}
