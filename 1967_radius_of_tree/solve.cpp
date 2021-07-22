// RECURSION


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ans[10001];
int largest[10001];
int n_large[10001];
int solve(vector<pair<int, int>> v[10001], int root);

int main() {

    vector<pair<int, int>> v[10001];

    int N; scanf("%d", &N);
    for (int i = 0; i < N - 1; ++i) {

        int to, at, cost;
        scanf("%d %d %d", &to, &at, &cost);

        v[to].emplace_back(at, cost);
    }
    solve(v, 1);
    for (int i = 1; i <= N; ++i) {
        ans[i] = largest[i] + n_large[i];
    }

    sort(ans, ans + (N + 1));

    printf("%d", ans[N]);

    return 0;
}

int solve(vector<pair<int, int>> v[10001], int root) {

    for (auto itr = v[root].begin(); itr != v[root].end(); ++itr) {
        int tmp = solve(v, itr->first) + itr->second;

        if (tmp > largest[root]) {
            n_large[root] = largest[root];
            largest[root] = tmp;
        } else if (tmp > n_large[root]) {
            n_large[root] = tmp;
        }
    }
    return largest[root];
}
