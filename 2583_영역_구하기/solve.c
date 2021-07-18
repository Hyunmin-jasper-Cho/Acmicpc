#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define INPUT_MAX 500

int parse_int(char *str);
int solve(int y, int x);
int compare(const void *a, const void *b);

int N, M, K;
bool visited[100][100];

int main() {
    char input[INPUT_MAX];


    fgets(input, INPUT_MAX, stdin);
    N = parse_int(strtok(input, " "));
    M = parse_int(strtok(NULL, " "));
    K = parse_int(strtok(NULL, " "));

    int ans[10000], itr = 0;
    for (int i = 0; i < K; ++i) {
        fgets(input, INPUT_MAX, stdin);

        int sta_x = parse_int(strtok(input, " "));
        int sta_y = parse_int(strtok(NULL, " "));
        int end_x = parse_int(strtok(NULL, " ")) - 1;
        int end_y = parse_int(strtok(NULL, " ")) - 1;

        for (int x = sta_x; x <= end_x; ++x) {
            for (int y = sta_y; y <= end_y; ++y) {
                visited[y][x] = true;
            }
        }

    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int v = solve(i, j);
            if (v != 0) {
                ans[itr++] = v;
            }
        }
    } qsort(ans, itr, sizeof(int), compare);

    printf("%d\n", itr);
    for (int i = 0; i < itr; ++i) {
        printf("%d ", ans[i]);
    }
}

int solve(int y, int x) {
    // out of range
    if (x < 0 || y < 0 || y >= N || x >= M) {
        return 0;
    }


    if (visited[y][x]) return 0;

    int size = 1;
    visited[y][x] = true;

    size += solve(y + 1, x);
    size += solve(y - 1, x);
    size += solve(y, x + 1);
    size += solve(y, x - 1);

    return size;
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}


int parse_int(char *str) {
    return (int) strtol(str, NULL, 10);

}
