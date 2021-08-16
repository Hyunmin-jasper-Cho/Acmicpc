#include <iostream>
#include <cstring>
#include <queue>
#define INF 100001

int N, M;
bool vis[100001];
int dist[100001];
using namespace std;

void init();

int main() {
    init();
    memset(vis, false, sizeof(vis));
    scanf("%d %d", &N, &M);

    vis[N] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, N}); dist[N] = 0;

    while (!pq.empty()) {

        int size = (int) pq.size();
        for (int i = 0; i < size; ++i) {
            int tmp_cost = pq.top().first;
            int tmp_index = pq.top().second; pq.pop();

            if (tmp_cost > dist[tmp_index]) continue;

            if (tmp_index + 1 <= 100000) {
                if (!vis[tmp_index + 1]) {
                    if (tmp_cost + 1 < dist[tmp_index + 1]) {
                        dist[tmp_index + 1] = tmp_cost + 1;
                        pq.push({dist[tmp_index + 1], tmp_index + 1});
                    }
                }
            }

            if (tmp_index - 1 >= 0) {
                if (!vis[tmp_index - 1]) {
                    if (tmp_cost + 1 < dist[tmp_index - 1]) {
                        dist[tmp_index - 1] = tmp_cost + 1;
                        pq.push({dist[tmp_index - 1], tmp_index - 1});
                    }
                }
            }

            if (tmp_index * 2 <= 100000) {
                if (!vis[tmp_index * 2]) {
                    if (tmp_cost< dist[tmp_index * 2]) {
                        dist[tmp_index * 2] = tmp_cost;
                        pq.push({dist[tmp_index * 2], tmp_index * 2});
                    }
                }
            }

        }
    }

    printf("%d", dist[M]);

    return 0;
}

void init() {
    for (int i = 0; i <= 100000; ++i) {
        dist[i] = INF;
    }
}
