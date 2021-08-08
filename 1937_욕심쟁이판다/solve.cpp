#include <iostream>
#include <cstring>

int N;
int map[501][501];
int dp[501][501];

int xm[4] = {0, 0, -1, 1};
int ym[4] = {-1, 1, 0, 0};
int solve(int x, int y);

int main() {
    char input[10000];

    memset(dp, -1, sizeof(dp));
    scanf("%d", &N); getchar();

    for (int i = 1; i <= N; ++i) {
        fgets(input, 10000, stdin);
        map[i][1] = (int) strtol(strtok(input, " "), nullptr, 10);
        for (int j = 2; j <= N; ++j) {
            map[i][j] = (int) strtol(strtok(nullptr, " "), nullptr, 10);
        }
    }

    int max_move = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int v = solve(j, i);
            max_move = (max_move < v ? v : max_move);
        }
    }

    printf("%d", max_move + 1);


    return 0;
}

int solve(int x, int y) {
    int ans = 0;
    if (dp[y][x] != -1) {
        return dp[y][x];
    }

    int tmp;
    for (int i = 0; i < 4; ++i) {
        if (x + xm[i] > 0 and y + ym[i] > 0 and x + xm[i] <= N and y + ym[i] <= N) { // 범위 안에 있고..
            if (map[y + ym[i]][x + xm[i]] > map[y][x]) { // 새로운 값이 기존 값보다 크다면..
                if (dp[y + ym[i]][x + xm[i]] != -1) {
                    tmp = dp[y + ym[i]][x + xm[i]] + 1;
                } else tmp = solve(x + xm[i], y + ym[i]) + 1;
                
                ans = (ans < tmp ? tmp : ans);
            }
        }
    }
    dp[y][x] = ans;
    return dp[y][x];
}
