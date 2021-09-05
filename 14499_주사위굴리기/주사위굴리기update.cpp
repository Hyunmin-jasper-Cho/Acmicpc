#include <iostream>

int N, M, x, y, k;
int map[21][21];
int command[1001] = {0, };
int xm[5] = {0, 0, 0, 1, -1};
int ym[5] = {0, 1, -1, 0, 0};

int l[5][3] = {
    {0, 0, 0},
    {2, 5, 1},
    {1, 5, 2},
    {4, 5, 3},
    {3, 5, 4}
};

int dice[6] = {0, };
int dice_pos[6] = {0, 1, 2, 3, 4, 5};
//                 T  E  W  F  R  B

void roll(int cmd, int nx, int ny);
void input();

int main() {
    input();
    
    int top_idx = dice_pos[0];
    int top_val = dice[top_idx];
    
    for (int i = 0; i < k; ++i) {
        int cmd = command[i];
        
        int nx = x + xm[cmd], ny = y + ym[cmd];
        if (nx >= 0 and nx < N and ny >= 0 and ny < M) { // movable
            roll(cmd, nx, ny);
            
            top_idx = dice_pos[0];
            top_val = dice[top_idx];
            printf("%d\n", top_val);
            
            if (map[x][y] == 0) {
                map[x][y] = dice[dice_pos[5]];
            } else {
                dice[dice_pos[5]] = map[x][y];
                map[x][y] = 0;
            }
        }
    }
    
}

void input() {
    scanf("%d %d %d %d %d", &N, &M, &x, &y, &k);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &(map[i][j]));
        }
    }
    
    for (int i = 0; i < k; ++i) {
        scanf("%d", command + i);
        
        if (command[i] == 4) command[i] = 3;
        else if (command[i] == 3) command[i] = 4;
    }
}


void roll(int cmd, int nx, int ny) {
    x = nx; y = ny;
    int tmp = dice_pos[0];
    
    dice_pos[0] = dice_pos[l[cmd][0]]; dice_pos[l[cmd][0]] = dice_pos[l[cmd][1]];
    dice_pos[l[cmd][1]] = dice_pos[l[cmd][2]]; dice_pos[l[cmd][2]] = tmp;
}
