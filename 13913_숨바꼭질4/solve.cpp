#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int main() {

    int ans[200000], idx = 0;
    int pre_node[100001] = {0, };
    bool vis[100001]; memset(vis, false, sizeof(vis));
    int a, b; scanf("%d %d", &a, &b);

    queue<int> q; q.push(a); vis[a] = true;
    while (!q.empty()) {

        if (vis[b]) break;

        int size = (int) q.size();
        for (int i = 0; i < size; ++i) {
            int val = q.front(); q.pop();

            if (val + 1 <= 100000) {
                if (!vis[val + 1]) {
                    vis[val + 1] = true;
                    pre_node[val + 1] = val;
                    q.push(val + 1);
                }
            }

            if (val != 0) {
                if (!vis[val - 1]) {
                    vis[val - 1] = true;
                    pre_node[val - 1] = val;
                    q.push(val - 1);
                }
            }

            if (val * 2 <= 100000) {
                if (!vis[val * 2]) {
                    vis[val * 2] = true;
                    pre_node[val * 2] = val;
                    q.push(val * 2);
                }
            }
        }
    }

    int tmp = b;
    ans[idx++] = tmp;
    while (true) {
        if (tmp == a) break;

        ans[idx++] = pre_node[tmp];
        tmp = pre_node[tmp];
    }

    printf("%d\n", idx - 1);
    for (int i = idx - 1; i >= 0; --i) {
        printf("%d ", ans[i]);
    }

    return 0;
}
