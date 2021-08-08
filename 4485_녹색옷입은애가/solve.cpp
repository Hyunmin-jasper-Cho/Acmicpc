// 다익스트라는 기본적으로 visit 을 확인하지 않는다. 헷갈리지 말자.

#include <iostream>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <vector>
#include <queue>
#define INF 1500

using namespace std;
int N;

int x_m[4] = {0, 0, -1, 1};
int y_m[4] = {-1, 1, 0, 0};

void clr(int val[126][126], int init_val);

bool is_reliable(int x, int y);

int main() {
    int cnt = 1;

    char input[500];
    int val[126][126];
    int dist[126][126];

    while (true) {

        scanf("%d", &N);
        getchar();

        if (N != 0) {
            clr(dist, INF); // clear distance
            for (int i = 1; i <= N; ++i) {
                fgets(input, 500, stdin);
                val[i][1] = (int) strtol(strtok(input, " "), nullptr, 10);
                for (int j = 2; j <= N; ++j) {
                    val[i][j] = (int) strtol(strtok(nullptr, " "), nullptr, 10);
                }
            }


            //                 cost     x pos   y pos
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
            pq.push(make_pair(val[1][1], make_pair(1, 1)));
            while (!pq.empty()) {

                int size = pq.size();
                for (int i = 0; i < size; ++i) {

                    int tmp_cost = pq.top().first;
                    int tmp_x_pos = pq.top().second.first;
                    int tmp_y_pos = pq.top().second.second;
                    pq.pop();

                    for (int j = 0; j < 4; ++j) {
                        int new_x = tmp_x_pos + x_m[j], new_y = tmp_y_pos + y_m[j];
                        if (is_reliable(new_x, new_y)) {
                            if (dist[new_y][new_x] > tmp_cost + val[new_y][new_x]) {
                                dist[new_y][new_x] = tmp_cost + val[new_y][new_x]; // 갱신..
                                pq.push(make_pair(dist[new_y][new_x], make_pair(new_x, new_y)));
                            }
                        }
                    }

                }
            }
            printf("Problem %d: %d\n", cnt++, dist[N][N]);

        } else return 0;
    }
}

bool is_reliable(int x, int y) {
    if (x <= 0 or y <= 0 or x > N or y > N) return false;

    return true;
}

void clr(int val[126][126], int init_val) {
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            val[i][j] = init_val;
        }
    } val[1][1] = 0;
}
