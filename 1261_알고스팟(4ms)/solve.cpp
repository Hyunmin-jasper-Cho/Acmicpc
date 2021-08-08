#include <iostream>
#include <functional>
#include <cstring>
#include <queue>
#include <map>
#define INF 100001

int height, width;
using namespace std;

int x_m[4] = {0, 0, -1, 1};
int y_m[4] = {-1, 1, 0, 0};

void clr(int arr[101][101]);

int main() {
    char input[105];

    char data[101][101];
    int dist[101][101];
    int vis[101][101];
    clr(dist); dist[1][1] = 0;
    memset(vis, 0, sizeof(vis));

    scanf("%d %d", &width, &height);
    for (int i = 1; i <= height; ++i) {
        scanf("%s", input);
        for (int j = 1; j <= width; ++j) {
            data[i][j] = input[j - 1];
        }
    }

    // cost, x pos, y pos
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    map<pair<int, int>, int> done;
    pq.push({0, {1, 1}});

    while (!pq.empty()) {
        int size = (int) pq.size();
        for (int i = 0; i < size; ++i) {
            int tmp_cost = pq.top().first;
            int tmp_x_pos = pq.top().second.first;
            int tmp_y_pos = pq.top().second.second; pq.pop();

            if (done.contains({tmp_x_pos, tmp_y_pos})) continue;
            else done.insert({{tmp_x_pos, tmp_y_pos}, 1});
            vis[tmp_y_pos][tmp_x_pos] = 1;

            for (int j = 0; j < 4; ++j) {
                int n_x = tmp_x_pos + x_m[j];
                int n_y = tmp_y_pos + y_m[j];

                if (n_x > 0 and n_y > 0 and n_x <= width and n_y <= height and vis[n_y][n_x] == 0) { // 범위 내면서 방문하지 않았을 때..

                    if (data[n_y][n_x] == '1') { // 새로운 지점이 벽일 때..
                        if (dist[n_y][n_x] > tmp_cost + 1) {
                            dist[n_y][n_x] = tmp_cost + 1;
                        }
                    } else {
                        if (dist[n_y][n_x] > tmp_cost) {
                            dist[n_y][n_x] = tmp_cost;
                        }
                    }
                    pq.push({dist[n_y][n_x], {n_x, n_y}});
                }
            }
        }
    }

    printf("%d", dist[height][width]);

    return 0;
}

void clr(int arr[101][101]) {
    for (int i = 0; i < 101; ++i) {
        for (int j = 0; j < 101; ++j) {
            arr[i][j] = INF;
        }
    }
}
