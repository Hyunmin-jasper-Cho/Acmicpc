#include <iostream>
#include <algorithm>
#include <cstring>

int height, width;
int map[501][501];
bool vis[501][501];
int types[100] = {0, }, idx = 0;

int x_move[4] = {0, 0, -1, 1};
int y_move[4] = {-1, 1, 0, 0};

bool is_out_of_range(int x, int y);

void solve(int x, int y, int depth, int tmp);

void clr();
void clr_vis();

int main() {
    clr_vis();
    char input[5000];
    scanf("%d %d", &height, &width); getchar();

    for (int i = 1; i <= height; ++i) {
        fgets(input, 5000, stdin);
        int val = (int) strtol(strtok(input, " "), nullptr, 10);
        map[i][1] = val;
        for (int j = 2; j <= width; ++j) {
            val = (int) strtol(strtok(nullptr, " "), nullptr, 10);
            map[i][j] = val;
        }
    }

    int ans = 0;
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= width; ++j) { // 모든 범위에 대해서..
            clr();
            vis[i][j] = true;
            solve(j, i, 0, 0);

            if (!is_out_of_range(j - 1, i)) {
                if (!is_out_of_range(j + 1, i)) {
                    if (!is_out_of_range(j, i + 1)) {
                        types[idx++] = map[i][j - 1] + map[i][j + 1] + map[i + 1][j] + map[i][j];
                    }
                }
            }

            if (!is_out_of_range(j - 1, i)) {
                if (!is_out_of_range(j, i - 1)) {
                    if (!is_out_of_range(j, i + 1)) {
                        types[idx++] = map[i][j - 1] + map[i - 1][j] + map[i + 1][j] + map[i][j];
                    }
                }
            }

            if (!is_out_of_range(j - 1, i)) {
                if (!is_out_of_range(j + 1, i)) {
                    if (!is_out_of_range(j, i - 1)) {
                        types[idx++] = map[i][j - 1] + map[i][j + 1] + map[i - 1][j] + map[i][j];
                    }
                }
            }

            if (!is_out_of_range(j + 1, i)) {
                if (!is_out_of_range(j, i - 1)) {
                    if (!is_out_of_range(j, i + 1)) {
                        types[idx++] = map[i][j + 1] + map[i - 1][j] + map[i + 1][j] + map[i][j];
                    }
                }
            }

            vis[i][j] = false;
            std::sort(types, types + idx);

            int tmp = types[idx - 1];
            ans = ans < tmp ? tmp : ans;
        }
    }

    printf("%d", ans);

    return 0;
}

void clr() {
    for (int & type : types) {
        type = 0;
    } idx = 0;
}

void solve(int x, int y, int depth, int tmp) {

    tmp += map[y][x];

    if (depth == 3) {
        types[idx++] = tmp;
        return;
    }

    // 현재 상태에 대해서 4번 반복..
    for (int i = 0; i < 4; ++i) {
        if (!is_out_of_range(x + x_move[i], y + y_move[i])) { // out of range 가 아니면
            vis[y + y_move[i]][x + x_move[i]] = true;
            solve(x + x_move[i], y + y_move[i], depth + 1, tmp);
            vis[y + y_move[i]][x + x_move[i]] = false;
        }
    }

}

bool is_out_of_range(int x, int y) {
    if (x <= 0 or y <= 0 or x > width or y > height) return true;
    if (vis[y][x]) return true;

    else return false;
}
void clr_vis() {
    for (int i = 0; i <= height; ++i) {
        for (int  j = 0; j <= width; ++j) {
            vis[i][j] = false;
        }
    }
}
