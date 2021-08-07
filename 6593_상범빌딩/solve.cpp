#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int x_m[6] = {0, 0, -1, 1, 0, 0};
int y_m[6] = {-1, 1, 0, 0, 0, 0};
int f_m[6] = {0, 0, 0, 0, -1, 1};

char building [31] [31] [31];
bool vis[31][31][31];

int F, H, W;
bool is_ok(int f, int y, int x);

int main() {

    while (true) {

        scanf("%d %d %d", &F, &H, &W);

        if (F == 0 and H == 0 and W == 0) return 0;

        memset(vis, false, sizeof(vis));

        queue<pair<int, pair<int, int>>> q;

        int end_f, end_y, end_x;

        for (int cur_floor = F; cur_floor >= 1; --cur_floor) {
            for (int i = 1; i <= H; ++i) {
                char input[50]; scanf("%s", input);
                for (int j = 1; j <= W; ++j) {
                    building[cur_floor][i][j] = input[j - 1];

                    if (input[j - 1] == 'S') {
                        q.push(make_pair(cur_floor, make_pair(i, j)));
                        vis[cur_floor][i][j] = true;
                    }

                    if (input[j - 1] == 'E') {
                        end_f = cur_floor;
                        end_y = i;
                        end_x = j;
                    }
                }
            }
            getchar();
        }


        bool find = false;
        int time = 0;
        while (!q.empty()) {
            int size = q.size();

            if (vis[end_f][end_y][end_x]) find = true;
            if (find) break;

            for (int i = 0; i < size; ++i) {

                int f, y, x;
                f = q.front().first;
                y = q.front().second.first;
                x = q.front().second.second; q.pop();

                for (int j = 0; j < 6; ++j) {
                    if (is_ok(f + f_m[j], y + y_m[j], x + x_m[j])) {
                        q.push(make_pair(f + f_m[j], make_pair(y + y_m[j], x + x_m[j])));
                        vis[f + f_m[j]][y + y_m[j]][x + x_m[j]] = true;
                    }
                }
            }
            time += 1;
        }

        if (find) {
            printf("Escaped in %d minute(s).\n", time);
        } else printf("Trapped!\n");

    }
}

bool is_ok(int f, int y, int x) {
    if (!vis[f][y][x]) {
        if (building[f][y][x] != '#') {
            if (x >= 1 and y >= 1 and f >= 1 and f <= F and y <= H and x <= W) {
                return true;
            }
        }
    } return false;
}
