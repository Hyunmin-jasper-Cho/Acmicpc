#include <iostream>
#include <functional>
#include <vector>
#include <queue>

#define INF 100000001

void clr(int *arr, int N);

using namespace std;

int main() {
    int N, M, sta, end; // 도시개수 N, 버스개수 M
    scanf("%d %d", &N, &M);
    int ans[N + 1]; clr(ans, N);

    //          at   cost                    to
    vector<pair<int, int>> adjacent_node_of[N + 1]; // v = 1, 2, ..., N

    //                 cost  index
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    for (int i = 0; i < M; ++i) {
        int to, at, cost;
        scanf("%d %d %d", &to, &at, &cost);
        adjacent_node_of[to].emplace_back(make_pair(at, cost)); // 인접 노드들 저장..
    }


    scanf("%d %d", &sta, &end);
    pq.push(make_pair(0, sta)); // 시작지점의 cost 를 0 으로 설정한다
    ans[sta] = 0;                      // 시작지점의 cost 를 0 으로 설정한다


    while (!pq.empty()) {
        // adjacent of sta..


        // 현재 노드와 가장 가까운 노드의 index 와 cost 를 얻는다.
        int cost = pq.top().first;
        int index = pq.top().second; pq.pop();

        // 이미 알아낸 cost 가 새로 알아낸 cost 보다 작다면.. skip..
        if (ans[index] < cost) continue;         // 이거 안하면 시간 초과..
        // 해당 노드의 인접 노드들을 탐색하는데...
        for (auto & itr : adjacent_node_of[index]) {
            // 기존의 알아놓았던 값이 새로이 알아낸 값보다 크다면..
            if (ans[itr.first] > cost + itr.second) {
                ans[itr.first] = cost + itr.second; // 값을 갈아치우고..
                pq.push(make_pair(ans[itr.first], itr.first)); // 바뀐 cost 와 index 를 pq 에 넣는다..
            }
        }

    }

    printf("%d", ans[end]);


    return 0;
}

void clr(int *arr, int N) {
    for (int i = 0; i <= N; ++i) {
        arr[i] = INF;
    }
}
