// long long int 범위임을 자세히 보자..

#include <functional>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define INF 100000000001
#define MAX 500000

typedef long long int ll;

using namespace std;
int N, M;

void clr(ll arr[MAX]);

int main() {
    scanf("%d %d", &N, &M);
    vector<pair<ll, ll>> adjacent_node_of[N];
    ll lighten_node[MAX];
    ll dist[MAX]; clr(dist);


    memset(lighten_node, 1, sizeof(lighten_node));
    for (int i = 0; i < N; ++i) {
        scanf("%lld", lighten_node + i);
    } lighten_node[N - 1] = 0;


    for (int i = 0; i < M; ++i) {
        int to, at, cost; scanf("%d %d %d", &to, &at, &cost);
        if (lighten_node[to] == 1 or lighten_node[at] == 1) continue;

        adjacent_node_of[to].emplace_back(make_pair(at, cost));
        adjacent_node_of[at].emplace_back(make_pair(to, cost));
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {


        ll tmp_cost = pq.top().first;
        ll tmp_index = pq.top().second; pq.pop();

        if (dist[tmp_index] < tmp_cost) continue;
        for (auto & itr : adjacent_node_of[tmp_index]) {
            if (dist[itr.first] > tmp_cost + itr.second) {
                dist[itr.first] = tmp_cost + itr.second;
                pq.push(make_pair(dist[itr.first], itr.first));
            }
        }
    }


    if (dist[N - 1] == INF) printf("-1");
    else printf("%lld", dist[N - 1]);


    return 0;
}

void clr(ll arr[MAX]) {
    for (int i = 0; i < MAX; ++i) {
        arr[i] = INF;
    } arr[0] = 0;
}
