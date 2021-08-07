#include <iostream>
#define INF 1000000001

int N, S;

bool reliable(int e, int s);

int main() {
    scanf("%d %d", &N, &S);
    int arr[100001]; arr[0] = 0;
    int sum[100001]; sum[0] = 0;

    int least_len = INF;
    int s = 0, e = 0;

    for (int i = 1; i <= N; ++i) {
        scanf("%d", arr + i);
        sum[i] = arr[i] + sum[i - 1];
    }

    while (reliable(e, s)) {
        if (sum[e] - sum[s] >= S) {
            if (e == s) {
                least_len = 1;
            } else least_len = (e - s) < least_len ? (e - s) : least_len;
            s++;
        } else {
            e++;
        }

    }


    if (least_len == INF) {
        printf("0");
    } else printf("%d", least_len);

    return 0;
}

bool reliable(int e, int s) {
    if (e < s) return false;
    if (e > N or s > N) return false;
    return true;
}
