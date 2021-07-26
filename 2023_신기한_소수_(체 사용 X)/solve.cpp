#include <iostream>
#include <cmath>

using namespace std;

int N;
int ans[8];

void solve(int n);

bool is_prime(int i, int n);

int main() {

    char input[3];
    fgets(input, 3, stdin);

    N = (int) strtol(input, nullptr, 10);


    // 시작은 무조건 2, 3, 5, 7
    ans[0] = 2;
    solve(1);

    ans[0] = 3;
    solve(1);

    ans[0] = 5;
    solve(1);

    ans[0] = 7;
    solve(1);



    return 0;
}

void solve(int n) {

    if (n == N) {
        for (int i = 0; i < N; ++i) {
            printf("%d", ans[i]);
        } printf("\n");
    }

    // 현재 depth 에 대해서 총 5번 반복 (짝수 제외..)
    for (int i = 1; i <= 9; i+=2) {

        if (is_prime(i, n)) {  // 소수라면..
            ans[n] = i;    // 추가한다..
            solve(n + 1);      // 더 깊이 들어간다...
        }

    }
}

bool is_prime(int i, int n) {

    int sum = 0;
    for (int itr = 0; itr < n; ++itr) {
        sum += (ans[itr] * (int) pow(10, n - itr));
    } sum += i;


    if (sum % 2 == 0) return false;

    for (int itr = 3; itr <= sqrt(sum) + 1; ++itr) {
        if (sum % itr == 0) return false;
    } return true;
}
