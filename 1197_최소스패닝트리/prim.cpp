#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>

int V, E;

using namespace std;
typedef pair<int, int> type;
priority_queue<type, vector<type>, greater<>> pq;
vector<type> ad[10001];
bool vis[10001];



void input();

int main() {
    
    input();
    
    // sta node: 1
    pq.push({0, 1});
    long long int total = 0;
    
    while (!pq.empty()) {
        int tmp_cost = pq.top().first;
        int tmp_node = pq.top().second;
        pq.pop();
        
        
        
        
        if (vis[tmp_node]) continue; // skip
        
        
        
        vis[tmp_node] = true; // 방문처리..
        total += tmp_cost;
        
        for (auto & itr : ad[tmp_node]) {
            pq.push({itr.second, itr.first});
        }
    }
    
    cout << total << "\n";
    return 0;
}

void input() {
    fill(vis, vis + 10000, false);
    cin >> V >> E;
    for (int i = 0; i < E; ++i) {
        int to, at, cost;
        scanf("%d %d %d", &to, &at, &cost);
        ad[to].emplace_back(make_pair(at, cost));
        ad[at].emplace_back(make_pair(to, cost));
    }
}
