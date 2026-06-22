#include <stdio.h>
#include <stdlib.h>
#include "my_array.h"
#include "my_linked_list.h"
#include "my_dlinked_list.h"
#include "my_stack.h"
#include "my_queue.h"
#include "my_bst.h"
#include "my_hash.h"
#include "my_graph.h"

int main(void) {

    puts("=== Array ===");
    Array *arr = Array_new();
    arr->append(arr, 1);
    arr->append(arr, 2);
    arr->append(arr, 3);
    printf("get(1)  = %d\n", arr->get(arr, 1));
    printf("pop()   = %d\n", arr->pop(arr));
    arr->delete(arr, 0);
    printf("after delete(0), get(0) = %d\n", arr->get(arr, 0));
    arr->destroy(arr);

    puts("\n=== Singly Linked List ===");
    LinkedList *sll = LinkedList_new(10);
    sll->append(sll, 5);
    sll->append(sll, 16);
    sll->prepend(sll, 1);
    sll->insert(sll, 2, 6);
    printf("list:     "); sll->print(sll);
    LinkedList *rev = sll->reverse(sll);
    printf("reversed: "); rev->print(rev);
    sll->destroy(sll);
    rev->destroy(rev);

    puts("\n=== Doubly Linked List ===");
    DLinkedList *dll = DLinkedList_new(5);
    dll->append(dll, 10);
    dll->prepend(dll, 1);
    dll->insert(dll, 2, 6);
    dll->remove(dll, 1);
    printf("dll: "); dll->print(dll);
    dll->destroy(dll);

    puts("\n=== Stack (array-backed) ===");
    StackA *sa = StackA_new();
    sa->push(sa, 5);
    sa->push(sa, 15);
    sa->pop(sa);
    for (int i = 0; i < 5; i++) sa->push(sa, i * i / 2);
    printf("peek = %d  length = %d\n", sa->peek(sa), sa->length);
    sa->destroy(sa);

    puts("\n=== Stack (linked-list-backed) ===");
    StackLL *sl = StackLL_new();
    sl->push(sl, 100);
    sl->push(sl, 200);
    sl->pop(sl);
    printf("peek = %d  length = %d\n", sl->peek(sl), sl->length);
    sl->destroy(sl);

    puts("\n=== Queue ===");
    Queue *q = Queue_new();
    q->enqueue(q, 10);
    q->enqueue(q, 20);
    q->enqueue(q, 30);
    printf("peek = %d\n", q->peek(q));
    q->dequeue(q);
    printf("after dequeue, peek = %d  length = %d\n", q->peek(q), q->length);
    q->destroy(q);

    puts("\n=== BST ===");
    BST *tree = BST_new();
    int vals[] = {9, 4, 6, 20, 170, 15, 1};
    for (int i = 0; i < 7; i++) tree->insert(tree, vals[i]);
    int len = 0;
    int *bfs = tree->bfs(tree, &len);
    printf("BFS:     "); for (int i = 0; i < len; i++) printf("%d ", bfs[i]); puts(""); free(bfs);
    int *ino = tree->dfs_inorder(tree, &len);
    printf("InOrder: "); for (int i = 0; i < len; i++) printf("%d ", ino[i]); puts(""); free(ino);
    tree->remove(tree, 20);
    bfs = tree->bfs(tree, &len);
    printf("BFS -20: "); for (int i = 0; i < len; i++) printf("%d ", bfs[i]); puts(""); free(bfs);
    tree->destroy(tree);

    puts("\n=== Hash Table ===");
    Hash *h = Hash_new(1000);
    h->set(h, "grapes",  10000);
    h->set(h, "apples",  54);
    h->set(h, "oranges", 2);
    int v = 0;
    h->get(h, "grapes",  &v); printf("grapes  = %d\n", v);
    h->get(h, "apples",  &v); printf("apples  = %d\n", v);
    h->get(h, "oranges", &v); printf("oranges = %d\n", v);
    printf("hash('MaNasaaa') = %d\n", h->hash(h, "MaNasaaa"));
    h->destroy(h);

    puts("\n=== Graph ===");
    Graph *g = Graph_new();
    char *nodes[] = {"0","1","2","3","4","5","6"};
    for (int i = 0; i < 7; i++) g->add_vertex(g, nodes[i]);
    g->add_edge(g, "3","1"); g->add_edge(g, "3","4");
    g->add_edge(g, "4","2"); g->add_edge(g, "4","5");
    g->add_edge(g, "1","2"); g->add_edge(g, "1","0");
    g->add_edge(g, "0","2"); g->add_edge(g, "6","5");
    g->show_connections(g);
    g->destroy(g);

    return 0;
}
