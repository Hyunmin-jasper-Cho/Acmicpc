#include <iostream>
#include <cstring>

int cnt = 0;
int ans[11] = {0, };
int N, k;

void solve(int depth, int sum);

int main() {

    char input[50];

    fgets(input, 50, stdin);
    N = (int) strtol(strtok(input, " "), nullptr, 10);
    k = (int) strtol(strtok(nullptr, " "), nullptr, 10);


    // 시작은 1 부터...
    for (int i = 1; i <= 3; ++i) {
        ans[0] = i; // idx == 1
        solve(1, ans[0]);
    }
    printf("-1");


    return 0;
}

void solve(int depth, int sum) {

    if (sum == N) {
        cnt += 1;
        if (cnt == k) {
            for (int i = 0; i < depth - 1; ++i) {
                printf("%d+", ans[i]);
            } printf("%d", ans[depth - 1]);
            exit(0);
        } return;
    }

    if (sum + 1 <= N) {
        ans[depth] = 1;
        solve(depth + 1, sum + 1);
    } if (sum + 2 <= N) {
        ans[depth] = 2;
        solve(depth + 1, sum + 2);
    } if (sum + 3 <= N) {
        ans[depth] = 3;
        solve(depth + 1, sum + 3);
    }

}
