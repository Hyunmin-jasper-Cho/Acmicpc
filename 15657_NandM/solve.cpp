#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int *arr;
int *ans;

void solve(int depth);

int main() {

    scanf("%d %d", &N, &M);

    arr = new int[N];
    ans = new int[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", arr + i);
    } sort(arr, arr + N);

    solve(0);


    return 0;
}

void solve(int depth) {

    if (depth == M) {
        for (int i = 0; i < M; ++i) {
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }


    for (int i = 0; i < N; ++i) {

        if (depth != 0) {
            if (arr[i] < ans[depth - 1]) continue; // skip..
        } ans[depth] = arr[i];

        solve(depth + 1);


    }


}
