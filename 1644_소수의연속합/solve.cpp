#include <iostream>
#include <cstring>
#include <cmath>
#define MAX 283146

typedef long long int ll;

int N;
bool is_prime[4000001];
int prime_set[MAX + 1], idx = 1;
ll sum[MAX + 1];

void init();

int main() {
    memset(is_prime, true, sizeof(is_prime));
    init(); scanf("%d", &N);

    int cnt = 0;
    int s = 0, e = 0;
    while (e >= s) {
        if (prime_set[s] > N) break;

        if (sum[e] - sum[s] > N) {
            s++;
        } else if (sum[e] - sum[s] < N) {
            e++;
        } else {
            cnt++;
            s++;
            e++;
        }
    }
    printf("%d", cnt);

    return 0;
}

void init() {
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 4; i <= 4000000; i += 2) {
        is_prime[i] = false;
    }

    for (int i = 3; i <= sqrt(4000000) + 1; i += 2) {
        for (int j = 2; i * j <= 4000000; ++j) {
            is_prime[i * j] = false;
        }
    }

    prime_set[0] = 0;
    for (int i = 0; i <= 4000000; ++i) {
        if (is_prime[i]) prime_set[idx++] = i;
    }

    sum[0] = 0;
    for (int i = 1; i <= MAX; ++i) {
        sum[i] = sum[i - 1] + prime_set[i];
    }
}
