#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    int arr[1001] = {0, };
    int dp[1001] = {0, };

    char input[6];
    scanf("%s", input);

    int N = (int) strtol(input, nullptr, 10);


    for (int i = 1; i <= N; ++i) {
        scanf("%s", input);
        arr[i] = (int) strtol(input, nullptr, 10);
    }


    for (int i = 1; i <= N; ++i) {

        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {

                int tmp = dp[j] + 1;

                dp[i] = tmp > dp[i] ? tmp : dp[i];
            }
        }
    } sort(dp, dp + (N + 1));

    printf("%d", dp[N]);

    return 0;
}
