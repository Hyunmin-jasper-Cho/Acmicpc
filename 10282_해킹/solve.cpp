#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define INF 20000001

void clr(int arr[10001]);

using namespace std;

int main() {

    int test_case; scanf("%d", &test_case);
    for (int tc = 0; tc < test_case; ++tc) {



        int dist[10001]; clr(dist);


        int N, D, M; scanf("%d %d %d", &N, &D, &M);
        dist[M] = 0; // start_point

        vector<pair<int, int>> adjacent_node_of[N + 1];

        for (int i = 0; i < D; ++i) {
            int at, to, delay_time; scanf("%d %d %d", &at, &to, &delay_time);
            adjacent_node_of[to].emplace_back(make_pair(at, delay_time));
        }


        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, M});

        while (!pq.empty()) {
            int size = (int) pq.size();
            for (int i = 0; i < size; ++i) {

                int tmp_cost = pq.top().first;
                int tmp_index = pq.top().second;
                pq.pop();

                if (dist[tmp_index] < tmp_cost) continue;
                for (auto & itr : adjacent_node_of[tmp_index]) {

                    if (dist[itr.first] > tmp_cost + itr.second) { // 새로 구한 값보다 크다면..
                        dist[itr.first] = tmp_cost + itr.second; // 갱신..
                        pq.push({dist[itr.first], itr.first});
                    }
                }
            }
        }



        int cnt = 0;
        int max_time = 0;
        for (int i = 1; i <= N; ++i) {
            if (dist[i] != INF) {
                cnt++;
                if (dist[i] > max_time) max_time = dist[i];
            }
        }
        printf("%d %d\n", cnt, max_time);






    }

    return 0;
}

void clr(int arr[10001]) {
    for (int i = 0; i <= 10000; ++i) {
        arr[i] = INF;
    }
}
