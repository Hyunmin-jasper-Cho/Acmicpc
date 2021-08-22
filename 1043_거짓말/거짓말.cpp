#include <iostream>

int person[51];
int np_set[51];
bool know[51] = {false, };

int party[51][51];

void init();
void _union(int a, int b);
int _find(int x);

void merge_set(int arr[51], int sta, int end);

int main() {
    init();
    
    int N, M; scanf("%d %d", &N, &M);
    
    int np, f_np = 60; scanf("%d", &np);
    for (int i = 0; i < np; ++i) {
        scanf("%d", np_set + i);
        know[np_set[i]] = true;
        if (f_np > np_set[i]) f_np = np_set[i];
    } merge_set(np_set, 0, np);
    
    
    for (int i = 0; i < M; ++i) {
        scanf("%d", &(party[i][0]));
        int tp = party[i][0];
        
        for (int j = 1; j <= tp; ++j) {
            scanf("%d", &(party[i][j]));
        } merge_set(party[i], 1, tp + 1);
    }
    
    for (int i = M - 1; i >= 0; --i) {
        merge_set(party[i], 1, party[i][0] + 1);
    }
    
    int cnt = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 1; j <= party[i][0]; ++j) {
            if (person[party[i][j]] == f_np) {
                cnt++; break;
            }
        }
    }
    
    printf("%d", M - cnt);
    
    
    return 0;
}

void init() {
    for (int i = 0; i <= 50; ++i) {
        person[i] = i;
    }
}

int _find(int x) {
    if (x == person[x]) return x;
    return person[x] = _find(person[x]);
}

void _union(int a, int b) {
    int x = _find(a);
    int y = _find(b);
    
    if (x == y) return;
    
    if (know[x] and !know[y]) {
        person[y] = x;
    } else if (know[y] and !know[x]) {
        person[x] = y;
    } else {
        if (x < y) person[y] = x;
        else person[x] = y;
    }
}

void merge_set(int arr[51], int sta, int end) {
    for (int i = sta; i < end - 1; ++i) {
        _union(arr[i], arr[i + 1]);
    }
    for (int i = end - 1; i > sta; --i) {
        _union(arr[i], arr[i - 1]);
    }
}
