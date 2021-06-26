#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node Node;
typedef struct list List;
typedef struct vertex Vertex;
typedef struct graph Graph;
int answer = 0;

struct node {
    int data;
    Node *next;
};
struct list {
    Node *root;
    int list_itr;
};
struct vertex {
    List *adjacent_vertex_list;
};
struct graph {
    Vertex **vertex;
};

List *new_list(int total_number_of_computer) {
    List *lst = (List *) malloc(sizeof (List));
    Node **node = (Node **) malloc(sizeof (Node *) * total_number_of_computer);
    node[0] = (Node *) malloc(sizeof (Node));
    node[0]->data = 1;

    for (int i = 1; i < total_number_of_computer; ++i) {
        node[i] = (Node *) malloc(sizeof (Node));
        node[i]->data = 0;
        node[i - 1]->next = node[i];
    }
    node[total_number_of_computer - 1]->next = NULL;
    lst->root = node[0];
    lst->list_itr = 0;
    return lst;
}

void add_list(List *lst, int data) {
    Node *tmp = lst->root;
    for (int i = 0; i < lst->list_itr; ++i) {
        tmp = tmp->next;
    }
    tmp->data = data;
    lst->list_itr += 1;
}

Graph *new_graph(int total_number_of_computer) {
    Graph *g = (Graph *) malloc(sizeof (Graph));
    g->vertex = (Vertex **) malloc(sizeof (Vertex *) * total_number_of_computer);

    for (int i = 0; i < total_number_of_computer; ++i) {
        g->vertex[i] = (Vertex *) malloc(sizeof (Vertex));
        g->vertex[i]->adjacent_vertex_list = new_list(total_number_of_computer);
    }
    return g;
}

void link_vertex(Graph *g, int a, int b) { // link a to b and b to a // 양방향
    a -= 1;
    b -= 1;

    add_list(g->vertex[a]->adjacent_vertex_list, b);
    add_list(g->vertex[b]->adjacent_vertex_list, a);
}

void dfs(Graph *g, bool *visited, int vertex_number) {
    // 방문한 노드 --> 즉시 return false;
    if (visited[vertex_number]) return;

    visited[vertex_number] = true;
    answer += 1;

    Node *itr = g->vertex[vertex_number]->adjacent_vertex_list->root;
    int list_max = g->vertex[vertex_number]->adjacent_vertex_list->list_itr;

    for (int i = 0; i < list_max; ++i) {
        dfs(g, visited, itr->data);
        itr = itr->next;
    }
}

int main() {
    int total_number_of_computer, number_of_line;
    scanf("%d %d", &total_number_of_computer, &number_of_line);

    Graph *g = new_graph(total_number_of_computer);
    bool *visited = (bool *) malloc(sizeof (bool) * total_number_of_computer);
    for (int i = 0; i < total_number_of_computer; ++i) {
        visited[i] = false;
    }

    for (int i = 0; i < number_of_line; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        link_vertex(g, a, b);
    }

    dfs(g, visited, 0);
    printf("%d\n", answer - 1);
    return 0;
}
