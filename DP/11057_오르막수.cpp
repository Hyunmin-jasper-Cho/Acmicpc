#include <iostream>
#include <cstring>
#define LM 10007

typedef long long int ll;

ll num[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
ll tmp[10] = {0, };
ll dp[1001] = {0, 10, 0, };

int N;

int main() {
    scanf("%d", &N);
    
    
    for (int k = 2; k <= 1000; ++k){
        memset(tmp, 0, sizeof(tmp));
        
        for (int i = 0; i <= 9; ++i) {
            for (int j = 0; j <= i; ++j) {
                tmp[i] += num[j] % LM;
            } tmp[i] %= LM;
        }
        
        for (int i = 0; i <= 9; ++i) {
            num[i] = tmp[i];
            dp[k] += num[i];
        } dp[k] %= LM;
    
    }
    
    printf("%lld", dp[N] % LM);
    
    return 0;
}
