#include <iostream>

int N, K;
using namespace std;

int x_sum[1025][1025];
int y_sum[1025][1025];

int main() {

    scanf("%d %d", &N, &K);
    int val[1025][1025];


    for (int i = 0; i <= N; ++i) {
        val[i][0] = 0;
        val[0][i] = 0;

        x_sum[0][i] = 0;
        x_sum[i][0] = 0;

        y_sum[0][i] = 0;
        y_sum[i][0] = 0;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &(val[i][j]));

            x_sum[i][j] = x_sum[i][j - 1] + val[i][j];
            y_sum[i][j] = y_sum[i - 1][j] + val[i][j];

        }
    }

    for (int tc = 0; tc < K; ++tc) {
        int x1, x2, y1, y2; scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

        int tt_sum = 0;

        for (int j = x1; j <= x2; ++j) {

            tt_sum += y_sum[y2][j] - y_sum[y1 - 1][j];

        } printf("%d\n", tt_sum);
    }

    return 0;
}
