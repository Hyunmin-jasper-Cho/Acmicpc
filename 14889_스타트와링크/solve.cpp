#include <iostream>
#include <algorithm>
#include <cstring>

int N;

int ans = 2147483647;

bool vis[21];
void solve(int depth, int cur, int map[21][21]);

int main() {
    memset(vis, false, sizeof(vis));
    char input[200], *end;
    int map[21][21];

    scanf("%d", &N); getchar();
    for (int i = 1; i <= N; ++i) {
        fgets(input, 200, stdin); end = input;
        for (int j = 1; j <= N; ++j) {
            map[i][j] = (int) strtol(end, &end, 10);
        }
    }

    vis[1] = true;
    solve(1, 1, map);

    printf("%d", ans);

    return 0;
}

void solve(int depth, int cur, int map[21][21]) {
    // 종료조건..
    if (depth ==  N / 2) {
        int a_tmp = 0;
        int b_tmp = 0;
        for (int i = 1; i <= N; ++i) {
            if (!vis[i]) {
                for (int j = 1; j <= N; ++j) {
                    if (!vis[j]) {
                        a_tmp += map[i][j];
                    }
                }
            } else {
                for (int j = 1; j <= N; ++j) {
                    if (vis[j]) {
                        b_tmp += map[i][j];
                    }
                }
            }
        }
        int v = abs(a_tmp - b_tmp);
        ans = (v < ans ? v : ans);

        return;
    }



    for (int i = cur; i <= N; ++i) {
        if (!vis[i]) { // 선택하지 않았다면..
            vis[i] = true;
            solve(depth + 1, i, map);
            vis[i] = false;
        }
    }
}
