#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_int(char *str);
int get_max(int a, int b);

int main() {

    char input[5000];

    scanf("%s", input); getchar();
    int N = parse_int(input);

    int **tri = (int **) malloc(sizeof (int *) * (N + 1));
    int **path = (int **) malloc(sizeof (int *) * (N + 1));
    for (int i = 1; i <= N; ++i) {
        tri[i] = (int *) malloc(sizeof (int) * (i + 1));
        path[i] = (int *) malloc(sizeof (int) * (i + 1));

        fgets(input, 5000, stdin);

        tri[i][1] = parse_int(strtok(input, " "));
        for (int j = 2; j <= i; ++j) {
            tri[i][j] = parse_int(strtok(NULL, " "));
        }
    }

    for (int i = 1; i <= N; ++i) {
        path[N][i] = tri[N][i];
    }


    for (int height = N - 1; height >= 1; --height) {
        for (int i = 1; i <= height; ++i) {
            path[height][i] = get_max(path[height + 1][i], path[height + 1][i + 1])
                    + tri[height][i];
        }
    }

    printf("%d\n", path[1][1]);
    return 0;
}

int parse_int(char *str) {
    return (int) strtol(str, NULL, 10);
}

int get_max(int a, int b) {
    if (a > b) return a;
    else return b;
}

