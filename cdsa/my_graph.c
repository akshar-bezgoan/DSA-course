#include "my_graph.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int _find(Graph *self, const char *label) {
    for (int i = 0; i < self->count; i++)
        if (strcmp(self->vertices[i].label, label) == 0) return i;
    return -1;
}

static void _adj_append(Vertex *v, const char *label) {
    AdjNode *node = (AdjNode *)malloc(sizeof(AdjNode));
    strncpy(node->label, label, MAX_LABEL - 1);
    node->label[MAX_LABEL - 1] = '\0';
    node->next = NULL;
    if (!v->head) { v->head = node; return; }
    AdjNode *cur = v->head;
    while (cur->next) cur = cur->next;
    cur->next = node;
}

static void _add_vertex(Graph *self, const char *label) {
    if (self->count >= MAX_VERTICES) return;
    strncpy(self->vertices[self->count].label, label, MAX_LABEL - 1);
    self->vertices[self->count].label[MAX_LABEL - 1] = '\0';
    self->vertices[self->count].head = NULL;
    self->count++;
}

static void _add_edge(Graph *self, const char *l1, const char *l2) {
    int i1 = _find(self, l1), i2 = _find(self, l2);
    if (i1 < 0 || i2 < 0) return;
    _adj_append(&self->vertices[i1], l2);
    _adj_append(&self->vertices[i2], l1);
}

static void _show_connections(Graph *self) {
    for (int i = 0; i < self->count; i++) {
        printf("%s --> ", self->vertices[i].label);
        AdjNode *cur = self->vertices[i].head;
        while (cur) { printf("%s ", cur->label); cur = cur->next; }
        printf("\n");
    }
}

static void _destroy(Graph *self) {
    for (int i = 0; i < self->count; i++) {
        AdjNode *cur = self->vertices[i].head;
        while (cur) { AdjNode *next = cur->next; free(cur); cur = next; }
    }
    free(self);
}

Graph *Graph_new() {
    Graph *g            = (Graph *)malloc(sizeof(Graph));
    g->count            = 0;
    g->add_vertex       = _add_vertex;
    g->add_edge         = _add_edge;
    g->show_connections = _show_connections;
    g->destroy          = _destroy;
    return g;
}
