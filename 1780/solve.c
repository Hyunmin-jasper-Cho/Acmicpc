#include <stdio.h>
#include <stdbool.h>

int slate[2187 + 1][2187 + 1];
int n_of_m1 = 0;
int n_of_zero = 0;
int n_of_1 = 0;

bool isFilled(int sta_x, int sta_y, int len) { // 4, 1, 3
    bool n[3] = {false, false, false}; // -1, 0, 1
    n[slate[sta_y][sta_x] + 1] = true;

    for (int i = sta_y; i < sta_y + len; ++i) {
        for (int j = sta_x; j < sta_x + len; ++j) {
            if (n[0] && (slate[i][j] == 0 || slate[i][j] == 1)) return false;
            if (n[1] && (slate[i][j] == -1 || slate[i][j] == 1)) return false;
            if (n[2] && (slate[i][j] == -1 || slate[i][j] == 0)) return false;
        }
    }

    if (n[0]) n_of_m1 += 1;
    else if (n[1]) n_of_zero += 1;
    else n_of_1 += 1;

    return true;
}

void solve(int sta_x, int sta_y, int len) {
    if (!isFilled(sta_x, sta_y, len)) {
        for (int i = sta_y; i < sta_y + len; i += (len / 3)) {
            for (int j = sta_x; j < sta_x + len; j += (len / 3)) {
                solve(j, i, len / 3);
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &(slate[i][j]));
        }
    }

    solve(1, 1, N);

    printf("%d\n%d\n%d\n", n_of_m1, n_of_zero, n_of_1);

    return 0;
}
