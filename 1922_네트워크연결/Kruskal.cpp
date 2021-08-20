#include <iostream>
#include <functional>
#include <queue>


int N, M;
int a, b, cost;
int parent[1001];
using namespace::std;

void init();
void merge(int a, int b);
int find(int x);

int main() {
    init();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d %d %d", &a, &b, &cost);
        if (a != b) pq.push({cost, {a, b}});
    }
    
    int t_cost = 0;
    int cnt = 0;
    while (cnt != N - 1) {
        int l_cost = pq.top().first;
        int l1 = pq.top().second.first;
        int l2 = pq.top().second.second; pq.pop();
        
        
        if (find(l1) == find(l2)) continue;
        
        t_cost += l_cost;
        
        if (l1 < l2) {
            merge(l1, l2);
        } else merge(l2, l1);
        cnt++;
    }
    
    printf("%d", t_cost);
    
    return 0;
}

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    
    if (x == y) return;
    
    parent[y] = x;
}

void init() {
    for (int i = 0; i <= 1000; ++i) {
        parent[i] = i;
    }
}
