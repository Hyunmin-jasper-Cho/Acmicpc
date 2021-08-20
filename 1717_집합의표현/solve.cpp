#include <iostream>

int N, M;
int _union[1000001];

void init();
void merge(int a, int b);
int find(int x);

int main() {
    init();
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < M; ++i) {
        int cmd, a, b;
        scanf("%d %d %d", &cmd, &a, &b);
        
        if (cmd == 0) { // merge..
            merge(a, b);
        } else { // find..
            if (find(a) == find(b)) {
                printf("YES\n");
            } else printf("NO\n");
        }
    }
    
    return 0;
}

void merge(int a, int b) {
    // @Assert a < b
    int x = find(a);
    int y = find(b);
    
    if (y == x) return; // already linked
    
    _union[y] = x;
}

int find(int x) {
    if (x == _union[x]) return x;
    
    return _union[x] = find(_union[x]);
}

void init() {
    for (int i = 0; i <= 1000000; ++i) {
        _union[i] = i;
    }
}
