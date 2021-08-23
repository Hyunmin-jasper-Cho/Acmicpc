#include <iostream>

int N, cnt = 0;
int vis[16] = {0, };
int ans[16] = {0, };

void solve(int depth);
bool can_add(int v, int depth);

int main() {

    scanf("%d", &N);

    for (int i = 1; i <= N / 2; ++i) {
        vis[i] = 1; ans[1] = i;
        solve(2);
        vis[i] = 0;
    } cnt *= 2;

    if (N % 2 == 1) {
        int M = (N / 2) + 1;
        vis[M] = 1; ans[1] = M;
        solve(2);
        vis[M] = 0;
    }

    printf("%d", cnt);

    return 0;
}

void solve(int depth) {

    if (depth == N + 1) {
        cnt++; return;
    }

    for (int i = 1; i <= N; ++i) {
        if (vis[i] == 1) continue;

        if (can_add(i, depth)) {
            vis[i] = 1; ans[depth] = i;
            solve(depth + 1);
            vis[i] = 0;
        }
    }
}

bool can_add(int v, int depth) {
    for (int i = 1; i < depth; ++i) {
        if (abs(v - ans[i]) == abs(depth - i)) {
            return false;
        }
    } return true;
}
