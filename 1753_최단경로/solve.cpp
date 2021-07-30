#include <iostream>
#include <functional>
#include <vector>
#include <queue>

#define INF 200001

using namespace std;

int main() {

    //                 cost, index
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    int V, E, s;
    scanf("%d %d %d", &V, &E, &s);

    vector<pair<int, int>> adjacent_node_of[V + 1];
    int d[V + 1];

    for (int i = 1; i <= V; ++i) {

        if (i == s) {
            d[i] = 0;
            pq.push(make_pair(0, s)); // 시작점을 pq 에 넣어둔다..
        } else {
            d[i] = INF;
        }
    }


    for (int i = 0; i < E; ++i) {
        int to, at, cost;
        scanf("%d %d %d", &to, &at, &cost);
        adjacent_node_of[to].emplace_back(make_pair(at, cost)); // 2차원 배열 대신 vector 사용..
    }

    while (!pq.empty()) { // 이것땜에 삽질함.. pq.empty()..
        int least_cost = pq.top().first;       // 시작점에서 가장 가까운 노들 가는 cost
        int index = pq.top().second; pq.pop(); // 위의 노드의 index

        for (auto & itr : adjacent_node_of[index]) {
                // itr.second   : index 노드에서 종단점에 가는 거리
                // least_cost   : 시작 노드에서 index 노드로 가는 거리
                // d[itr->first]: 현재 알고있는 시작에서 종단점으로 가는 거리
            if (itr.second + least_cost < d[itr.first]) {
                d[itr.first] = itr.second + least_cost;
                pq.push(make_pair(d[itr.first], itr.first));
            }
        }

    }

    for (int i = 1; i <= V; ++i) {
        if (d[i] >= INF) printf("INF\n");
        else printf("%d\n", d[i]);
    } exit(0);

}
