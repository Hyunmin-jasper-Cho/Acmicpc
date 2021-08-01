#include <iostream>
#include <cstring>

using namespace std;

int height, width;

bool is_out_of_range(int x, int y);
bool cannot_go_anywhere(char plate[21][21], int x, int y, const int alphabet[26]);
int solve(char plate[21][21], int x, int y, int alpha[26]);

enum {
    R = 0, D, L, U
};

//               R   D   L  U
int x_move[4] = {+1, 0, -1, 0};
int y_move[4] = {0, +1, 0, -1};

int main() {

    char plate[21][21];
    int alphabet[26] = {0, };
    char input[50];

    fgets(input, 50, stdin);
    height = (int) strtol(strtok(input, " "), nullptr, 10);
    width = (int) strtol(strtok(nullptr, " "), nullptr, 10);

    for (int i = 1; i <= height; ++i) {
        scanf("%s", input);
        for (int j = 1; j <= width; ++j) {
            plate[i][j] = input[j - 1];
        }
    }


    printf("%d", solve(plate, 1, 1, alphabet));



    return 0;
}

int solve(char plate[21][21], int x, int y, int alpha[26]) {

    if (cannot_go_anywhere(plate, x, y, alpha)) {
        alpha[plate[y][x] - 'A'] = 0; // 반환하고..
        return 1;
    }

    int cnt = 0;
    // 현재 위치한 곳을 방문한다..
    alpha[plate[y][x] - 'A'] = 1; cnt += 1;


    int tmp = 0;
    // 상하좌우로 dfs..
    for (int i = 0; i < 4; ++i) {
        if (!is_out_of_range(x + x_move[i], y + y_move[i])) {
            if (alpha[plate[y + y_move[i]][x + x_move[i]] - 'A'] == 0) {
                int t_tmp = solve(plate, x + x_move[i], y + y_move[i], alpha);
                if (tmp < t_tmp) tmp = t_tmp;
                // 돌아왔다면..
                alpha[plate[y + y_move[i]][x + x_move[i]] - 'A'] = 0; // 반환...
            }
        }
    } alpha[plate[y][x] - 'A'] = 0; // 반환하고..
    return cnt + tmp;
}
bool cannot_go_anywhere(char plate[21][21], int x, int y, const int alphabet[26]) {
    // 어느 한 곳이라도 갈 수 있다면 return false..

    for (int i = 0; i < 4; ++i) {
        if (!is_out_of_range(x + x_move[i], y + y_move[i])) {

            if (alphabet[plate[y + y_move[i]][x + x_move[i]] - 'A'] == 0) {
                return false;
            }

        }
    } return true;
}
bool is_out_of_range(int x, int y) {
    return (x <= 0 or y <= 0 or x > width or y > height);
}
