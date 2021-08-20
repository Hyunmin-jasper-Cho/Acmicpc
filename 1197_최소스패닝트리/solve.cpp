#include <iostream>
#include <functional>
#include <vector>
#include <queue>

#define INF 10000000000

typedef long long int ll;

int V, E;
using namespace std;

ll parent[10001];

ll find(ll x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]); // 부모의 부모 찾기...
}

void merge(ll a, ll b) {
    ll a_p = find(a);
    ll b_p = find(b);
    
    if (a_p == b_p) return; // already Linked
    
    parent[b_p] = a_p;
}

void init();

int main() {
    init();
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<>> pq;
    vector<int> ad[10001];
    
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; ++i) {
        ll a, b, cost;
        scanf("%lld %lld %lld", &a, &b, &cost);
        
        ad[a].emplace_back(b);
        ad[b].emplace_back(a);
        
        
        if (a < b) pq.push({cost, {a, b}});
        else pq.push({cost, {b, a}});
    }
    
    
    ll cost = 0, cnt = 0;
    while (cnt != V - 1) {
        ll l_cost = pq.top().first;
        ll l1 = pq.top().second.first; // smaller
        ll l2 = pq.top().second.second; pq.pop(); // bigger
        
        if (find(l1) == find(l2)) continue;
        
        cost += l_cost;
        merge(l1, l2);
        cnt++;
    }
    
    printf("%lld", cost);
    
    return 0;
}

void init() {
    for (int i = 0; i <= 10000; ++i) {
        parent[i] = i;
    }
}

