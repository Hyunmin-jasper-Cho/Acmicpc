#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define INPUT_MAX 500

int map[101][101]; // x = 1, 2, 3, ..., 99, 100;
bool visited[101][101];
int N, min_height = 101, max_height = -1;

int parse_int(char *str);
int solve(int rain, int y, int x);
void clear();

int main() {

    char input[INPUT_MAX];
    int cnt = 1; // 안전영역은 최소 1 이다.


    fgets(input, INPUT_MAX, stdin);
    N = parse_int(input);

    for (int i = 1; i <= N; ++i) {

        fgets(input, INPUT_MAX, stdin);
        map[i][1] = parse_int(strtok(input, " "));
        if (min_height > map[i][1]) min_height = map[i][1];
        if (max_height < map[i][1]) max_height = map[i][1];

        for (int j = 2; j <= N; ++j) {
            map[i][j] = parse_int(strtok(NULL, " "));
            if (min_height > map[i][j]) min_height = map[i][j];
            if (max_height < map[i][j]) max_height = map[i][j];
        }

    }

    for (int rain = min_height; rain < max_height; ++rain) {
        int tmp = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                tmp += solve(rain, i, j);
            }
        } clear();
        if (cnt < tmp) cnt = tmp;
    }
    printf("%d\n", cnt);
}

void clear() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            visited[i][j] = false;
        }
    }
}

int solve(int rain, int y, int x) {
    // out of range
    if (y <= 0 || x <= 0 || y > N || x > N) {
        return 0;
    }

    // ruined place..
    if (map[y][x] <= rain) {
        return 0;
    }

    // already visited..
    if (visited[y][x]) {
        return 0;
    }

    visited[y][x] = true;
    solve(rain, y + 1, x);
    solve(rain, y - 1, x);
    solve(rain, y, x + 1);
    solve(rain, y, x - 1);

    return 1;
}

int parse_int(char *str) {
    return (int) strtol(str, NULL, 10);

}
