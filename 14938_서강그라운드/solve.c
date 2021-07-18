#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INPUT_MAX 500
#define UNREACHABLE 1000000

int parse_int(char *str);
void floyd(int n, int map[101][101]);
void init(int map[101][101]);

int N, M, R;
int items[101];
int ans[101];

int main() {
    char input[INPUT_MAX];
    int to, at, cost;
    int map[101][101];

    fgets(input, INPUT_MAX, stdin);
    N = parse_int(strtok(input, " "));
    M = parse_int(strtok(NULL, " "));
    R = parse_int(strtok(NULL, " "));
    init(map);

    fgets(input, INPUT_MAX, stdin);
    items[1] = parse_int(strtok(input, " "));
    for (int i = 2; i <= N; ++i) {
        items[i] = parse_int(strtok(NULL, " "));
    }

    for (int i = 0; i < R; ++i) {
        fgets(input, INPUT_MAX, stdin);

        to = parse_int(strtok(input, " "));
        at = parse_int(strtok(NULL, " "));
        cost = parse_int(strtok(NULL, " "));

        map[to][at] = cost;
        map[at][to] = cost;
    }

    floyd(N, map);

    int max = INT_MIN;
    for (int h = 1; h <= N; ++h) {
        for (int w = 1; w <= N; ++w) {

            if (map[h][w] <= M) { // 수색범위 이내라면..
                ans[h] += items[w];
            }
        }
        if (max < ans[h]) max = ans[h];
    }

    printf("%d\n", max);

    return 0;
}

void floyd(int n, int map[101][101]) {

    for (int k = 1; k <= n; ++k) {

        for (int to = 1; to <= n; ++to) {
            for (int at = 1; at <= n; ++at) {
                if (map[to][k] + map[k][at] < map[to][at]) {
                    map[to][at] = map[to][k] + map[k][at];
                }
            }
        }
    }
}

void init(int map[101][101]) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j) map[i][j] = 0;
            else map[i][j] = UNREACHABLE;
        }
    }
}


int parse_int(char *str) {
    return (int) strtol(str, NULL, 10);
}
