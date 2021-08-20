#include <iostream>
#include <cstring>
#define LM 1000000000

/*
 0 과 9 에서 예외 case 가 생긴다.
 그런데 n 번째의 0 의 개수는 n - 1 번째의 1의 개수와 같으며,
      n 번째의 9 의 개수는 n - 1 번째의 8의 개수와 같다.
 
 1, 2, ..., 8 은 이후 2쌍이 생기며
 0 과 9는 뒤이어 한 쌍만이 생긴다.
 
 
 */
typedef long long int ll;

ll num[10] = {0, };
ll tmp[10] = {0, };
ll dp[101] = {0, 9, };

void init();

int main() {
    init();
    int N; scanf("%d", &N);
    
    for (int i = 2; i <= 100; ++i) {
        ll sum = 0;
        tmp[0] = num[1] % LM;
        
        for (int j = 1; j <= 8; ++j) {
            tmp[j] = ((num[j - 1] % LM) + (num[j + 1] % LM)) % LM;
        } tmp[9] = num[8] % LM;
        
        for (int i = 0; i <= 9; ++i) {
            num[i] = tmp[i];
            sum += num[i];
        } dp[i] = sum % LM;
    }
    
    printf("%lld", dp[N]);
    
    return 0;
}


void init() {
    for (int i = 0; i <= 9; ++i) {
        num[i] = 1;
    } num[0] = 0;
}
