#include <iostream>
#include <functional>
#include <vector>
#include <queue>

#define INF 1000001

using namespace std;

void dijkstra(int time[1001], priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq,
              vector<pair<int, int>> adjacent_node[1001], int start_point);

void clr(int arr[1001][1001]);

int main() {
    int remain_time[1001][1001]; clr(remain_time);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<pair<int, int>> adjacent_node_of[1001];

    int N, M, X; scanf("%d %d %d", &N, &M, &X);


    for (int i = 0; i < M; ++i) {
        int to, at, cost; scanf("%d %d %d", &to, &at, &cost);
        adjacent_node_of[to].emplace_back(make_pair(at, cost));
    }

    for (int i = 1; i <= N; ++i) {
        dijkstra(remain_time[i], pq, adjacent_node_of, i);
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        int tmp = remain_time[X][i] + remain_time[i][X];
        ans = (ans > tmp ? ans : tmp);
    }

    printf("%d", ans);

    return 0;
}

void clr(int arr[1001][1001]) {
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= 1000; ++j) {
            arr[i][j] = INF;
        }
    }
}

void dijkstra(int time[1001], priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq,
              vector<pair<int, int>> adjacent_node[1001], int start_point) {

    pq.push(make_pair(0, start_point));
    time[start_point] = 0; // 시작지점의 cost 를 0 으로 설정한다..

    while (!pq.empty()) {
        int cost = pq.top().first;
        int index = pq.top().second; pq.pop();

        for (auto & itr : adjacent_node[index]) {
            if (time[itr.first] > cost + itr.second) {
                time[itr.first] = cost + itr.second;
                pq.push(make_pair(time[itr.first], itr.first));
            }
        }
    }
}
