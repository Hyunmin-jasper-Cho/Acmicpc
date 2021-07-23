#include <iostream>
#include <vector>

int d, cnt = 0, root_idx;

using namespace std;

typedef struct node Node;
struct node {
    vector<int> adjacent_list;
    Node *parent;
};


void solve(Node *nodes, int idx);

int main() {

    int N; scanf("%d", &N);
    int *arr = new int[N];
    Node *nodes = new Node[N];

    for (int i = 0; i < N; ++i) {
        scanf("%d", arr + i);
    }

    for (int i = 0; i < N; ++i) {

        if (arr[i] == -1) { // root..
            nodes[i].parent = nullptr;
            root_idx = i;
        } else {
            nodes[i].parent = &(nodes[arr[i]]);
            nodes[arr[i]].adjacent_list.push_back(i);
        }
    }

    scanf("%d", &d);


    if (d == root_idx) {
        printf("0");
    } else if (N == 2) {
        printf("1");
    } else {
        // traversal
        solve(nodes, root_idx);
        printf("%d\n", cnt);
    }

    return 0;
}

void solve(Node *nodes, int idx) {

    if (nodes[idx].adjacent_list.empty()) {
        cnt++;
        return;
    }

    for (auto itr = nodes[idx].adjacent_list.begin(); itr != nodes[idx].adjacent_list.end(); itr++) {

        if (*itr == d) {


            // 하나밖에 없는데 그걸 지웠다면..
            if (nodes[idx].adjacent_list.size() == 1) {
                // 그리고 그 노드의 부모가 root 가 아니라면.. (root != leaf..)
                if (nodes[*itr].parent != nodes + root_idx) {
                    cnt++; // leaf 이기 때문에..
                }
            }



            continue; // skip
        }

        solve(nodes, *itr);
    }
}

