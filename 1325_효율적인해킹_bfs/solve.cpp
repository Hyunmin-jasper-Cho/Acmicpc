#include <iostream>
#include <limits>
#include <deque>

int N, M;
using namespace std;

class vertex{
public:
    int data{};
    deque<int> adjacent_list;

    void link(int adjacent_node) {
        this->adjacent_list.push_front(adjacent_node);
    }
};

int bfs(int sta_node, vertex *v, bool *visited);

int main() {
    deque<int> q;

    scanf("%d %d", &N, &M);
    int *ans = new int[N + 1];
    bool *visited = new bool[ N+ 1];
    auto *v = new vertex[N + 1];


    for (int i = 1; i <= M; ++i) {
        int at, to;
        scanf("%d %d", &at, &to);
        v[to].link(at);
    }

    int max = -2147483647;
    for (int i = 1; i <= N; ++i) {
        ans[i] = bfs(i, v, visited);
        if (max < ans[i]) max = ans[i];

        for (int j = 1; j <= N; ++j) {
            visited[j] = false;
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (ans[i] == max) printf("%d ", i);
    }

    return 0;
}

int bfs(int sta_node, vertex *v, bool *visited) {
    int cnt = 0;

    deque<int> d;
    d.push_back(sta_node);
    visited[sta_node] = true;
    while (!d.empty()) {

        int size = (int) d.size();
        for (int i = 0; i < size; ++i) {
            int cur = d.back();
            d.erase(prev(d.end()));

            for (int next_val : v[cur].adjacent_list) {
                if (!visited[next_val]) {
                    d.push_back(next_val);
                    visited[next_val] = true;
                    cnt += 1;
                }
            }
        }
    }

    return cnt;
}
