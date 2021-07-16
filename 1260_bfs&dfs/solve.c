#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

typedef struct vertex Vertex;
struct vertex {
    int *adjacent_list;
    int idx;
};

Vertex **ver;
bool *visited;

int parse_int(char *str);
void dfs(int v_num);
int compare(const void *a, const void *b);

int main() {
    char input[51];

    fgets(input, 51, stdin);
    int N, M, V;
    N = parse_int(strtok(input, " "));
    M = parse_int(strtok(NULL, " "));
    V = parse_int(strtok(NULL, " "));

    ver = (Vertex **) malloc(sizeof (Vertex *) * (N + 1));
    visited = (bool *) malloc(sizeof (bool) * (N + 1));
    for (int i = 1; i <= N; ++i) {
        ver[i] = (Vertex *) malloc(sizeof (Vertex));
        ver[i]->adjacent_list = (int *) malloc(sizeof (int) * N);
        ver[i]->idx = 0;
    }

    for (int i = 0; i < M; ++i) {
        int A, B;
        fgets(input, 51, stdin);
        A = parse_int(strtok(input, " "));
        B = parse_int(strtok(NULL," "));

        ver[A]->adjacent_list[(ver[A]->idx++)] = B;
        ver[B]->adjacent_list[(ver[B]->idx++)] = A;
    }

    for (int i = 1; i <= N; ++i) {
        qsort(ver[i]->adjacent_list, ver[i]->idx, sizeof(int), compare);
    }

    dfs(V);
    for (int i = 1; i <= N; ++i) {
        visited[i] = false;
    }
    printf("\n");

    Queue *q = new_queue();
    push(q, V);
    while (!is_queue_empty(q)) {
        int size = get_size(q);


        for (int i = 0; i < size; ++i) {

            int cur_ver_num = pop_value(q);
            printf("%d ", cur_ver_num);
            visited[cur_ver_num] = true;

            for (int j = 0; j < ver[cur_ver_num]->idx; ++j) {

                if (!visited[ver[cur_ver_num]->adjacent_list[j]]) {
                    push(q, ver[cur_ver_num]->adjacent_list[j]);
                    visited[ver[cur_ver_num]->adjacent_list[j]] = true;
                }

            }

        }
    }

    return 0;
}

void dfs(int v_num) {

    if (visited[v_num]) return;

    printf("%d ", v_num);
    visited[v_num] = true;

    for (int i = 0; i < ver[v_num]->idx; ++i) {
        dfs(ver[v_num]->adjacent_list[i]);
    }

}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int parse_int(char *str) {
    return (int) strtol(str, NULL, 10);
}
