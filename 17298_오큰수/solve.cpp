#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> s;

    int N; scanf("%d", &N);

    int val[N + 1]; val[0] = 0;
    int NGE[N + 1]; NGE[0] = -1;

    scanf("%d", val + 1);
    for (int i = 2; i <= N; ++i) {

        scanf("%d", val + i);
        if (val[i] > val[i - 1]) {
            NGE[i - 1] = val[i];
        } else NGE[i - 1] = -1;
    } NGE[N] = -1;


    for (int i = N - 1; i >= 1; --i) {

        if (NGE[i] != -1) {
            if (!s.empty()) {
                while (*(prev(s.end())) < NGE[i]) {
                    s.erase(prev(s.end())); // 스택에서 제거해 주어야 한다... (안그러면 time over..)
                }
            } s.emplace_back(NGE[i]); continue;
        }

        if (NGE[i] == -1) {

            while (!s.empty()) {
                if (*(prev(s.end())) > val[i]) {
                    NGE[i] = *(prev(s.end())); 
                    break;
                } else s.erase(prev(s.end()));
            }

        }
    }

    for (int i = 1; i <= N; ++i) {
        printf("%d ", NGE[i]);
    }


    return 0;
}
