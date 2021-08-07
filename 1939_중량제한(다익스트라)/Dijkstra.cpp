#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <queue>
#define INF 10000000000

using namespace std;
int N, M;

typedef long long int ll;
void clr(long long int *arr);

int main() {
    unordered_map<ll, int> done;

    scanf("%d %d", &N, &M);
    vector<pair<ll, ll>> adjacent_node_of[N + 1];
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>> pq;
    ll cost[N + 1]; clr(cost);
    bool vis[N + 1]; memset(vis, false, sizeof(vis));

    for (int i = 0; i < M; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        adjacent_node_of[a].emplace_back(make_pair(b, c));
        adjacent_node_of[b].emplace_back(make_pair(a, c));
    }

    int to, at; scanf("%d %d", &to, &at);
    cost[to] = 0;


    pq.push(make_pair(INF, to)); vis[to] = true;
    while (!pq.empty()) {

        ll tmp_cost = pq.top().first;
        ll tmp_idx = pq.top().second; pq.pop(); vis[tmp_idx] = true;

        if (done.contains(tmp_idx)) continue;

        // 구조적 문제로 같은 index 가 pq 에 여러번 들어올 수 있는데, 
        // 같은 작업을 pass 하기 위한 조치이다.
        done.insert(make_pair(tmp_idx, 1));

        for (auto & itr : adjacent_node_of[tmp_idx]) {
            if (!vis[itr.first]) {
                if (cost[itr.first] == INF) { // 한 번도 가지 않은 곳이라면..
                    if (tmp_cost == 0) cost[itr.first] = itr.second; // tmp_cost 가 0 인 곳은 시작점. 즉 시작점에 대한 예외처리이다.
                    else cost[itr.first] = (itr.second < tmp_cost ? itr.second : tmp_cost); // 지금가지 거쳐 온 값(tmp_cost)과 새로운 다리의 값(itr.second) 중 작은 값(무너지지 않으려면..) 으로 설정..
                } else { // 이미 방문 했더라면..
                    ll t_tmp;
                    if (tmp_cost == 0) t_tmp = itr.second;
                    else t_tmp = (itr.second < tmp_cost ? itr.second : tmp_cost); // 위의 과정을 한 뒤..

                    cost[itr.first] = (t_tmp > cost[itr.first] ? t_tmp : cost[itr.first]); // 이전에 방문했을 때 cost 와 새로구한 cost 를 비교 후 더 큰 값을 대입한다..
                }
                pq.push(make_pair(cost[itr.first], itr.first)); // pq 에 해당 지점 넣는다. 이 과정에서 같은 값이 여러번 들어올 수 있다.
            }
        }
    }


    printf("%lld", cost[at]);
    return 0;
}

void clr(long long int *arr) {
    for (int i = 0; i <= N; ++i) {
        arr[i] = INF;
    }
}
