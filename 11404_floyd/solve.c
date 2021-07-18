#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT_MAX 100
#define UNREACHABLE 10000000 // 천만..

int parse_int(char *str);

void init(int pInt[101][101], int n);

int main() {
    char input[INPUT_MAX];
    int N, M, map[101][101];

    fgets(input, INPUT_MAX, stdin);
    N = parse_int(input);
    init(map, N);

    fgets(input, INPUT_MAX, stdin);
    M = parse_int(input);

    for (int i = 0; i < M; ++i) {
        int to, at, cost;
        fgets(input, INPUT_MAX, stdin);

        to = parse_int(strtok(input, " "));
        at = parse_int(strtok(NULL, " "));
        cost = parse_int(strtok(NULL, " "));

        map[to][at] = (cost < map[to][at] ? cost : map[to][at]);
    }

    // k: 거치는 노드...
    for (int k = 1; k <= N; ++k) {

        for (int to = 1; to <= N; ++to) {
            for (int at = 1; at <= N; ++at) {
                if (map[to][k] + map[k][at] < map[to][at]) {
                    map[to][at] = map[to][k] + map[k][at];
                }
            }
        }

    }


    for (int to = 1; to <= N; ++to) {
        for (int at = 1; at <= N; ++at) {
            if (map[to][at] >= UNREACHABLE) {
                printf("0 ");
            } else printf("%d ", map[to][at]);
        } printf("\n");
    }

    return 0;
}

void init(int pInt[101][101], int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                pInt[i][j] = 0;
            } else pInt[i][j] = UNREACHABLE;
        }
    }
}

int parse_int(char *str) {
    return (int) strtol(str, NULL, 10);
}
