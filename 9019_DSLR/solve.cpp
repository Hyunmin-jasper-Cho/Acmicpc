#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main() {
    int test_case; scanf("%d", &test_case);
    for (int tc = 0; tc < test_case; ++tc) {

        char answer[100000] = {0, }, index = 0;
        int pre_index[10000];
        char pre_cmd[10000];

        bool vis[10000];
        memset(vis, false, sizeof(vis));


        int a, b; scanf("%d %d", &a, &b);
        // bfs
        int depth = 0;
        queue<int> q; q.push(a); vis[a] = true;
        while (!q.empty()) {
            int size = (int) q.size();

            if (vis[b]) break;

            for (int i = 0; i < size; ++i) {
                int cur_val = q.front(); q.pop();

                // D
                int D_val = (cur_val * 2) % 10000;
                if (!vis[D_val]) {
                    q.push(D_val);
                    pre_index[D_val] = cur_val;
                    pre_cmd[D_val] = 'D';
                    vis[D_val] = true;
                }

                // S
                int S_val;
                if (cur_val == 0) { S_val = 9999; }
                else { S_val = cur_val - 1; }
                if (!vis[S_val]) {
                    q.push(S_val);
                    pre_index[S_val] = cur_val;
                    pre_cmd[S_val] = 'S';
                    vis[S_val] = true;
                }

                // L
                int L_val = ((cur_val % 1000) * 10) + (cur_val / 1000);
                if (!vis[L_val]) {
                    q.push(L_val);
                    pre_index[L_val] = cur_val;
                    pre_cmd[L_val] = 'L';
                    vis[L_val] = true;
                }

                // R
                int R_val = (cur_val / 10) + ((cur_val % 10) * 1000);
                if (!vis[R_val]) {
                    q.push(R_val);
                    pre_index[R_val] = cur_val;
                    pre_cmd[R_val] = 'R';
                    vis[R_val] = true;
                }

            } depth++;
        }



        int tmp = b;
        while (true) {
            if (tmp == a) break;

            answer[index++] = pre_cmd[tmp];
            tmp = pre_index[tmp];
        }


        for (int i = index - 1; i >= 0; --i) {
            printf("%c", answer[i]);
        } printf("\n");

    }

    return 0;
}
