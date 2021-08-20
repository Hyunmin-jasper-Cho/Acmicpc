#include <iostream>

int N, M;
int parent[101];

void init();

int find(int x);
void merge(int a, int b);

int main() {
    scanf("%d %d", &N, &M); init();
    for (int i = 0; i < M; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        
        if (find(a) == find(b)) continue;
        
        merge(a, b);
    }
    
    int cnt = 0;
    for (int i = 2; i <= N; ++i) {
        if (find(i) == 1) cnt++;
    } printf("%d", cnt);
    
    return 0;
}

void init() {
    for (int i = 0; i <= N; ++i) {
        parent[i] = i;
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
    
    if (x < y) {
        parent[y] = x;
    } else parent[x] = y;
}
