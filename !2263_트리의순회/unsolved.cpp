#include <iostream>
#include <vector>
#include <queue>

typedef struct order Order;
struct order {
    int *post_order;
    int *in_order;
};

int N;
int get_index(const int *in, int value);
int get_next_root(std::vector<int> *child, int cur_idx, Order o);
void solve(Order o, std::queue<int> q, int *visit, std::vector<int> *left, std::vector<int> *right);

void clr(int *vis);

int main() {
    scanf("%d", &N);

    std::vector<int> left[N + 1];  // left[7].emplace_back(5): 7의 왼쪽에는 5 존재
    std::vector<int> right[N + 1];

    std::queue<int> q;

    Order o;
    o.in_order = new int[N + 1];
    o.post_order = new int[N + 1];
    int visit[N + 1]; clr(visit);


    for (int i = 1; i <= N; ++i) {
        scanf("%d", &(o.in_order[i]));
    }
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &(o.post_order[i]));
    }


    solve(o, q, visit, left, right);
    return 1;

    q.push(o.post_order[N]);
    while (!q.empty()) {
        int root = q.front(); q.pop(); visit[root] = 1; // 현재 노드 방문 처리..
        printf("%d ", root);

        // inorder 상에서 root 의 index 를 얻는다.
        int root_index = get_index(o.in_order, root);

        // 현재 루트에 대해서 좌, 우 에 존재하는 노드들을 추가한다.
        for (int i = root_index - 1; visit[o.in_order[i]] != 1; --i) {
            if (i == 0) break;
            left[root].emplace_back(o.in_order[i]);
        }
        for (int i = root_index + 1; visit[o.in_order[i]] != 1; ++i) {
            if (i == N + 1) break;
            right[root].emplace_back(o.in_order[i]);
        }

        // preorder 이므로 왼쪽 먼저 check
        if (!left[root].empty()) { // 왼쪽이 비어있지 않다면.. (= 왼편에 노드가 존재하면)

            // 왼편의 노드들 중에서 적절한 다음 root 를 찾는다.
            int next_root_value = get_next_root(left, root_index, o);

            // 그 root 의 값을 queue 에 넣는다.
            q.push(next_root_value);
            continue;
        }

        if (!right[root].empty()) {

            int next_root_value = get_next_root(right, root_index, o);
            q.push(next_root_value);
            continue;
        }

    }


    return 0;
}

void solve(Order o, std::queue<int> q, int *visit, std::vector<int> *left, std::vector<int> *right) {
    q.push(o.post_order[N]);

    while (!q.empty()) {
        int root = q.front(); q.pop(); visit[root] = 1; // 현재 노드 방문 처리..
        printf("%d ", root);

        // inorder 상에서 root 의 index 를 얻는다.
        int root_index = get_index(o.in_order, root);

        // 현재 루트에 대해서 좌, 우 에 존재하는 노드들을 추가한다.
        for (int i = root_index - 1; visit[o.in_order[i]] != 1; --i) {
            if (i == 0) break;
            left[root].emplace_back(o.in_order[i]);
        }
        for (int i = root_index + 1; visit[o.in_order[i]] != 1; ++i) {
            if (i == N + 1) break;
            right[root].emplace_back(o.in_order[i]);
        }





        // preorder 이므로 왼쪽 먼저 check
        if (!left[root].empty()) { // 왼쪽이 비어있지 않다면.. (= 왼편에 노드가 존재하면)

            // 왼편의 노드들 중에서 적절한 다음 root 를 찾는다.
            int next_root_value = get_next_root(left, root_index, o);

            // 그 root 의 값을 queue 에 넣는다.
            q.push(next_root_value);
        } if (!right[root].empty()) {

            int next_root_value = get_next_root(right, root_index, o);
            q.push(next_root_value);
            continue;
        }

    }

}

int get_post_index(const int *post, int value) {
    for (int i = 1; i <= N; ++i) {
        if (value == post[i]) return i;
    } return -1;
}

int get_next_root(std::vector<int> *child, int cur_idx, Order o) {
    int tmp = -1;
    for (auto & itr : child[o.in_order[cur_idx]]) {

        int idx = get_post_index(o.post_order, itr);
        tmp = idx > tmp ? idx : tmp;
    } return o.post_order[tmp];
}


int get_index(const int *in, int value) {
    for (int i = 1; i <= N; ++i) {
        if (value == in[i]) return i;
    } return -1;
}

void clr(int *vis) {
    for (int i = 0; i <= N; ++i) {
        vis[i] = 0;
    }
}
