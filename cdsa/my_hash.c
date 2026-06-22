#include "my_hash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int _hash(Hash *self, const char *key) {
    int val = 0, len = (int)strlen(key);
    for (int i = 0; i < len; i++)
        val = (val + (unsigned char)key[i] * i) % self->size;
    return val;
}

static void _set(Hash *self, const char *key, int value) {
    int index = _hash(self, key);
    HashEntry *e = self->buckets[index];
    while (e) { if (strcmp(e->key, key) == 0) { e->value = value; return; } e = e->next; }
    HashEntry *ne = (HashEntry *)malloc(sizeof(HashEntry));
    ne->key   = strdup(key); ne->value = value;
    ne->next  = self->buckets[index];
    self->buckets[index] = ne;
}

static int _get(Hash *self, const char *key, int *out) {
    int index = _hash(self, key);
    HashEntry *e = self->buckets[index];
    while (e) {
        if (strcmp(e->key, key) == 0) { if (out) *out = e->value; return 1; }
        e = e->next;
    }
    return 0;
}

static void _print_all(Hash *self) {
    for (int i = 0; i < self->size; i++) {
        HashEntry *e = self->buckets[i];
        if (e) {
            printf("Index%d: ", i);
            while (e) { printf("[%s: %d] ", e->key, e->value); e = e->next; }
            printf("\n");
        }
    }
}

static void _destroy(Hash *self) {
    for (int i = 0; i < self->size; i++) {
        HashEntry *e = self->buckets[i];
        while (e) { HashEntry *next = e->next; free(e->key); free(e); e = next; }
    }
    free(self->buckets); free(self);
}

Hash *Hash_new(int size) {
    Hash *h       = (Hash *)malloc(sizeof(Hash));
    h->size       = size;
    h->buckets    = (HashEntry **)calloc(size, sizeof(HashEntry *));
    h->hash       = _hash;
    h->set        = _set;
    h->get        = _get;
    h->print_all  = _print_all;
    h->destroy    = _destroy;
    return h;
}
