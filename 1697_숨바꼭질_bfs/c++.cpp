#include <iostream>
#include <functional>
#include <queue>

int N, K;
using namespace std;
int vis[100001] = {0, };

int main() {
    queue<int> pq;
    
    scanf("%d %d", &N, &K);
    int mx = 2 * K < 100000 ? 2 * K : 100000;
    
    if (N == K) {
        printf("0"); return 0;
    } else if (N > K) {
        printf("%d", N - K); return 0;
    }
    
    pq.push(N); vis[N] = 1;
    
    int time = 0;
    while (!pq.empty()) {
        if (vis[K]) break;
        
        int size = (int) pq.size();
        for (int i = 0; i < size; ++i) {
            int cv = pq.front(); pq.pop();
            
            if (cv < K and cv * 2 <= mx) {
                if (!vis[cv * 2]) {
                    vis[cv * 2] = 1;
                    pq.push(cv * 2);
                }
            } if (cv + 1 <= mx) {
                if (!vis[cv + 1]){
                    vis[cv + 1] = 1;
                    pq.push(cv + 1);
                }
            } if (cv > 0) {
                if (vis[cv - 1] == 0) {
                    vis[cv - 1] = 1;
                    pq.push(cv - 1);
                }
            }
        } time++;
    }
    
    printf("%d", time);
    
    return 0;
}
