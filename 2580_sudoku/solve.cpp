#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool is_reliable(int x, int y, int sudoku[10][10], int prediction_value);
void solve(vector<pair<int, int>>::iterator itr, int cnt, int sudoku[10][10]);

int main() {
    char input[30];
    int sudoku[10][10];
    int cnt = 0;

    vector<pair<int, int>> empty_slot;

    for (int i = 1; i <= 9; ++i) {
        fgets(input, 30, stdin);
        sudoku[i][1] = (int) strtol(strtok(input, " "), nullptr, 10);

        if (sudoku[i][1] == 0) {
            empty_slot.emplace_back(make_pair(1, i));
            cnt += 1;
        }

        for (int j = 2; j <= 9; ++j) {
            sudoku[i][j] = (int) strtol(strtok(nullptr, " "), nullptr, 10);

            if (sudoku[i][j] == 0) {
                empty_slot.emplace_back(make_pair(j, i));
                cnt += 1;
            }
        }
    }

    auto itr = empty_slot.begin();
    solve(itr, cnt, sudoku);


    return 0;
}

void solve(vector<pair<int, int>>::iterator itr, int cnt, int sudoku[10][10]) {

    if (itr->first == 8 and itr->second == 2) {
        int DEBUG = -1;
    }

    if (cnt == 0) { // 종료조건..
        return;
    }

    // 현재 빈 위치에 대해서 총 9 번 시도..
    for (int value = 1; value <= 9; ++value) {

        if (is_reliable(itr->first, itr->second, sudoku, value)) { // 이 value 를 넣을 수 있다면..
            sudoku[itr->second][itr->first] = value;

            if (cnt == 1) {
                for (int i = 1; i <= 9; ++i) {
                    for (int j = 1; j <= 9; ++j) {
                        printf("%d ", sudoku[i][j]);
                    } printf("\n");
                }
                exit(0);
            }


            solve(next(itr), cnt - 1, sudoku); // 더 깊이 들어갔다가..

            sudoku[itr->second][itr->first] = 0; // 다시 돌아오면 초기화..
        }

    }
}

bool is_reliable(int x, int y, int sudoku[10][10], int prediction_value) {

    // 가로줄..
    for (int i = 1; i <= 9; ++i) {
        if (sudoku[y][i] == prediction_value) return false;
    }

    // 세로줄..
    for (int i = 1; i <= 9; ++i) {
        if (sudoku[i][x] == prediction_value) return false;
    }

    // 내부 사각형..
    if (x <= 3) {
        if (y <= 3) {
            for (int i = 1; i <= 3; ++i) {
                for (int j = 1; j <= 3; ++j) {
                    if (sudoku[i][j] == prediction_value) return false;
                }
            }
        } else if (y <= 6) {
            for (int i = 4; i <= 6; ++i) {
                for (int j = 1; j <= 3; ++j) {
                    if (sudoku[i][j] == prediction_value) return false;
                }
            }
        } else {
            for (int i = 7; i <= 9; ++i) {
                for (int j = 1; j <= 3; ++j) {
                    if (sudoku[i][j] == prediction_value) return false;
                }
            }
        }
    } else if (x <= 6) {
        if (y <= 3) {
            for (int i = 1; i <= 3; ++i) {
                for (int j = 4; j <= 6; ++j) {
                    if (sudoku[i][j] == prediction_value) return false;
                }
            }
        } else if (y <= 6) {
            for (int i = 4; i <= 6; ++i) {
                for (int j = 4; j <= 6; ++j) {
                    if (sudoku[i][j] == prediction_value) return false;
                }
            }
        } else {
            for (int i = 7; i <= 9; ++i) {
                for (int j = 4; j <= 6; ++j) {
                    if (sudoku[i][j] == prediction_value) return false;
                }
            }
        }
    } else {
        if (y <= 3) {
            for (int i = 1; i <= 3; ++i) {
                for (int j = 7; j <= 9; ++j) {
                    if (sudoku[i][j] == prediction_value) return false;
                }
            }
        } else if (y <= 6) {
            for (int i = 4; i <= 6; ++i) {
                for (int j = 7; j <= 9; ++j) {
                    if (sudoku[i][j] == prediction_value) return false;
                }
            }
        } else {
            for (int i = 7; i <= 9; ++i) {
                for (int j = 7; j <= 9; ++j) {
                    if (sudoku[i][j] == prediction_value) return false;
                }
            }
        }
    }
    return true;
}
