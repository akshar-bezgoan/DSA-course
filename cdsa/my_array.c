#include "my_array.h"
#include <stdlib.h>

static int  _get    (Array *self, int index)  { return self->data[index]; }
static int  _pop    (Array *self)             { int v = self->data[--self->length]; return v; }
static void _destroy(Array *self)             { free(self->data); free(self); }

static void _append(Array *self, int item) {
    if (self->length == self->capacity) {
        self->capacity *= 2;
        self->data = (int *)realloc(self->data, self->capacity * sizeof(int));
    }
    self->data[self->length++] = item;
}

static void _shift(Array *self, int index) {
    for (int i = index; i < self->length - 1; i++)
        self->data[i] = self->data[i + 1];
    self->length--;
}

static void _delete(Array *self, int index) { _shift(self, index); }

Array *Array_new() {
    Array *a    = (Array *)malloc(sizeof(Array));
    a->length   = 0;
    a->capacity = 4;
    a->data     = (int *)malloc(a->capacity * sizeof(int));
    a->get      = _get;
    a->append   = _append;
    a->pop      = _pop;
    a->delete   = _delete;
    a->destroy  = _destroy;
    return a;
}
