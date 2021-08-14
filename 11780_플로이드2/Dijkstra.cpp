#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#define INF 10000001

int N, M;
int dist[101][101];
int ans[1001], idx = 0;
using namespace std;

void init();
int before[101][101];
void dijkstra(int to, std::vector<std::pair<int, int>> *adjacent);

int main() {
    init();

    scanf("%d %d", &N, &M);

    vector<pair<int, int>> adjacent[N + 1];
    for (int i = 0; i < M; ++i) {
        int to, at, cost; scanf("%d %d %d", &to, &at, &cost);
        adjacent[to].emplace_back(make_pair(at, cost));
    }

    for (int i = 1; i <= N; ++i) {
        dijkstra(i, adjacent);
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (dist[i][j] >= INF) dist[i][j] = 0;

            printf("%d ", dist[i][j]);
        } printf("\n");
    }


    for (int i = 1; i <= N; ++i) {


        for (int j = 1; j <= N; ++j) {
            if (dist[i][j] == 0) {
                printf("0\n"); continue;
            }

            idx = 0;
            int tmp = j;
            while (tmp != i) {
                ans[idx++] = tmp;
                tmp = before[i][tmp];
            } ans[idx++] = tmp;


            printf("%d ", idx);
            for (int k = idx - 1; k >= 0; --k) {
                printf("%d ", ans[k]);
            } printf("\n");
        }
    }

    return 0;
}

void dijkstra(int to, std::vector<std::pair<int, int>> *adjacent) {
    dist[to][to] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, to});
    while (!pq.empty()) {

        int tmp_cost = pq.top().first;
        int tmp_index = pq.top().second; pq.pop();
        if (tmp_cost > dist[to][tmp_index]) continue;
        for (auto & itr : adjacent[tmp_index]) {
            if (dist[to][itr.first] > tmp_cost + itr.second) {
                dist[to][itr.first] = tmp_cost + itr.second;
                before[to][itr.first] = tmp_index;
                pq.push({dist[to][itr.first], itr.first});
            }
        }
    }
}

void init() {
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) {
            dist[i][j] = INF;
        }
    }
}
