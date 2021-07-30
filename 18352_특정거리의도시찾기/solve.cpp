#include <iostream>
#include <functional>
#include <queue>
#include <vector>

#define INF 300001

void clr(int *arr, int n);

using namespace std;

int main() {

    bool found = false;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // N: 도시의 개수, M: 도로의 개수, K: 거리정보, X: 출발 도시의 번호
    int N, M, K, X;

    scanf("%d %d %d %d", &N, &M, &K, &X);
    int dist[N + 1]; clr(dist, N);
    pq.push(make_pair(0, X)); dist[X] = 0;


    vector<int> adjacent_node_of[N + 1];

    for (int i = 0; i < M; ++i) {

        int to, at;
        scanf("%d %d", &to, &at);
        adjacent_node_of[to].emplace_back(at);
    }


    while (!pq.empty()) {

        int cost = pq.top().first;
        int index = pq.top().second; pq.pop();

        for (auto & itr : adjacent_node_of[index]) {
            if (dist[itr] > cost + 1) {
                dist[itr] = cost + 1;
                pq.push(make_pair(cost + 1, itr));
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (dist[i] == K) {
            printf("%d\n", i);
            found = true;
        }
    }
    if (found) exit(0);
    printf("-1");

    return 0;
}

void clr(int *arr, int n) {
    for (int i = 0; i <= n; ++i) {
        arr[i] = INF;
    }
}
