#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define RED 1
#define BLACK -1
#define NONE 0

using namespace std;

int V, E;

void clr(int *arr);

int main() {
    int test_case; scanf("%d", &test_case);

    for (int i = 0; i < test_case; ++i) {
        queue<int> q;
        map<int, int> is_visit;

        scanf("%d %d", &V, &E);
        vector<int> adjacent_node_of[V + 1];
        int color[V + 1]; clr(color);
        bool is_bipartite = true;
        for (int j = 1; j <= V; ++j) {
            is_visit.insert(make_pair(j, 1));
        }

        for (int j = 0; j < E; ++j) {

            int a, b; scanf("%d %d", &a, &b);
            adjacent_node_of[a].emplace_back(b);
            adjacent_node_of[b].emplace_back(a);
        }

        while (!is_visit.empty()) {

            q.push(is_visit.begin()->first); // 맵의 첫번째 인자를 넣는다.
            color[is_visit.begin()->first] = RED; // search 의 시작점의 Color 를 Red 로 설정한다.


            while (!q.empty()) {
                int size = q.size();


                for (int j = 0; j < size; ++j) {

                    int cur_idx = q.front();
                    q.pop();
                    int cur_color = color[cur_idx];
                    is_visit.erase(cur_idx); // 방문처리..

                    for (auto &itr : adjacent_node_of[cur_idx]) {
                        if (color[itr] == NONE) { // 나의 인접 노드의 색이 없다면
                            // 나와 반대되는 색을 칠해준다.
                            color[itr] = -cur_color;
                            q.push(itr); // q 에 push..
                        } else { // 색이 존재한다면..
                            // 근데 나와 색이 같다면..
                            if (color[itr] == cur_color) {
                                is_bipartite = false; // 이분 그래프가 아님...
                                break;
                            }
                        }
                    } if (!is_bipartite) break;
                } if (!is_bipartite) break;
            } if (!is_bipartite) break;
        }


        if (!is_bipartite) {
            printf("NO\n");
        } else printf("YES\n");


    }

    return 0;
}

void clr(int *arr) {
    for (int i = 0; i <= V; ++i) {
        arr[i] = NONE; // 색상 초기화..
    }
}
