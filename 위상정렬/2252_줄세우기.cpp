#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#define LM 32000

using namespace std;

int N, M;
int cnt[LM + 1] = {0, };
bool vis[LM + 1] = {false, };

vector<int> ad[LM + 1];
priority_queue<int, vector<int>, greater<>> pq;

void input();

int main() {
    input();
    
    while (!pq.empty()) {
        int size = (int) pq.size();
        
        while (size--) {
            int node = pq.top(); pq.pop(); vis[node] = true;
            cout << node << " ";
            
            for (auto &itr : ad[node]) {
                cnt[itr]--;
                if (!cnt[itr]) pq.push(itr);
            }
        }
        
    } cout << '\n';
    
    return 0;
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int to, at;
        scanf("%d %d", &to, &at);
        cnt[at]++; ad[to].emplace_back(at);
    }
    
    for (int i = 1; i <= N; ++i) {
        if (!cnt[i]) {
            pq.push(i);
        }
    }
}

