#include <iostream>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

int height, width, total_ice = 0;

int x_move[4] = {0, 0, -1, 1};
int y_move[4] = {-1, 1, 0, 0};
int cnt = 0;

int visited[301][301];
int ice[301][301];

void clr();
void bfs(int x, int y);
bool can_move(int x, int y);

int main() {
    char input[1000];
    int init_x = -1, init_y = -1;

    map<pair<int, int>, int> iceberg;

    scanf("%d %d", &height, &width); getchar(); clr();

    for (int i = 1; i <= height; ++i) {
        fgets(input, 1000, stdin);
        int val = (int) strtol(strtok(input, " "), nullptr, 10);
        ice[i][1] = val;
        if (val != 0) {
            total_ice += 1;
            iceberg.insert(make_pair(make_pair(1, i), val));
        }

        for (int j = 2; j <= width; ++j) {
            val = (int) strtol(strtok(nullptr, " "), nullptr, 10);
            ice[i][j] = val;
            if (val != 0) {
                total_ice += 1;
                iceberg.insert(make_pair(make_pair(j, i), val));
            }
        }
    }

    auto itr = iceberg.begin();
    int time = 0;
    bfs(itr->first.first, itr->first.second);


    if (cnt != total_ice) {
        printf("0");
        return 0;
    }


    while (total_ice != 0) {
        clr();

        // 얼음들에 대해서만..
        for (itr = iceberg.begin(); itr != iceberg.end(); ++itr) {
            int reduce = 0;

            for (int i = 0; i < 4; ++i) {
                if (!iceberg.contains(make_pair(itr->first.first + x_move[i], itr->first.second + y_move[i]))) {
                    reduce += 1;
                }
            }
            itr->second -= reduce;
            ice[itr->first.second][itr->first.first] -= reduce;
        }

        itr = iceberg.begin();
        for (; itr != iceberg.end();) {
            if (itr->second <= 0) {
                ice[itr->first.second][itr->first.first] = 0;
                total_ice -= 1;
                iceberg.erase(itr++);
            } else ++itr;
        }


        time += 1;

        if (total_ice == 0) {
            printf("0");
            return 0;
        }

        itr = iceberg.begin();
        cnt = 0; bfs(itr->first.first, itr->first.second);

        if (total_ice != cnt) {
            break;
        }



    }
    printf("%d", time);

    return 0;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    cnt += 1; visited[y][x] = 1;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int cur_x = q.front().first, cur_y = q.front().second; q.pop();


            for (int j = 0; j < 4; ++j) {
                if (can_move(cur_x + x_move[j], cur_y + y_move[j])) {
                    q.push(make_pair(cur_x + x_move[j], cur_y + y_move[j]));
                    cnt += 1; visited[cur_y + y_move[j]][cur_x + x_move[j]] = 1;
                }
            }
        }
    }
}

bool can_move(int x, int y) {
    if (x <= 0 or y <= 0 or x > width or y > height) return false;

    if (ice[y][x] != 0) { // 빙산이고
        if (visited[y][x] == -1) { // 방문하지 않았다면..
            return true;
        }
    } return false;
}

void clr() {
    for (int i = 0; i <= height; ++i) {
        for (int j = 0; j <= width; ++j) {
            visited[i][j] = -1;
        }
    }
}
