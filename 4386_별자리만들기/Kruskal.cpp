#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <cmath>

using namespace::std;

pair<double, double> stars[101];
double get_dist(int a, int b);

int parent[101];
void init();
int find(int x);
void merge(int a, int b);

int main() {
    init();
    
    
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;
    
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%lf %lf", &(stars[i].first), &(stars[i].second));
    }
    
    for (int i = 1; i <= N - 1; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            double dist = get_dist(i, j);
            pq.push({dist, {i, j}}); // i always smaller than j
        }
    }
    
    double t_dist = 0;
    while (!pq.empty()) {
        
        
        double dist = pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second; pq.pop();
        
        if (find(a) == find(b)) continue;
        
        merge(a, b);
        t_dist += dist;
    }
    
    printf("%.2f", t_dist);
    return 0;
}

double get_dist(int a, int b) {
    double A = pow(stars[a].first - stars[b].first, 2);
    double B = pow(stars[a].second - stars[b].second, 2);
    return sqrt(A + B);
}

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    
    if (x == y) return;
    
    parent[y] = x;
}

void init() {
    for (int i = 0; i <= 100; ++i) {
        parent[i] = i;
    }
}
