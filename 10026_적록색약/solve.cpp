#include <iostream>
#include <cstdlib>

int N;
char map[101][101];
bool visited[101][101];

int solve(int x, int y, char sta_char, bool colour_blind);
void clr();

// R: 82 / G: 71 / B: 66
// R * B = 5412
// G * B = 4686
// R * G = 5822

int main() {

    char input[105];
    scanf("%s", input);

    N = (int) strtol(input, nullptr, 10);

    for (int i = 1; i <= N; ++i) {
        scanf("%s", input);
        for (int j = 1; j <= N; ++j) {
            map[i][j] = input[j - 1];
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cnt += solve(j, i, map[i][j], false);
        }
    } clr(); printf("%d ", cnt); cnt = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cnt += solve(j, i, map[i][j], true);
        }
    } printf("%d\n", cnt);

    return 0;
}

void clr() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            visited[i][j] = false;
        }
    }
}

int solve(int x, int y, char sta_char, bool colour_blind) {

    if (x < 1 || y < 1 || x > N || y > N) return 0; // out of range

    if (visited[y][x]) return 0; // already visited..

    char current_ch = map[y][x];
    if (!colour_blind) {
        if (current_ch != sta_char) return 0; // other area..
    } else {
        if (current_ch != sta_char) {
            if (current_ch * sta_char != 5822) return 0;
        }
    }


    // if same area..
    visited[y][x] = true;
    solve(x + 1, y, sta_char, colour_blind);
    solve(x - 1, y, sta_char, colour_blind);
    solve(x, y + 1, sta_char, colour_blind);
    solve(x, y - 1, sta_char, colour_blind);

    return 1;

}
