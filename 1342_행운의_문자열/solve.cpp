#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int alpha[26], len, cnt = 0;

void solve(unsigned char prev_char, int depth);
bool is_reliable(unsigned char prev, int i);

int main() {

    vector<char> v;

    char input[12];
    scanf("%s", input);

    len = (int) strlen(input);
    for (int i = 0; i < len; ++i) {
        alpha[input[i] - 'a'] += 1;
        if (alpha[input[i] - 'a'] == 1) {
            v.emplace_back(input[i]);
        }
    }

    for (unsigned char sta_char : v) {

        alpha[sta_char - 'a'] -= 1; // 하나 삭제해주고..
        solve(sta_char, 1);
        alpha[sta_char - 'a'] += 1; // 다시 추가해준다..
    }

    printf("%d", cnt);

    return 0;
}

bool is_reliable(unsigned char prev_char, int i) {
    if (alpha[i] == 0) return false;
    if (prev_char - 'a' == i) return false;
    return true;
}

void solve(unsigned char prev_char, int depth) {

    if (depth == len) {
        cnt += 1; // 개수 하나 증가..
        return;   // 돌아간다..
    }


    // 현재 depth 에 대해서 총 알파벳의 종류만큼 실행..
    for (int i = 0; i < 26; ++i) {

        if (!is_reliable(prev_char, i)) continue; // skip..


        // 해당하는 알파벳을 하나 사용하고..
        alpha[i] -= 1;

        // 더 깊이 들어간다...
        solve((i + 'a'), depth + 1);

        // 이후 빠져나왔다면 알파벳을 다시 돌려준다
        alpha[i] += 1;

    }
}
