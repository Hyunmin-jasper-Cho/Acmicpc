// * 최단거리는 최단거리들의 합이다.

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#define INF 100000001

using namespace std;

int N, M;

void clr(int arr[1001]);

int main() {
    scanf("%d %d", &N, &M);

    // index, cost
    vector<pair<int, int>> adjacent_node_of[N + 1];
    int dist[1001]; clr(dist);
    int just_before_nodes[1001];
    int route_arr[1001] = {0, }, route_index = 0;

    memset(just_before_nodes, -1, sizeof(just_before_nodes));

    for (int i = 0; i < M ; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        adjacent_node_of[a].emplace_back(make_pair(b, c));
    } int to, at; scanf("%d %d", &to, &at);
    dist[to] = 0; just_before_nodes[to] = 0;


    // cost, index
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push(make_pair(0, to)); // start_point
    while (!pq.empty()) {
        int size = pq.size();

        for (int i = 0; i < size; ++i) {
            int tmp_cost = pq.top().first;
            int tmp_index = pq.top().second; pq.pop();

            if (tmp_cost > dist[tmp_index]) continue;
            for (auto & itr : adjacent_node_of[tmp_index]) {
                if (dist[itr.first] > tmp_cost + itr.second) {
                    just_before_nodes[itr.first] = tmp_index; // 직전의 최단 거리를 갖는 노드를 저장한다..

                    dist[itr.first] = tmp_cost + itr.second;
                    pq.push(make_pair(dist[itr.first], itr.first));
                }
            }
        }
    }

    printf("%d\n", dist[at]);


    int cnt = 0;
    int tmp = at;

    route_arr[route_index++] = tmp;
    cnt++;
    while (tmp != to) {
        tmp = just_before_nodes[tmp];
        route_arr[route_index++] = tmp;
        cnt++;
    }

    printf("%d\n", cnt);
    for (int i = route_index - 1; i >= 0; --i) {
        printf("%d ", route_arr[i]);
    }


    return 0;
}

void clr(int arr[1001]) {
    for (int i = 0; i < 1001; ++i) {
        arr[i] = INF;
    }
}
