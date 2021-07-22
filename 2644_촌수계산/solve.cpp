#include <iostream>
#include <cstring>
#include <vector>
#include <deque>

using namespace std;

int parse_int(char *str);

void clr(bool *visited);

int main() {
    vector<int> v[101];
    deque<int> d;
    int N, A, B, K, cnt = 0;
    bool find = false;

    char input[10];
    bool visited[101]; clr(visited);

    fgets(input, 10, stdin);
    N = parse_int(input);

    fgets(input, 10, stdin);
    A = parse_int(strtok(input, " "));
    B = parse_int(strtok(nullptr, " "));

    fgets(input, 10, stdin);
    K = parse_int(input);

    for (int i = 0; i < K; ++i) {
        int r_a, r_b;
        fgets(input, 10, stdin);
        r_a = parse_int(strtok(input, " "));
        r_b = parse_int(strtok(nullptr, " "));

        // save relation
        v[r_a].push_back(r_b);
        v[r_b].push_back(r_a);
    }

    d.push_back(A); visited[A] = true;
    while (!d.empty()) {

        int size = (int) d.size();

        if (visited[B]) {
            find = true;
            break;
        }

        for (int i = 0; i < size; ++i) {

            // 일단 현재 노드 뽑는다..
            int cur = d.front(); d.pop_front();

            for (int & itr : v[cur]) {
                if (!visited[itr]) { // 방문하지 않았다면..
                    d.push_back(itr); visited[itr] = true;
                }
            }

        } cnt += 1;
    }

    if (find) {
        printf("%d", cnt);
    } else printf("-1");

    return 0;
}

void clr(bool *visited) {
    for (int i = 0; i < 101; ++i) {
        visited[i] = false;
    }
}

int parse_int(char *str) {
    return (int) strtol(str, nullptr, 10);
}
