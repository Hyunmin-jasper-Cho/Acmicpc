#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#define INF 800001

using namespace std;

void clr(int *arr, int N);

void dijkstra(int *arr, int start_point, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq,
              vector<pair<int, int>> *adjacent_node_of);

int main() {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int V, E; scanf("%d %d", &V, &E);

    int from_start_dist[V + 1]; clr(from_start_dist, V);
    int from_second_dist[V + 1]; clr(from_second_dist, V);
    int from_final_dist[V + 1]; clr(from_final_dist, V);

    vector<pair<int, int>> adjacent_node_of[V + 1];
    for (int i = 0; i < E; ++i) {
        int A, B, cost;
        scanf("%d %d %d", &A, &B, &cost);

        // 양방향 연결..
        adjacent_node_of[A].emplace_back(make_pair(B, cost));
        adjacent_node_of[B].emplace_back(make_pair(A, cost));
    }

    int N1, N2; scanf("%d %d", &N1, &N2);


    // STA -> N1 -> N2 -> N
    // 또는
    // STA -> N2 -> N1 -> N
    // 을 구해보고.. 둘다 INF 보다 크거나 같다면 -> -1 반환..

    dijkstra(from_start_dist, 1, pq, adjacent_node_of);
    dijkstra(from_second_dist, N1, pq, adjacent_node_of);
    dijkstra(from_final_dist, N2, pq, adjacent_node_of);
    long long int ans1 = from_start_dist[N1] + from_second_dist[N2] + from_final_dist[V];

    clr(from_second_dist, V); clr(from_final_dist, V);

    dijkstra(from_second_dist, N2, pq, adjacent_node_of);
    dijkstra(from_final_dist, N1, pq, adjacent_node_of);
    long long int ans2 = from_start_dist[N2] + from_second_dist[N1] + from_final_dist[V];

    if (ans1 >= INF and ans2 >= INF) printf("-1");
    else printf("%lld", ans1 < ans2 ? ans1 : ans2);
    return 0;
}

void dijkstra(int *arr, int start_point, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq,
              vector<pair<int, int>> *adjacent_node_of) {
    arr[start_point] = 0;
    pq.push(make_pair(0, start_point)); // cost: 0, 시작점: 1
    while (!pq.empty()) {

        int cost = pq.top().first;
        int index = pq.top().second; pq.pop(); // 시작점에서 가장 가까운 노드를 선택하고..

        for (auto & itr : adjacent_node_of[index]) { // 그 노드의 인접 노드들에 대해서..
            if (arr[itr.first] > cost + itr.second) {
                arr[itr.first] = cost + itr.second;
                pq.push(make_pair(arr[itr.first], itr.first));
            }
        }
    }
}

void clr(int *arr, int N) {
    for (int i = 0; i <= N; ++i) {
        arr[i] = INF;
    }
}
