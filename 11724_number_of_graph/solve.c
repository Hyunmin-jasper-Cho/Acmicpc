#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list List;
typedef struct node Node;
typedef struct vertex Vertex;

struct list {
    Node **total_nodes;
    int itr;
};
struct node {
    int data;
};
struct vertex {
    List *adjacent_list;
    bool is_visited;
};

List *get_list(int list_size);
void add_list(List *list, int node_number);
int dfs(Vertex **total_vertex, int vertex_number);

int main() {
    int N, M, ans = 0;
    scanf("%d %d", &N, &M);

    // init vertex
    Vertex **ver = (Vertex **) malloc(sizeof(Vertex *) * (N + 1));
    for (int i = 1; i <= N; ++i) {
        ver[i] = (Vertex *) malloc(sizeof(Vertex));
        ver[i]->adjacent_list = get_list(N);
        ver[i]->is_visited = false;
    }

    for (int i = 0; i < M; ++i) {
        int A, B;
        scanf("%d %d", &A, &B);

        add_list(ver[A]->adjacent_list, B);
        add_list(ver[B]->adjacent_list, A);
    }

    for (int i = 1; i <= N; ++i) {
        ans += dfs(ver, i);
    }

    printf("%d\n", ans);
    return 0;
}

List *get_list(int list_size) {
    Node **nodes = (Node **) malloc(sizeof(Node *) * list_size);
    for (int i = 0; i < list_size; ++i) {
        nodes[i] = (Node *) malloc(sizeof(Node));
        nodes[i]->data = -1; // initialize
    }

    List *lst = (List *) malloc(sizeof(List));
    lst->itr = 0;
    lst->total_nodes = nodes;

    return lst;
}

void add_list(List *list, int node_number) {
    Node **total_nodes = list->total_nodes;

    total_nodes[list->itr++]->data = node_number;
}

int dfs(Vertex **total_vertex, int vertex_number) {
    Vertex *current_vertex = total_vertex[vertex_number];

    if (current_vertex->is_visited) { return 0; }
    current_vertex->is_visited = true;

    for (int i = 0; i < current_vertex->adjacent_list->itr; ++i) {
        dfs(total_vertex, current_vertex->adjacent_list->total_nodes[i]->data);
    }
    return 1;
}

