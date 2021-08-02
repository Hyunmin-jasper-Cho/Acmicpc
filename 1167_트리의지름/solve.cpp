#include <iostream>
#include <vector>

using namespace std;

void clr(int *dist, int n);
void solve(int *dist, int *vis, int sta, vector<pair<int, int>> *adjacent, int tmp);
int find_max_index(const int *dist, int N);

int main() {
    int N; scanf("%d", &N);

    vector<pair<int , int>> adjacent_node_of[N + 1];
    int vis[N + 1]; clr(vis, N);
    int dist[N + 1]; clr(dist, N);

    for (int i = 0; i < N; ++i) {
        int to; scanf("%d", &to);

        while (true) {
            int at, cost;
            scanf("%d", &at);
            if (at == -1) break;
            else scanf("%d", &cost);

            adjacent_node_of[to].emplace_back(make_pair(at, cost));
        }
    }


    solve(dist, vis, 1, adjacent_node_of, 0);
    int idx = find_max_index(dist, N); clr(dist, N); clr(vis, N);


    solve(dist, vis, idx, adjacent_node_of, 0);
    idx = find_max_index(dist, N);
    printf("%d", dist[idx]);

    return 0;
}

int find_max_index(const int *dist, int N) {
    int max_val = 0, max_idx = 1;
    for (int i = 1; i <= N; ++i) {
        if (max_val < dist[i]) {
            max_val = dist[i]; max_idx = i;
        }
    }
    return max_idx;
}

void solve(int *dist, int *vis, int sta, vector<pair<int, int>> *adjacent, int tmp) {
    vis[sta] = 1;

    for (auto & itr : adjacent[sta]) { 

        if (vis[itr.first] == 0) {
            dist[itr.first] = itr.second + tmp;
            solve(dist, vis, itr.first, adjacent, itr.second + tmp);
        }
    }
}

void clr(int *dist, int n) {
    for (int i = 0; i <= n; ++i) {
        dist[i] = 0;
    }
}
