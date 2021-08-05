#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>

using namespace std;

int N;

int dfs(int adjacent_node_of[101][1], int start_index);
void dfs2(int adjacent_node_of[101][1], int start_index);
void init_vis();
unordered_map<int, bool> visited;
map<int, int> total;

int main() {


    scanf("%d", &N);
    int adjacent_node_of[101][1];
    unordered_map<int, pair<int, bool>> hm;
    vector<int> tmp;

    for (int j = 1; j <= N; ++j) {
        scanf("%d", &(adjacent_node_of[j][0]));
        // init as not visited..
        hm.insert(make_pair(j, make_pair(adjacent_node_of[j][0], false)));
        visited.insert(make_pair(j, true));
    }

    for (int i = 1; i <= N; ++i) {
        if (adjacent_node_of[i][0] == i) {
            visited.erase(i);
            tmp.emplace_back(i);
        }
    }

    for (int i = 1; i <= N; ++i) {
        init_vis();
        int start_index = i;

        int end_point_index = dfs(adjacent_node_of, start_index);

        if (start_index == hm.at(end_point_index).first) {
            tmp.emplace_back(start_index);
        }
    }


    init_vis();

    for (auto & itr : tmp) {
        dfs2(adjacent_node_of, itr);
    }

    printf("%d\n", (int) total.size());

    for (auto & itr : total) {
        printf("%d\n", itr.first);
    }
    return 0;
}

int dfs(int adjacent_node_of[101][1], int start_index) {
    visited.erase(start_index); // 방문처리..

    if (!visited.contains(adjacent_node_of[start_index][0])) { // 나의 인접 노드가 이미 방문되었다면..
        return start_index;
    } else {
        return dfs(adjacent_node_of, adjacent_node_of[start_index][0]);
    }
}

void dfs2(int adjacent_node_of[101][1], int start_index) {
    if (!visited.contains(start_index)) return;

    visited.erase(start_index);
    total.insert(make_pair(start_index, 1));

    if (visited.contains(adjacent_node_of[start_index][0])) {
        dfs2(adjacent_node_of, adjacent_node_of[start_index][0]);
    }
}

void init_vis() {
    visited.clear();
    for (int i = 0; i <= N; ++i) {
        visited.insert(make_pair(i, true));
    }
}
