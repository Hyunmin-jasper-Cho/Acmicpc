#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum {
    sea = 0, land
};

int parse_int(char *str);
int dfs(int i, int j);

bool **visited;
int **map;
int height, width;

int main() {
    while (true) {
        int ans = 0;
        char input[200];

        fgets(input, 200, stdin);

        width = parse_int(strtok(input, " "));
        height = parse_int(strtok(NULL, " "));

        if (width == 0 && height == 0) break;

        map = (int **) malloc(sizeof (int *) * height);
        visited = (bool **) malloc(sizeof (bool *) * height);

        for (int i = 0; i < height; ++i) {
            map[i] = (int *) malloc(sizeof (int) * width);
            visited[i] = (bool *) malloc(sizeof (bool) * width);

            fgets(input, 200, stdin);
            map[i][0] = parse_int(strtok(input, " "));
            for (int j = 1; j < width; ++j) {
                map[i][j] = parse_int(strtok(NULL, " "));
            }
        }

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (dfs(i, j) != 0) {
                    ans += 1;
                }
            }
        }

        printf("%d\n", ans);

    }

    return 0;
}

int dfs(int i, int j) {

    // index out of bounds..
    if (i < 0 || j < 0 || i >= height || j >= width ) return 0;

    // 이미 방문했거나 해당 지점이 0 이면..
    if (visited[i][j] == true || map[i][j] == sea) return 0;

    // 방문처리..
    visited[i][j] = true;

    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
    dfs(i + 1, j + 1);
    dfs(i + 1, j - 1);
    dfs(i - 1, j + 1);
    dfs(i - 1, j - 1);

    return 1;
}

int parse_int(char *str) {
    return (int) strtol(str, NULL, 10);
}
