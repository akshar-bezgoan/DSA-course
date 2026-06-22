#include "my_bst.h"
#include <stdlib.h>

typedef struct { int *data; int len; int cap; } IntVec;
static void iv_push(IntVec *v, int val) {
    if (v->len == v->cap) {
        v->cap  = v->cap ? v->cap * 2 : 8;
        v->data = (int *)realloc(v->data, v->cap * sizeof(int));
    }
    v->data[v->len++] = val;
}

static BSTNode *_node(int value) {
    BSTNode *n   = (BSTNode *)malloc(sizeof(BSTNode));
    n->value     = value; n->frequency = 0;
    n->left      = NULL;  n->right     = NULL;
    return n;
}

static void _free_nodes(BSTNode *n) {
    if (!n) return;
    _free_nodes(n->left); _free_nodes(n->right); free(n);
}

static void _insert(BST *self, int value) {
    BSTNode *new_node = _node(value);
    if (!self->root) { self->root = new_node; return; }
    BSTNode *cur = self->root;
    while (1) {
        if (value > cur->value) {
            if (cur->right) cur = cur->right;
            else { cur->right = new_node; cur->right->frequency++; break; }
        } else if (value < cur->value) {
            if (cur->left) cur = cur->left;
            else { cur->left = new_node; cur->left->frequency++; break; }
        } else { free(new_node); cur->frequency++; break; }
    }
}

static BSTNode *_lookup(BST *self, int value) {
    BSTNode *cur = self->root;
    while (cur) {
        if      (value > cur->value) cur = cur->right;
        else if (value < cur->value) cur = cur->left;
        else return cur;
    }
    return NULL;
}

static int _remove(BST *self, int value) {
    if (!self->root) return 0;
    BSTNode *cur = self->root, *parent = NULL;
    while (cur) {
        if      (value < cur->value) { parent = cur; cur = cur->left; }
        else if (value > cur->value) { parent = cur; cur = cur->right; }
        else {
            if (!cur->right) {
                if (!parent)                             self->root    = cur->left;
                else if (cur->value < parent->value)     parent->left  = cur->left;
                else                                     parent->right = cur->left;
            } else if (!cur->right->left) {
                cur->right->left = cur->left;
                if (!parent)                             self->root    = cur->right;
                else if (cur->value < parent->value)     parent->left  = cur->right;
                else                                     parent->right = cur->right;
            } else {
                BSTNode *lm = cur->right->left, *lmp = cur->right;
                while (lm->left) { lmp = lm; lm = lm->left; }
                lmp->left = lm->right;
                lm->left  = cur->left;
                lm->right = cur->right;
                if (!parent)                             self->root    = lm;
                else if (cur->value < parent->value)     parent->left  = lm;
                else                                     parent->right = lm;
            }
            free(cur); return 1;
        }
    }
    return 0;
}

static int *_bfs(BST *self, int *out_len) {
    IntVec result = {0};
    if (!self->root) { *out_len = 0; return NULL; }
    int qcap = 64, qhead = 0, qtail = 0;
    BSTNode **q = (BSTNode **)malloc(qcap * sizeof(BSTNode *));
    q[qtail++] = self->root;
    while (qhead < qtail) {
        if (qtail == qcap) { qcap *= 2; q = (BSTNode **)realloc(q, qcap * sizeof(BSTNode *)); }
        BSTNode *cur = q[qhead++];
        iv_push(&result, cur->value);
        if (cur->left)  q[qtail++] = cur->left;
        if (cur->right) q[qtail++] = cur->right;
    }
    free(q);
    *out_len = result.len; return result.data;
}

static void _inorder  (BSTNode *n, IntVec *v) { if (!n) return; _inorder(n->left,v);   iv_push(v,n->value); _inorder(n->right,v); }
static void _preorder (BSTNode *n, IntVec *v) { if (!n) return; iv_push(v,n->value);   _preorder(n->left,v); _preorder(n->right,v); }
static void _postorder(BSTNode *n, IntVec *v) { if (!n) return; _postorder(n->left,v); _postorder(n->right,v); iv_push(v,n->value); }

static int *_dfs_inorder  (BST *s, int *l) { IntVec v={0}; _inorder  (s->root,&v); *l=v.len; return v.data; }
static int *_dfs_preorder (BST *s, int *l) { IntVec v={0}; _preorder (s->root,&v); *l=v.len; return v.data; }
static int *_dfs_postorder(BST *s, int *l) { IntVec v={0}; _postorder(s->root,&v); *l=v.len; return v.data; }

static void _destroy(BST *self) { _free_nodes(self->root); free(self); }

BST *BST_new() {
    BST *t         = (BST *)malloc(sizeof(BST));
    t->root        = NULL;
    t->insert       = _insert;
    t->lookup       = _lookup;
    t->remove       = _remove;
    t->bfs          = _bfs;
    t->dfs_inorder  = _dfs_inorder;
    t->dfs_preorder = _dfs_preorder;
    t->dfs_postorder= _dfs_postorder;
    t->destroy      = _destroy;
    return t;
}
