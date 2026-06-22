#ifndef MY_BST_H
#define MY_BST_H

typedef struct BSTNode {
    int            value;
    int            frequency;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

typedef struct BST BST;

struct BST {
    BSTNode *root;

    void     (*insert)       (BST *self, int value);
    BSTNode *(*lookup)       (BST *self, int value);
    int      (*remove)       (BST *self, int value);
    int     *(*bfs)          (BST *self, int *out_len);
    int     *(*dfs_inorder)  (BST *self, int *out_len);
    int     *(*dfs_preorder) (BST *self, int *out_len);
    int     *(*dfs_postorder)(BST *self, int *out_len);
    void     (*destroy)      (BST *self);
};

BST *BST_new();

#endif
