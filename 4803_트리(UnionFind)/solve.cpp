#include <iostream>
#include <cstring>

using namespace::std;

int N, M;
int parent[501];
bool vis[501];
bool cycle[501];

void init();

int find(int x);
void merge(int a, int b);

int main() {
    int idx = 1;
    while (true) {
        init();
        
        scanf("%d %d", &N, &M);
        
        if (N == 0 and M == 0) return 0;
        
        for (int i = 0; i < M; ++i) {
            int a, b; scanf("%d %d", &a, &b);
            
            if (a == b) continue;
            
            if (find(a) != find(b)) { // 조상이 다르다면..
                if (a < b) {
                    if (cycle[find(b)]) cycle[find(a)] = true; // 만약 합쳐질 노드가 cycle 을 가진다면 합치는 노드도 cycle 을 갖게 된다.
                    merge(a, b); // 합친다.
                } else {
                    if (cycle[find(a)]) cycle[find(b)] = true;
                    merge(b, a);
                }
            } else { // 조상이 같으면 cycle 이 존재한다는 뜻...
                if (a < b) {
                    cycle[find(a)] = true;
                } else {
                    cycle[find(b)] = true;
                }
            }
        }
        
        int cnt = 0;
        for (int i = 1; i <= N; ++i) {
            
            if (!cycle[find(i)] and !vis[find(i)]) { // cycle 이 없고 해당 집합을 방문하지 않았다면..
                cnt++;
                vis[find(i)] = true;
            }
        }
        
        if (cnt == 0) {
            printf("Case %d: No trees.\n", idx++);
        } else if (cnt == 1) {
            printf("Case %d: There is one tree.\n", idx++);
        } else {
            printf("Case %d: A forest of %d trees.\n", idx++, cnt);
        }
    }
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
    for (int i = 0; i <= 500; ++i) {
        parent[i] = i;
    }
    memset(vis, false, sizeof(vis));
    memset(cycle, false, sizeof(cycle));
}
