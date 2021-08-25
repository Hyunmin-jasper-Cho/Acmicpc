#include <functional>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>

#define X first
#define Y second

using namespace::std;

typedef long long int ll;
typedef pair<double, pair<int, int>> vec;

double ans = 0;
ll gx[1001] = {0, };
ll gy[1001] = {0, };
int g_idx = 1;

int parent[1001];
void init(int n);

double get_dist(ll x1, ll y1, ll x2, ll y2);
int _find(int x);
void _union(int a, int b);

int main() {
    int N, M, cnt = 0;
    priority_queue<vec, vector<vec>, greater<>> pq;

    scanf("%d %d", &N, &M);

    init(N);

    // get pos of gods
    for (int i = 0; i < N; ++i) {
        scanf("%lld %lld", gx + g_idx, gy + g_idx); g_idx++;
    }

    for (int i = 0; i < M; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        if (a == b or parent[a] == parent[b]) continue;

        _union(a, b);
    }

    // get dist of gods
    for (int i = 1; i < N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (parent[i] == parent[j]) continue;

            pq.push({get_dist(gx[i], gy[i], gx[j], gy[j]), {i, j}});
        }
    }

    while (cnt < N - 2 and !pq.empty()) {
        double dist = pq.top().first;
        int A = pq.top().Y.X;
        int B = pq.top().Y.Y; pq.pop();

        if (_find(A) == _find(B)) continue;

        ans += dist;
        cnt++;
        _union(A, B);
    } printf("%.2lf", ans);


    return 0;
}

void init(int n) {
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
    }
}

double get_dist(ll x1, ll y1, ll x2, ll y2) {
    ll A = (x1 - x2) * (x1 - x2);
    ll B = (y1 - y2) * (y1 - y2);

    return sqrt((double) A + (double)B);
}

int _find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = _find(parent[x]);
}

void _union(int a, int b) {
    int A = _find(a);
    int B = _find(b);

    if (A == B) return;

    if (A < B) parent[B] = A;
    else parent[A] = B;
}
