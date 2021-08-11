#include <iostream>
#include <functional>
#include <cstring>
#include <queue>

#define WALL 0

int xm[4] = {0, 0, -1, 1};
int ym[4] = {-1, 1, 0, 0};

char input[100];
using namespace std;

int main() {
    int map[51][51];
    int wall_cost[51][51]; memset(wall_cost, -1, sizeof(wall_cost));
    int N;

    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%s", input);
        for (int j = 1; j <= N; ++j) {
            map[i][j] = (int) input[j - 1] - '0';
        }
    } wall_cost[1][1] = 0; // always white...

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {1, 1}});
    while (!pq.empty()) {

        int c_cost = pq.top().first;

        int cx = pq.top().second.first;
        int cy = pq.top().second.second; pq.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = cx + xm[i];
            int ny = cy + ym[i];

            if (nx > 0 and nx <= N and ny > 0 and ny <= N) {
                if (wall_cost[ny][nx] == -1) {
                    if (map[ny][nx] == WALL) {
                        wall_cost[ny][nx] = c_cost + 1;
                    } else wall_cost[ny][nx] = c_cost;
                    pq.push({wall_cost[ny][nx], {nx, ny}});
                } else {
                    if (map[ny][nx] == WALL) {
                        if (wall_cost[ny][nx] > c_cost + 1) {
                            wall_cost[ny][nx] = c_cost + 1;
                            pq.push({wall_cost[ny][nx], {nx, ny}});
                        }
                    } else {
                        if (wall_cost[ny][nx] > c_cost) {
                            wall_cost[ny][nx] = c_cost;
                            pq.push({wall_cost[ny][nx], {nx, ny}});
                        }
                    }
                }
            }
        }
    }

    printf("%d", wall_cost[N][N]);


    return 0;
}
