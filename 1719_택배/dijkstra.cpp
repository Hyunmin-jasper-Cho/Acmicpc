#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#define INF 300001

typedef std::pair<int, int> pos;

int N, M;
int dist[201][201];
int path[201][201];
using namespace std;

void init();

void dijkstra(int to, vector<pair<int, int>> adjacent[201]);

int main() {
    vector<pair<int, int>> adjacent[201];
    init();
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; ++i) {
        int to, at, cost; scanf("%d %d %d", &to, &at, &cost);
        adjacent[to].emplace_back(make_pair(at, cost));
        adjacent[at].emplace_back(make_pair(to, cost));
    }

    for (int i = 1; i <= N; ++i) {
        dijkstra(i, adjacent);
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j) printf("- ");
            else printf("%d ", path[j][i]);
        } printf("\n");
    }


    return 0;
}

void dijkstra(int to, vector<pair<int, int>> adjacent[201]) {
    priority_queue<pos, vector<pos>, greater<>> pq;
    pq.push({0, to});
    while (!pq.empty()) {
        int tmp_cost = pq.top().first;
        int tmp_index = pq.top().second; pq.pop();

        if (tmp_cost > dist[to][tmp_index]) continue;
        for (auto & itr : adjacent[tmp_index]) {
            if (dist[to][itr.first] > tmp_cost + itr.second) {
                dist[to][itr.first] = tmp_cost + itr.second;
                path[to][itr.first] = tmp_index;
                pq.push({dist[to][itr.first], itr.first});
            }
        }
    }
}

void init() {
    for (int i = 0; i <= 200; ++i) {
        for (int j = 0; j <= 200; ++j) {
            dist[i][j] = INF;
        }
    }
}
