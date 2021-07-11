#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int N, r, c;

int new_solve(int val, int len, int x, int y);

int main() {
    char input[30];
    fgets(input, 30, stdin);

    N = (int) strtol(strtok(input, " "), NULL, 10);
    r = (int) strtol(strtok(NULL, " "),NULL, 10);
    c = (int) strtol(strtok(NULL, " "),NULL, 10);

    int len = (int) pow(2, N);

    int ans = new_solve(0, len, 0, 0);
    printf("%d", ans);

    return 0;
}

int new_solve(int val, int len, int x, int y) {
    int ans = 0;
    if (len == 1) {
        if (x == c && y == r) {
            return val;
        }
    } else {
        int half = len / 2;
        int new_val = (half * half);

        if (r < y + half) { // 상

            if (c < x + half) { // 좌
                ans = new_solve(val, half, x, y); // 상좌
            } else { // 우
                ans = new_solve(val + new_val, half, x + half, y); // 상우
            }

        } else { // 하

            if (c < x + half) { // 좌
                ans = new_solve((2 * new_val) + val, half, x, y + half); // 하좌
            } else { // 우
                ans = new_solve((3 * new_val) + val, half, x + half, y + half); // 하우
            }

        }

    }
    return ans;
}
