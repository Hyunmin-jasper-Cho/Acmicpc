#include <iostream>
#include <algorithm>

using namespace std;

int R, N;
char arr[16]; // v = 0, 1, ... 15
char ans[16];
bool vis[16];

void solve(int depth, int vowel, int non_vowel);
bool is_vowel(char c);

bool is_reliable(int i, int depth);

int main() {

    char input[50];
    int idx = 0;

    scanf("%d %d", &R, &N); getchar();
    fgets(input, 50, stdin);

    for (int i = 0; i < N; ++i) {
        arr[i] = input[idx];
        idx += 2;
    } sort(arr, arr + N);

    solve(0, 0, 0);

    return 0;
}

void solve(int depth, int vowel, int non_vowel) {

    if (depth == R) {
        if (vowel >= 1 and non_vowel >= 2) {
            for (int i = 0; i < R; ++i) printf("%c", ans[i]);
            printf("\n");
        }
    }


    // total N
    for (int i = 0; i < N; ++i) {

        // 조건에 맞다면..
        if (is_reliable(i, depth)) {

            ans[depth] = arr[i]; // 현재 depth 에 저장하고..

            vis[i] = true; // 방문
            if (is_vowel(ans[depth])) vowel += 1;
            else non_vowel += 1;


            solve(depth + 1, vowel, non_vowel);


            vis[i] = false;
            if (is_vowel(ans[depth])) vowel -= 1;
            else non_vowel -= 1;

        }
    }
}

bool is_reliable(int i, int depth) {

    // 이미 방문했는지..
    if (vis[i]) return false;

    if (depth == 0) {
        if (i <= N - R) return true;
        else return false;
    } else {
        if (ans[depth - 1] >= arr[i]) {
            return false;
        } else return true;
    }
}

bool is_vowel(char c) {
    if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') {
        return true;
    } else return false;
}
