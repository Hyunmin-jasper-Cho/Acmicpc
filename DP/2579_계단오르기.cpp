#include <iostream>
#include <cstdlib>

using namespace std;

int ans = 0, tmp = 0;
int number_of_stairs;
int *stairs;

void solve(int index);

int main() {
    char input[7];
    int dp[301] = {0, }; // n 번까지의 최대 값

    scanf("%s", input);
    number_of_stairs = (int) strtol(input, nullptr, 10);
    stairs = new int[number_of_stairs + 1];

    stairs[0] = 0;
    for (int i = 0; i < number_of_stairs; ++i) {
        scanf("%s", input);
        stairs[i + 1] = (int) strtol(input, nullptr, 10);
    }

    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    dp[3] = stairs[3] + (int) max(stairs[1], stairs[2]);

    for (int i = 4; i <= number_of_stairs; ++i) {
        dp[i] = (int) max(dp[i - 3] + stairs[i - 1] + stairs[i], dp[i - 2] + stairs[i]);
    }

    printf("%d", dp[number_of_stairs]);


    return 0;
}

