#include <iostream>
#include <queue>
#define INF "use the stairs"

using namespace std;
int vis[1000001] = {0, };

int main() {
    int F, S, G, U, D;
    // F: total F floor
    // S: current floor
    // G: goal
    // U, D
    
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    
    // case 1: S == F
    if (S == G) {
        printf("0"); exit(0);
    }
    
    // case 2: can't go up or down..
    if ((U == 0 and G > S) or (D == 0 and G < S)) {
        printf(INF); exit(0);
    }
    
    int time = 0;
    queue<int> q; q.push(S); vis[S] = 1;
    while (!q.empty()) {
        
        if (vis[G] == 1) {
            break;
        }
        
        int size = (int) q.size();
        for (int i = 0; i < size; ++i) {
            int cf = q.front(); q.pop();
            if (cf + U <= F) {
                if (vis[cf + U] == 0) {
                    vis[cf + U] = 1;
                    q.push(cf + U);
                }
            } if (cf - D >= 1) {
                if (vis[cf - D] == 0) {
                    vis[cf - D] = 1;
                    q.push(cf - D);
                }
            }
        } time++;
    }
    
    if (vis[G] == 1) {
        printf("%d", time);
    } else printf(INF);
    
    return 0;
}
