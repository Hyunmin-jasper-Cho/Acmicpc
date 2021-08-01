#include <iostream>
#include <cstdlib>

using namespace std;

int ans = 0, tmp = 0;
int N;

void solve(int index);

int main() {
    char input[7];
    int dp[10001] = {0, }; // n 번까지의 최대 값
    int glasses[10001] = {0, };

    scanf("%s", input);
    N = (int) strtol(input, nullptr, 10);

    glasses[0] = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%s", input);
        glasses[i + 1] = (int) strtol(input, nullptr, 10);
    }

    dp[1] = glasses[1];
    dp[2] = glasses[1] + glasses[2];
    dp[3] = glasses[1] + glasses[2] + glasses[3] - min(glasses[1], min(glasses[2], glasses[3]));

    for (int i = 4; i <= N; ++i) {
        dp[i] = max(dp[i - 1], max(glasses[i] + glasses[i - 1] + dp[i - 3], glasses[i] + dp[i - 2]));
    }


    printf("%d", dp[N]);


    return 0;
}

