#ifndef MY_HASH_H
#define MY_HASH_H

typedef struct HashEntry {
    char             *key;
    int               value;
    struct HashEntry *next;
} HashEntry;

typedef struct Hash Hash;

struct Hash {
    /* data */
    HashEntry **buckets;
    int         size;

    /* methods */
    int  (*hash)     (Hash *self, const char *key);
    void (*set)      (Hash *self, const char *key, int value);
    int  (*get)      (Hash *self, const char *key, int *out_value);
    void (*print_all)(Hash *self);
    void (*destroy)  (Hash *self);
};

Hash *Hash_new(int size);

#endif
