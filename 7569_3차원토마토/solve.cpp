#include <iostream>
#include <cstring>
#include <queue>

#define ROTTEN 1
#define UNROTTEN 0

int N, M, H;
using namespace std;

int x_m[6] = {0, 0, -1, 1, 0, 0};
int y_m[6] = {-1, 1, 0, 0, 0, 0};
int f_m[6] = {0, 0, 0, 0, 1, -1};

int map[101][101][101];
bool vis[101][101][101];

bool is_reliable(int x, int y, int f);

int main() {
    queue<pair<int, pair<int, int>>> q;
    memset(vis, false, sizeof(vis));

    char input[1000];
    int cnt_of_none_rotten_tomato = 0;

    scanf("%d %d %d", &N, &M, &H); getchar();
    for (int i = H; i >= 1; --i) {
        for (int j = 1; j <= M; ++j) {
            fgets(input, 1000, stdin);

            map[i][j][1] = (int) strtol(strtok(input, " "), nullptr, 10);


            if (map[i][j][1] == UNROTTEN) cnt_of_none_rotten_tomato++;
            else if (map[i][j][1] == ROTTEN) q.push({i, {j, 1}});


            for (int k = 2; k <= N; ++k) {
                map[i][j][k] = (int) strtol(strtok(nullptr, " "), nullptr, 10);


                if (map[i][j][k] == UNROTTEN) cnt_of_none_rotten_tomato++;
                else if (map[i][j][k] == ROTTEN) q.push({i, {j, k}});


            }
        }
    }

    if (cnt_of_none_rotten_tomato == 0) {
        printf("0"); exit(0);
    }


    int time = 0;
    while (!q.empty()) {
        int size = (int) q.size();

        if (cnt_of_none_rotten_tomato == 0) break;

        for (int i = 0; i < size; ++i) {
            int pop_f = q.front().first;
            int pop_x = q.front().second.second;
            int pop_y = q.front().second.first;
            q.pop();

            for (int j = 0; j < 6; ++j) {
                int nx = pop_x + x_m[j];
                int ny = pop_y + y_m[j];
                int nf = pop_f + f_m[j];

                if (is_reliable(nx, ny, nf)) {
                    map[nf][ny][nx] = ROTTEN;
                    cnt_of_none_rotten_tomato -= 1;
                    q.push({nf, {ny, nx}});
                }
            }
        } time++;
    }


    if (cnt_of_none_rotten_tomato != 0) {
        printf("-1");
    } else printf("%d", time);

    return 0;
}
bool is_reliable(int x, int y, int f) {
    if (x <= 0 or y <= 0 or f <= 0 or x > N or y > M or f > H) return false;
    if (map[f][y][x] != UNROTTEN) return false;

    return true;
}
