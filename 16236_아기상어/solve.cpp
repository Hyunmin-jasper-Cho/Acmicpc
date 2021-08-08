// 문제를 잘 읽자....

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>

int N, my_size = 2;
int my_x, my_y;

int size_tmp = 0;

int x_m[4] = {0, -1, 0, 1};
int y_m[4] = {-1, 0, 1, 0};

int bfs(int place[21][21], int x, int y);

using namespace std;

int main() {
    char input[100];

    int place[21][21];

    scanf("%d" ,&N); getchar();
    for (int i = 1; i <= N; ++i) {
        fgets(input, 100, stdin);
        place[i][1] = (int) strtol(strtok(input, " "), nullptr, 10);
        if (place[i][1] == 9) {
            my_x = 1; my_y = i;
            place[i][1] = 0;
        }
        for (int j = 2; j <= N; ++j) {
            place[i][j] = (int) strtol(strtok(nullptr, " "), nullptr, 10);
            if (place[i][j] == 9) {
                my_x = j; my_y = i;
                place[i][j] = 0;
            }
        }
    }

    int total_remain_time = 0;
    while (true) {
        int val = bfs(place, my_x, my_y);
        if (val == -1) break;
        total_remain_time += val;
    }

    printf("%d", total_remain_time);

    return 0;
}

int bfs(int place[21][21], int x, int y) {
    int vis[21][21] = {0, };
    int time = 0;

    // y, x
    map<pair<int, int>, int> v;
    v.insert({{y, x}, 0});

    queue<pair<int, int>> q;
    q.push({x, y}); vis[y][x] = 1;

    while (!q.empty()) {

        int size = (int) q.size();

        for (auto & itr : v) {
            if (itr.second != 0 and itr.second < my_size) {
                place[itr.first.first][itr.first.second] = 0; // 해당 부분 먹고..
                my_y = itr.first.first; my_x = itr.first.second; // 이동..
                size_tmp += 1;

                if (size_tmp == my_size) {
                    my_size += 1;
                    size_tmp = 0;
                }

                return time;
            }
        }

        for (int i = 0; i < size; ++i) {
            int pop_x = q.front().first;
            int pop_y = q.front().second;
            v.erase({pop_y, pop_x});
            q.pop();

            for (int j = 0; j < 4; ++j) {
                int n_x = pop_x + x_m[j];
                int n_y = pop_y + y_m[j];

                if (n_x <= N and n_y <= N and n_x > 0 and n_y > 0) { // 범위 내이고..
                    if (place[n_y][n_x] <= my_size) { // 지나갈 수 잇고..
                        if (vis[n_y][n_x] == 0) { // 방문하지 않았다면..
                            vis[n_y][n_x] = 1;
                            q.push({n_x, n_y});
                            v.insert({{n_y, n_x}, place[n_y][n_x]});
                        }
                    }
                }
            }
        } time += 1;
    } return -1; // 먹을 수 있는 것이 없음..
}
