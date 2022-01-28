#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> ad[32001];
priority_queue<int, vector<int>, greater<>> pq;

int N, M; // N = 32'000, M = 100'000
int cnt[32001] = {0, };

void input();

int main() {
    input();
    
    while (!pq.empty()) {
        int problem_num = pq.top(); pq.pop();
        printf("%d ", problem_num);
        
        for (auto & itr : ad[problem_num]) {
            cnt[itr]--;
            if (cnt[itr] == 0) pq.push(itr);
        }
    }
    return 0;
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int to, at;
        scanf("%d %d", &to, &at);
        ad[to].emplace_back(at);
        cnt[at]++;
    }
    
    for (int i = 1; i <= N; ++i) {
        if (cnt[i] == 0) pq.push(i);
    }
    
    
}

