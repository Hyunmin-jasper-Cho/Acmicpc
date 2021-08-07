// 1 을 묶는가? 에 대한 예외처리가 필요했다

#include <iostream>
#include <algorithm>

int main() {
    int N; scanf("%d", &N);
    int arr[10000];

    int neg = 0, pos = 0;
    int sum = 0;

    for (int i = 0; i < N; ++i) {
        scanf("%d", arr + i);
        if (arr[i] < 0) neg++;
        else if (arr[i] > 0) pos++;
    } std::sort(arr, arr + N);


    if (neg % 2 == 0) {
        for (int i = 0; i <= neg - 2; i += 2) {
            sum += arr[i] * arr[i + 1];
        }
    } else {
        for (int i = 0; i <= neg - 3; i += 2) {
            sum += arr[i] * arr[i + 1];
        }
        if (neg != N) {
            if (arr[neg] == 0) {}
            else sum += arr[neg - 1];
        } else sum += arr[neg - 1];
    }

    if (pos % 2 == 1) {
        for (int i = N - 1; i >= N - (pos) + 2; i -= 2) {
            if (arr[i] != 1 and arr[i - 1] != 1) {
                sum += arr[i] * arr[i - 1];
            } else sum += (arr[i] + arr[i - 1]);
        } sum += arr[N - (pos)];
    } else {
        for (int i = N - 1; i >= N - (pos) + 1; i -= 2) {
            if (arr[i] != 1 and arr[i - 1] != 1) {
                sum += arr[i] * arr[i - 1];
            } else sum += (arr[i] + arr[i - 1]);
        }
    }


    printf("%d", sum);

    return 0;
}
