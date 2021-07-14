#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

enum {
    red = 1, green, blue
};

int parse_int(char *str);
int min(int a, int b);

int MAX_N;
int **house, **path;

int main() {

    char input[100];
    int ans = INT_MAX;

    scanf("%s", input); getchar();
    MAX_N = parse_int(input);

    house = (int **) malloc(sizeof (int *) * (MAX_N + 1));
    path = (int **) malloc(sizeof (int *) * (MAX_N + 1));
    for (int i = 1; i <= MAX_N; ++i) {
        house[i] = (int *) malloc(sizeof (int) * (3 + 1));
        path[i] = (int *) malloc(sizeof (int) * (3 + 1));

        fgets(input, 100, stdin);
        house[i][red] = parse_int(strtok(input, " "));
        house[i][green] = parse_int(strtok(NULL, " "));
        house[i][blue] = parse_int(strtok(NULL, " "));

    }

    for (int i = red; i <= blue; ++i) {
        path[MAX_N][i] = house[MAX_N][i];
    }

    int r_cost, g_cost, b_cost;

    for (int house_num = MAX_N - 1; house_num >= 1; --house_num) {

        for (int color = red; color <= blue; ++color) {
            int current_cost = house[house_num][color];

            if (color == red) {
                g_cost = path[house_num + 1][green] + current_cost;
                b_cost = path[house_num + 1][blue] + current_cost;

                path[house_num][red] = g_cost < b_cost ? g_cost : b_cost;
            } else if (color == green) {
                r_cost = path[house_num + 1][red] + current_cost;
                b_cost = path[house_num + 1][blue] + current_cost;

                path[house_num][green] = r_cost < b_cost ? r_cost : b_cost;
            } else {
                g_cost = path[house_num + 1][green] + current_cost;
                r_cost = path[house_num + 1][red] + current_cost;

                path[house_num][blue] = g_cost < r_cost? g_cost : r_cost;
            }

        }

    }

    ans = min(path[1][red], min(path[1][green], path[1][blue]));

    printf("%d", ans);

    return 0;
}

int parse_int(char *str) {
    return (int) strtol(str, NULL, 10);
}

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

