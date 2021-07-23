#include <iostream>
#include <vector>

using namespace std;

enum {
    PLUS = 0, MINUS, MUL, DIV
};

int N;
int ope[4] = {0, 0, 0, 0};
int *nums;

long long int NUM_MAX = -2147483647 - 1; // integer max
long long int NUM_MIN = 2147483647;      // integer min

void solve(int ans, int depth);

int main() {

    scanf("%d", &N);
    nums = new int[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", nums + i);
    }
    for (int i = 0; i < 4; ++i) {
        scanf("%d", ope + i);
    }

    solve(nums[0], 0);

    printf("%lld\n%lld", NUM_MAX, NUM_MIN);


    return 0;
}

void solve(int ans, int depth) {

    if (depth == N - 1) { // 끝..
        if (NUM_MAX < ans) NUM_MAX = ans;
        if (NUM_MIN > ans) NUM_MIN = ans;

        return; // 되돌아간다..
    }

    // 현재 depth 에 대해서 총 최대 4가지의 행동을 한다...
    for (int i = 0; i < 4; ++i) {
        if (ope[i] != 0) { // 해당 행동을 할 수 있을 때만..
            if (i == PLUS) {
                ope[PLUS] -= 1;
                solve(ans + nums[depth + 1], depth + 1);
                ope[PLUS] += 1;
            } else if (i == MINUS) {
                ope[MINUS] -= 1;
                solve(ans - nums[depth + 1], depth + 1);
                ope[MINUS] += 1;
            } else if (i == MUL) {
                ope[MUL] -= 1;
                solve(ans * nums[depth + 1], depth + 1);
                ope[MUL] += 1;
            } else {
                ope[DIV] -= 1;
                solve(ans / nums[depth + 1], depth + 1);
                ope[DIV] += 1;
            }
        }
    }

}
