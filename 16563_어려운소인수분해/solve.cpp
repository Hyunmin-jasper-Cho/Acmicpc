#include <iostream>
#include <cstring>
#include <cmath>
#define LM 5000001

using namespace std;

int N;

bool num[LM];
int save[LM];

/*
 
 각각에 맞는 최소 소인수를 저장한다(save 배열)
 i.e) 4: 2, 5: 5, 6: 2, 9: 3 과 같이..
 
 이후 약간의 재귀적인 방법으로 풀면 빠르다.
 
 i.e) 20
 save[20] = 2;
 따라서 20 --> 10 --> 5
 
 save[5] = 5;
 따라서 5 --> 1
 
 1 일 때 break;
 
 */

int s[1000000];

void init();

int main() {
    fill(begin(num), end(num), true);
    init();
    
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", s + i);
    }
    
    for (int i = 0; i < N; ++i) {
        
        int v = s[i];
        
        
        while (v != 1) {
            while (v % save[v] == 0) {
                printf("%d ", save[v]);
                v /= save[v];
                if (v == 1) break;
            }
        } printf("\n");
    }
    
    return 0;
}


void init() {
    for (int i = 0; i < LM; ++i) {
        save[i] = i;
    }
    
    num[0] = false; num[1] = false;
    for (int i = 4; i <= LM; i += 2) {
        num[i] = false;
        save[i] = 2;
    }
    
    for (int i = 3; i <= sqrt(LM) + 1; i += 2) {
        if (!num[i]) continue;
        for (int j = 2; i * j <= LM; ++j) {
            num[i * j] = false;
            save[i * j] = (i < save[i * j] ? i : save[i * j]);
        }
    }
}
