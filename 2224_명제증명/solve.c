#include <stdio.h>
#include <memory.h>

enum {
    A = 0, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    a    , b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z
};

int main() {

    int map[z + 1][z + 1]; // 0 ~ z
    for (int i = A; i <= z; ++i) {
        memset(map + i, 0, sizeof(int) * (z + 1));
    }

    int N;
    scanf("%d", &N); getchar();
    for (int i = 0; i < N; ++i) {
        char input[10];
        fgets(input, 10, stdin);
        char to = input[0];
        char at = input[5];

        // 'a' should be 26
        // a: 97, A: 65, a - A = 32

        if (to >= 'A' && to <= 'Z') { // 대문자..
            if (at >= 'A' && at <= 'Z') {
                map[to - 'A'][at - 'A'] = 1;
            } else map[to - 'A'][at - 'A' - 6] = 1;
        } else {
            if (at >= 'A' && at <= 'Z') {
                map[to - 'A' - 6][at - 'A'] = 1;
            } else map[to - 'A' - 6][at - 'A' - 6] = 1;
        }
    }


    for (int k = A; k <= z; ++k) {

        for (int sta = A; sta <= z; ++sta) {
            for (int at = A; at <= z; ++at) {

                // 만약 갈 수 있다면..
                if (map[sta][at] == 1) continue;

                // 바로 갈 수 없다면, 거쳐 갈 수 있는지 확인한다..
                if (map[sta][k] * map[k][at] == 1) { // 거쳐갈 수 있다면..
                    map[sta][at] = 1;
                }
            }
        }
    }
    int cnt = 0;
    for (int i = A; i <= z; ++i) {
        for (int j = A; j <= z; ++j) {
            if (map[i][j] == 1) {
                if (i != j) {
                    cnt += 1;
                }
            }
        }
    }

    printf("%d\n", cnt);
    for (int i = A; i <= z; ++i) {
        for (int j = A; j <= z; ++j) {
            if (map[i][j] == 1) {
                if (i != j) {

                    // 대문자면 + 'A'
                    // 소문자면 - 71

                    if (i < 26 && j < 26) {
                        printf("%c => %c\n", i + 'A', j + 'A');
                    } else if (i < 26) {
                        printf("%c => %c\n", i + 'A', j + 71);
                    } else if (j < 26) {
                        printf("%c => %c\n", i + 71, j + 'A');
                    } else {
                        printf("%c => %c\n", i + 71, j + 71);
                    }
                }
            }
        }
    }


    return 0;
}
