#include <iostream>
#include <cstring>
#include <cstdlib>
#include <deque>

using namespace std;

void clr(int *map, bool *visited);
bool is_reliable(int x, const bool *visited);

int main() {
    deque<int> v;

    char input[10];

    int N, M, cnt = 0;
    int map[101];
    bool visited[101]; clr(map, visited);

    fgets(input, 10, stdin);
    N = (int) strtol(strtok(input, " "), nullptr, 10);
    M = (int) strtol(strtok(nullptr, " "), nullptr, 10);

    for (int i = 0; i < N + M; ++i) {
        fgets(input, 10, stdin);
        int to = (int) strtol(strtok(input, " "), nullptr, 10);
        int at = (int) strtol(strtok(nullptr, " "), nullptr, 10);
        map[to] = at;
    }

    v.push_back(1); // start point
    visited[1] = true; // when push, visit
    while (!v.empty()) {

        if (visited[100]) break;

        int size = (int) v.size();
        for (int i = 0; i < size; ++i) {

            int current_node = v.front();
            v.pop_front(); // delete..

            for (int dice = 1; dice <= 6; ++dice) {
                // if can go..
                if (is_reliable(current_node + dice, visited)) {
                    if (map[current_node + dice] != 0) {
                        v.push_back(map[current_node + dice]);
                        visited[map[current_node + dice]] = true;
                    } else {
                        v.push_back(current_node + dice);
                        visited[current_node + dice] = true;
                    }
                }
            }



        } cnt += 1;
    }

    printf("%d\n", cnt);

    return 0;
}

bool is_reliable(int x, const bool *visited) {
    if (x <= 0 or x > 100) return false;
    if (visited[x]) return false;
    return true;
}

void clr(int *map, bool *visited) {
    for (int i = 0; i < 101; ++i) {
        map[i] = 0;
        visited[i] = false;
    }
}
