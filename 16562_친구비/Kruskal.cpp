#include <iostream>
#include <functional>
#include <cstring>
#include <queue>

using namespace::std;

int N, M, k;
bool vis[10001];
int parent[10001];
void init();

int find(int x);
void merge(int a, int b);

int main() {
    memset(vis, false, sizeof(vis));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    scanf("%d %d %d", &N, &M, &k); init();
    
    for (int i = 1; i <= N; ++i) {
        int v; scanf("%d", &v);
        pq.push({v, i});
    }
    
    for (int i = 0; i < M; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        
        if (a < b) merge(a, b);
        else merge(b, a);
    }
    
    int t_cost = 0;
    while (!pq.empty()) {
        int l_cost = pq.top().first;
        int l_idx = pq.top().second; pq.pop();
        
        if (!vis[find(l_idx)]) {
            vis[find(l_idx)] = true;
            t_cost += l_cost;
        }
    }
    
    if (t_cost > k) {
        printf("Oh no");
    } else printf("%d", t_cost);
    
    return 0;
}

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    // Assert: a < b
    int pa = find(a);
    int pb = find(b);
    
    if (pa == pb) return;
    
    parent[pb] = pa;
}

void init() {
    for (int i = 0; i <= N; ++i) {
        parent[i] = i;
    }
}
