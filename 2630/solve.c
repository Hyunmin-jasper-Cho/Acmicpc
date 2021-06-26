#include <stdio.h>
#include <stdbool.h>

int paper[128 + 1][128 + 1];
int blue_paper = 0;
int white_paper = 0;

bool isFilled(int height_pos, int width_pos, int len) { // len = 128, 64, ...
    bool isWhite = false;
    bool isBlue = false;

    if (paper[height_pos][width_pos] == 1) isBlue = true;
    else isWhite = true;

    for (int i = height_pos; i < len + height_pos; ++i) {
        for (int j = width_pos; j < len + width_pos; ++j) {
            if (isWhite && paper[i][j] == 1) return false;
            if (isBlue && paper[i][j] == 0) return false;
        }
    }
    if (isBlue) blue_paper += 1;
    else white_paper += 1;

    return true;
}

void solve(int height_pos, int width_pos, int len) { // len = 128, 64, ...
    if (isFilled(height_pos, width_pos, len)) {
        return;
    }

    int half = len / 2;

    solve(height_pos, width_pos, half);
    solve(height_pos, width_pos + half, half);
    solve(height_pos + half, width_pos, half);
    solve(height_pos + half, width_pos + half, half);
}

int main() {
    int len;
    scanf("%d", &len);

    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= len; ++j) {
            scanf("%d", &((paper[i])[j]));
        }
    }
    solve(1, 1, len);
    printf("%d\n%d\n", white_paper, blue_paper);
    return 0;
}
