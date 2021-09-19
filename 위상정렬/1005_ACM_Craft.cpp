#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#define LM 1000

int T, N, K, W;
int remain_time[LM + 1];
int cnt[LM + 1];

using namespace std;
typedef pair<int, int> dat;

priority_queue<dat, vector<dat>, greater<>> pq;
vector<int> ad[LM + 1];

void input();

int main() {
    cin >> T;
    
    while (T--) {
        input();
        
        while (!pq.empty()) {
            int node = pq.top().second;
            int b_time = pq.top().first;
            pq.pop();
            
            for (auto & itr : ad[node]) {
                cnt[itr]--;
                if (!cnt[itr]) {
                    remain_time[itr] += b_time;
                    pq.push({remain_time[itr], itr});
                }
            }
        }
        
        cout << remain_time[W] << "\n";
    }
    
    return 0;
}

void input() {
    for (int i = 0; i <= LM; ++i) {
        ad[i].clear();
    }
    
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", remain_time + i);
    }
    
    for (int i = 0; i < K; ++i) {
        int to, at;
        scanf("%d %d", &to, &at);
        ad[to].emplace_back(at);
        cnt[at]++;
    } cin >> W;
    
    for (int i = 1; i <= N; ++i) {
        if (!cnt[i]) pq.push({remain_time[i], i});
    }
}
