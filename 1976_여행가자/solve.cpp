#include <iostream>
#include <vector>

using namespace::std;

int N, M;
int _union[201];
int path[1001];
char input[1000], *last;
void init();

int find(int x);
void merge(int a, int b);

int main() {
    init();
    vector<int> ad[201];
    
    scanf("%d %d", &N, &M); getchar();
    for (int i = 1; i <= N; ++i) {
        fgets(input, 1000, stdin); last = input;
        for (int j = 1; j <= N; ++j) {
            if (strtol(last, &last, 10) == 1) {
                if (i < j) {
                    merge(i, j);
                } else merge(j, i);
            }
        }
    }
    
    if (M == 0) {
        printf("YES\n"); exit(0);
    }
    
    int std_p, tmp;
    scanf("%d", &tmp);
    std_p = find(tmp);
    for (int i = 0; i < M - 1; ++i) {
        scanf("%d", &tmp);
        tmp = find(tmp);
        if (tmp != std_p) {
            printf("NO\n"); exit(0);
        }
    }
    printf("YES\n");
    
    return 0;
}

void init() {
    for (int i = 0; i <= 200; ++i) {
        _union[i] = i;
    }
}

int find(int x) {
    if (x == _union[x]) return x;
    return _union[x] = find(_union[x]);
}
void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    
    if (x == y) return;
    
    _union[y] = x;
}
