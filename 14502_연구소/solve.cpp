#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
pair<int, int> lst[3];
int vis[8][8] = {0, };
int map[8][8];
int tmp_map[8][8];

pair<int, int> f[41664];
pair<int, int> s[41664];
pair<int, int> t[41664];
int idx = 0;
int xm[4] = {0, 0, -1, 1};
int ym[4] = {-1, 1, 0, 0};

vector<pair<int, int>> idle;
vector<pair<int, int>> virus;

int safe_area = 0;

void get_per(int depth);
int bfs();
void set_map();

int main() {
    char input[30], *last;
    
    scanf("%d %d", &N, &M); getchar();
    for (int i = 0; i < N; ++i) {
        fgets(input, 30, stdin); last = input;
        for (int j = 0; j < M; ++j) {
            map[i][j] = (int) strtol(last, &last, 10);
            tmp_map[i][j] = map[i][j];
            if (map[i][j] == 0) {
                idle.emplace_back(make_pair(j, i));
                safe_area++;
            } else if (map[i][j] == 2) {
                virus.emplace_back(make_pair(j, i));
            }
        }
    }
    
    get_per(0);
    int cnt = -1;
    for (int i = 0; i < idx; ++i) {
        set_map();
        
        tmp_map[f[i].second][f[i].first] = 1;
        tmp_map[s[i].second][s[i].first] = 1;
        tmp_map[t[i].second][t[i].first] = 1;
        
        int tmp = bfs();
        cnt = tmp > cnt ? tmp : cnt;
    } printf("%d", cnt - 3); // 3 for wall...
    return 0;
}

int bfs() {
    int tmp_safe_area = safe_area;
    
    queue<pair<int, int>> q;
    for (auto & itr : virus) {
        q.push({itr.first, itr.second});
    }
    
    while (!q.empty()) {
        
        int size = (int) q.size();
        for (int i = 0; i < size; ++i) {
            int cx = q.front().first;
            int cy = q.front().second; q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int nx = cx + xm[i];
                int ny = cy + ym[i];
                
                if (nx >= 0 and nx < M and ny >= 0 and ny < N){
                
                    if (tmp_map[ny][nx] == 0) {
                        q.push({nx, ny});
                        tmp_safe_area--;
                        tmp_map[ny][nx] = 2;
                    }
                    
                }
                
            }
        }
    } return tmp_safe_area;
}

void get_per(int depth) {
    
    if (depth == 3) {
        f[idx].first = lst[0].first;
        f[idx].second = lst[0].second;
        
        s[idx].first = lst[1].first;
        s[idx].second = lst[1].second;
        
        t[idx].first = lst[2].first;
        t[idx].second = lst[2].second;
        
        idx++;
        return;
    }
    
    for (auto & itr : idle) {
        int x = itr.first;
        int y = itr.second;
        if (vis[y][x] == 0) {
            if (depth == 0 or (y * M + x > lst[depth - 1].first + (lst[depth - 1].second * M))) {
                vis[y][x] = 1;
                lst[depth].first = x; lst[depth].second = y;
                
                get_per(depth + 1);
                
                lst[depth].first = 0; lst[depth].second = 0;
                vis[y][x] = 0;
            }
        }
    }
}

void set_map() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            tmp_map[i][j] = map[i][j];
        }
    }
}
