#include <iostream>


int main() {
    int map[1001][1001];
    bool vis[1001][1001];


    int N, M, X; scanf("%d %d %d", &N, &M, &X);

    for (int i = 0; i < M; ++i) {
        int to, at, cost; scanf("%d %d %d", &to, &at, &cost);
        if (map[to][at] == 0) { map[to][at] = cost;
            vis[to][at] = true;
        } else { map[to][at] = (map[to][at] < cost ? map[to][at] : cost); }
    }

    for (int i = 1; i <= N; ++i) {
        vis[i][i] = true;
    }

    for (int k = 1; k <= N; ++k) {

        if (k == 3) {
            int val = 3;
        }

        for (int to = 1; to <= N; ++to) {
            for (int at = 1; at <= N; ++at) {

                if (!vis[to][k] or !vis[k][at]) continue; // 거쳐갈 수 없음..

                // 현재 지점이 방문하지 않은 곳이라면..
                if (!vis[to][at]) {
                    map[to][at] = map[to][k] + map[k][at];
                    vis[to][at] = true;
                } else { // 이미 방문 했더라면..
                    if (map[to][at] > map[to][k] + map[k][at]) {
                        map[to][at] = map[to][k] + map[k][at];
                    }
                }

            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        int tmp = map[i][X] + map[X][i];
        ans = (ans > tmp ? ans : tmp);
    }

    printf("%d", ans);


    return 0;
}
