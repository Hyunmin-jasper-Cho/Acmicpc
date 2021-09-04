#include <iostream>
#include <functional>
#include <vector>
#include <queue>

#define LM 200000

using namespace std;
typedef long long int ll;
typedef pair<ll, pair<ll, ll>> DAT;



ll _find(ll x);
void init();



int N, M, tmp, cnt = 0;
ll parent[LM + 1];
ll total = 0;

int main() {
    
    while (true){
            
        init();
        
        priority_queue<DAT, vector<DAT>, greater<>> pq;
        scanf("%d %d", &M, &N);
        
        
        if (M == 0 and N == 0) break;
        
        
        for (int i = 0; i < N; ++i) {
            ll a, b, len;
            scanf("%lld %lld %lld", &a, &b, &len);
            pq.push({len, {a, b}}); total += len;
        }
        
        ll usage = 0;
        while (cnt != N - 1 and !pq.empty()) {
            ll cost = pq.top().first;
            ll a = pq.top().second.first, b = pq.top().second.second;
            pq.pop();
            
            ll ances_a = _find(a), ances_b = _find(b);
            if (ances_a == ances_b) continue;
            
            usage += cost;
            if (ances_a < ances_b) parent[ances_b] = ances_a;
            else parent[ances_a] = ances_b;
            cnt++;
        } printf("%lld\n", total - usage);
        
    }
    
    return 0;
}

ll _find(ll x) {
    if (x == parent[x]) return x;
    
    return parent[x] = _find(parent[x]);
}

void init() {
    for (int i = 0; i <= LM; ++i) {
        parent[i] = i;
    } total = 0; cnt = 0;
}
