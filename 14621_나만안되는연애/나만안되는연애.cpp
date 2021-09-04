#include <iostream>
#include <functional>
#include <cstring>
#include <vector>
#include <queue>
#define LM 1000

using namespace std;
typedef pair<int, pair<int, int>> dat;
int parent[LM + 1], N, M;
char sex[LM + 1], str[LM * 3];

priority_queue<dat, vector<dat>, greater<>> pq;

void init();
int find(int x);
int kruskal();

int main() {
    
    init();
    
    printf("%d", kruskal());
    
    return 0;
}


void init() {
    memset(sex, 0, sizeof(sex));
    for (int i = 0; i <= LM; ++i) parent[i] = i;
    scanf("%d %d", &N, &M); getchar();
    
    int idx = 1;
    fgets(str, LM * 3, stdin);
    for (int i = 0; i < (int) strlen(str); i += 2) {
        sex[idx++] = str[i];
    }
    
    
    for (int i = 0; i < M; ++i) {
        
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        pq.push({d, {u, v}});
    }
}

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}


int kruskal() {
    int cnt = 0, usage = 0;
    while (cnt != N - 1 and !pq.empty()) {
        int cost = pq.top().first;
        int u = pq.top().second.second;
        int v = pq.top().second.first; pq.pop();
        
        if (sex[u] == sex[v]) continue;
        
        int ances_u = find(u), ances_v = find(v);
        if (ances_u == ances_v) continue;
        
        usage += cost;
        
        if (ances_u < ances_v) parent[ances_v] = ances_u;
        else parent[ances_u] = ances_v;
        
        cnt++;
    }
    
    if (cnt != N - 1) return -1;
    return usage;
}
