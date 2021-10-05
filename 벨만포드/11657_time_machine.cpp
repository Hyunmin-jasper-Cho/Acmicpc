#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 50000001
#define ll long long int

int N, M;
ll dist[501];
using namespace std;
typedef pair<int, int> type;
vector<type> ad[501]; // dest, cost

void input();

int main() {
    input();
    
    bool infinite_cycle = false;
    for (int i = 0; i < N; ++i) {
        
        for (int j = 1; j <= N; ++j) {
            
            for (auto & itr : ad[j]) {
                if (dist[j] != INF and dist[itr.first] > dist[j] + itr.second) {
                    dist[itr.first] = dist[j] + itr.second;
                    if (i == N - 1) infinite_cycle = true;
                }
            }
            
        }
    }
    if (infinite_cycle) {
        cout << -1 << endl;
    } else {
        for (int i = 2; i <= N; ++i) {
            printf("%lld\n", dist[i] == INF ? -1 : dist[i]);
        }
    }
    
    return 0;
}

void input() {
    fill(dist, dist + 501, INF);
    
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int to, at, cost;
        scanf("%d %d %d", &to, &at, &cost);
        
        ad[to].emplace_back(make_pair(at, cost));
    }
    dist[1] = 0;
}
