#ifndef MY_GRAPH_H
#define MY_GRAPH_H

#define MAX_VERTICES 128
#define MAX_LABEL     64

typedef struct AdjNode {
    char            label[MAX_LABEL];
    struct AdjNode *next;
} AdjNode;

typedef struct {
    char     label[MAX_LABEL];
    AdjNode *head;
} Vertex;

typedef struct Graph Graph;

struct Graph {
    /* data */
    Vertex vertices[MAX_VERTICES];
    int    count;

    /* methods */
    void (*add_vertex)      (Graph *self, const char *label);
    void (*add_edge)        (Graph *self, const char *l1, const char *l2);
    void (*show_connections)(Graph *self);
    void (*destroy)         (Graph *self);
};

Graph *Graph_new();

#endif
