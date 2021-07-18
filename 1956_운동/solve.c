#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define INPUT_MAX 20
#define UNREACHABLE 40000001 // 4천만 1
#define EMPTY (-1)

int parse_int(char *str);


int compare(const void *a, const void *b);
void init_ans(int ans[401]);
void init(int V, int map[401][401]);
void floyd(int V, int map[401][401], bool reachable[401][401]);

int main() {
    int map[401][401];
    bool reachable[401][401];
    int ans[401];
    int V, E, to, at, cost;

    char input[INPUT_MAX];
    fgets(input, INPUT_MAX, stdin);
    V = parse_int(strtok(input, " "));
    E = parse_int(strtok(NULL, " "));
    init(V, map);
    init_ans(ans);

    for (int i = 0; i < E; ++i) {
        fgets(input, INPUT_MAX, stdin);
        to = parse_int(strtok(input, " "));
        at = parse_int(strtok(NULL, " "));
        cost = parse_int(strtok(NULL, " "));

        map[to][at] = cost;
        reachable[to][at] = true;
    }

    floyd(V, map, reachable);


    for (int i = 1; i <= V; ++i) {
        int tmp = EMPTY;
        for (int j = 1; j <= V; ++j) {

            // 자기자신 방문.. skip
            if (i == j) continue;

            // 들를 수 있는 곳이 없다면..
            if (!reachable[i][j] || !reachable[j][i]) continue;

            tmp = map[i][j] + map[j][i];

            if (ans[i] == EMPTY) ans[i] = tmp;
            else ans[i] = (tmp < ans[i] ? tmp : ans[i]);
        }
    } qsort(ans, (V + 1), sizeof(int), compare);

    if (ans[V] == EMPTY) { // 전부 EMPTY..
        printf("-1\n");
    } else {
        for (int i = 1; i <= V; ++i) {
            if (ans[i] != -1) {
                printf("%d\n", ans[i]);
                break;
            }
        }
    }

    return 0;
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void init_ans(int ans[401]) {
    for (int i = 0; i < 401; ++i) {
        ans[i] = EMPTY;
    }
}

void init(int V, int map[401][401]) {
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (i == j) map[i][j] = 0;
            else map[i][j] = UNREACHABLE;
        }
    }
}

void floyd(int V, int map[401][401], bool reachable[401][401]) {
    for (int k = 1; k <= V; ++k) {

        for (int to = 1; to <= V; ++to) {
            for (int at = 1; at <= V; ++at) {
                if (map[to][k] + map[k][at] < map[to][at]) {
                    map[to][at] = map[to][k] + map[k][at];
                    reachable[to][at] = true;
                }
            }
        }
    }
}


int parse_int(char *str) {
    return (int) strtol(str, NULL, 10);
}
