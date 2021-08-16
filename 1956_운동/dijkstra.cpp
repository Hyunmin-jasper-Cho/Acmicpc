#include <iostream>
#include <functional>
#include <queue>
#define INF 4000001

int V, E;
using namespace std;
int dist[401][401];

void init();
void dijkstra(int sta, vector<pair<int, int>> ad[401]);

int main() {
    init();
    vector<pair<int, int>> ad[401];
    
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; ++i) {
        int to, at, cost;
        scanf("%d %d %d", &to, &at, &cost);
        ad[to].emplace_back(make_pair(at, cost));
    }
    
    for (int i = 1; i <= V; ++i) {
        dist[i][i] = 0;
        dijkstra(i, ad);
    }
    
    int minimum = INF;
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (i == j) continue;
            if (dist[i][j] == INF or dist[j][i] == INF) continue;
            
            if (minimum > dist[i][j] + dist[j][i]) {
                minimum = dist[i][j] + dist[j][i];
            }
        }
    }
    
    printf("%d", minimum >= INF ? -1 : minimum);
    
    
    return 0;
}

void dijkstra(int sta, vector<pair<int, int>> ad[401]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, sta});
    while (!pq.empty()) {
        int tmp_cost = pq.top().first;
        int tmp_index = pq.top().second; pq.pop();
                
        if (tmp_cost > dist[sta][tmp_index]) continue;
        for (auto & itr : ad[tmp_index]) {
            if (dist[sta][itr.first] > tmp_cost + itr.second) {
                dist[sta][itr.first] = tmp_cost + itr.second;
                pq.push({dist[sta][itr.first], itr.first});
            }
        }
    }
}

void init() {
    for (int i = 0; i <= 400; ++i) {
        for (int j = 0; j <= 400; ++j) {
            dist[i][j] = INF;
        }
    }
}
