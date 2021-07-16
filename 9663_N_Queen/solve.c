#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int N;
int ans = 0;
bool **visited;

bool out_of_range(int x, int y);
int parse_int(char *str);
void solve(int depth);

bool is_reliable(int x, int depth);

int main() {
    char input[3];


    scanf("%s", input);
    N = parse_int(input);
    visited = (bool **) malloc(sizeof (bool *) * N);
    for (int i = 0; i < N; ++i) {
        visited[i] = (bool *) malloc(sizeof (bool) * N);
    }

    solve(0);
    printf("%d\n", ans);

    return 0;
}

bool out_of_range(int x, int y) {

    if (x < 0 || y < 0 || x >= N || y >= N) return true;
    else return false;

}


int parse_int(char *str) {
    return (int) strtol(str, NULL, 10);
}

void solve(int depth) { // depth 의 시작은 0번째 줄..

    // 만약 N 만큼의 깊이에 들어왔다면..
    if (depth == N) {
        ans += 1; // 개수 ++
        return; // 돌아간다.
    }

    // 현재 줄에서 (y 값) 0 번 부터 N - 1 번까지 행한다.
    for (int x = 0; x < N; ++x) {

        // 우선, 내가 해보려는 값이 out_of_range 이면 안된다..
        if (out_of_range(x, depth)) {

            // 범위 밖이라면 즉시 돌아간다...
            return;

        } else { // 범위 오류는 없다.. 그럼 이제 reliable 한지 확인한다..

            // 1. 해당 지점을 방문하지 않았고..
            if (!visited[depth][x]) {
                // 2. 해당 지점에 둬도 된다면..
                if (is_reliable(x, depth)) {

                    // 해당 지점을 방문처리 해 준뒤..
                    visited[depth][x] = true;
                    solve(depth + 1);  // dfs

                    // 이후 이 dfs 지점을 빠져나왔다면..
                    // 다시 visited 를 false 로 바꾸어 준다,..
                    visited[depth][x] = false;

                }
            }
        }

    }



}

bool is_reliable(int x, int depth) { // depth 는 y 와 같다

    // out of range 일 가능성은 없음

    // x 혹은 y 가 같거나 == 같은 x 좌표를 가진 map 상의 visited 가 true 인 점이 있는가
    for (int i = 0; i < N; ++i) {
        if (visited[i][x] == true) return false;
        if (visited[depth][i] == true) return false;
    }

    int x_save = x, depth_save = depth;
    // 대각선에 있던가..
    while (x < N && depth < N) {
        if (visited[depth++][x++]) return false;
    } x = x_save; depth = depth_save;
    while (x < N && depth >= 0) {
        if (visited[depth--][x++]) return false;
    } x = x_save; depth = depth_save;
    while (x >= 0 && depth < N) {
        if (visited[depth++][x--]) return false;
    } x = x_save; depth = depth_save;
    while (x >= 0 && depth >= 0) {
        if (visited[depth--][x--]) return false;
    }

    return true;
}
