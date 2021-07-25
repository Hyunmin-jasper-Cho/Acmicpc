#include <iostream>

int map[51][51];
bool wall[51][51];

enum {
    NORTH = 0, EAST, SOUTH, WEST
};

bool already_cleaned_up(int x, int y);

void clean_up(int x, int y, int *cnt) {
    if (map[y][x] == 1) return;
    map[y][x] = 1; *cnt += 1;
}

int main() {

    int h, w; scanf("%d %d", &h, &w);
    int x, y, pos; scanf("%d %d %d", &y, &x, &pos);

    for (int i = 0; i < h; ++i ){
        for (int j = 0; j < w; ++j) {
            scanf("%d", &(map[i][j]));
            if (map[i][j] == 1) { wall[i][j] = true; }
            else wall[i][j] = false;
        }
    }
    int cnt = 0;

    while (true) {

        // 1. 현재 위치를 청소한다
        clean_up(x, y, &cnt);

        // 현재 위치로부터의 왼쪽 칸을 탐색하는데...
        if (pos == NORTH) { // 현재 NORTH 를 바라보고 있다면..

            // 네 방향이 전부 청소가 되어 있다면..
            if (already_cleaned_up(x, y)) {
                if (wall[y + 1][x]) break;
                else y += 1;
                continue;
            }

            pos = WEST;  // 그 방향으로 회전하고
            if (map[y][x - 1] == 0) { // 왼편에 청소할 공간이 존재한다면..
                x -= 1;      // 그 방향으로 이동한 다음
                continue;    // 다시 1번부터 시행..
            } else continue;
        } else if (pos == EAST) {

            // 네 방향이 전부 청소가 되어 있다면..
            if (already_cleaned_up(x, y)) {
                if (wall[y][x - 1]) break;
                else x -= 1;
                continue;
            }

            pos = NORTH;
            if (map[y - 1][x] == 0) { // 왼편에 청소할 공간이 존재한다면..
                y -= 1;      // 그 방향으로 이동한 다음
                continue;    // 다시 1번부터 시행..
            } else continue;
        } else if (pos == SOUTH){

            // 네 방향이 전부 청소가 되어 있다면..
            if (already_cleaned_up(x, y)) {
                if (wall[y - 1][x]) break;
                else y -= 1;
                continue;
            }

            pos = EAST;
            if (map[y][x + 1] == 0) { // 왼편에 청소할 공간이 존재한다면..
                x += 1;      // 그 방향으로 이동한 다음
                continue;    // 다시 1번부터 시행..
            } else continue;
        } else {

            // 네 방향이 전부 청소가 되어 있다면..
            if (already_cleaned_up(x, y)) {
                if (wall[y][x + 1]) break;
                else x += 1;
                continue;
            }

            pos = SOUTH;
            if (map[y + 1][x] == 0) { // 왼편에 청소할 공간이 존재한다면..
                y += 1;      // 그 방향으로 이동한 다음
                continue;    // 다시 1번부터 시행..
            } else continue;
        }

    }

    printf("%d", cnt);
    return 0;
}

bool already_cleaned_up(int x, int y) {
    if (map[y][x + 1] == 1 and map[y][x - 1] == 1
        and map[y - 1][x] == 1 and map[y + 1][x] == 1) {
        return true;
    } else return false;
}
