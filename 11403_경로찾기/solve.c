
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define INPUT_MAX 300
#define TRUE 1
#define FALSE 0

int parse_int(char *str);

bool map[101][101];

int main() {
    char input[INPUT_MAX];

    fgets(input, INPUT_MAX, stdin);
    int N = parse_int(input);



    for (int i = 0; i < N; ++i) {
        fgets(input, INPUT_MAX, stdin);
        map[i][0] = parse_int(strtok(input, " "));

        for (int j = 1; j < N; ++j) {
            map[i][j] = parse_int(strtok(NULL, " "));
        }
    }

    for (int k = 0; k < N; ++k) {

        for (int to = 0; to < N; ++to) {
            for (int at = 0; at < N; ++at) {
                if (map[to][at]) continue;
                else {
                    if (map[to][k] == TRUE && map[k][at] == TRUE) {
                        map[to][at] = TRUE;
                    }
                }
            }
        }
    }

    for (int to = 0; to < N; ++to) {
        for (int at = 0; at < N; ++at) {
            printf("%d ", map[to][at]);
        } printf("\n");
    }

    return 0;
}


int parse_int(char *str) {
    return (int) strtol(str, NULL, 10);
}
