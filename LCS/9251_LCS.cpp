#include <iostream>
#include <cstring>
#include <cmath>

int dp[1001][1001] = {0, };
using namespace::std;

int main() {
    
    char str1[1002], str2[1002];
    cin >> str1 >> str2;
    
    int len1 = (int) strlen(str1);
    int len2 = (int) strlen(str2);
    
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            
            
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    cout << dp[len1][len2];
    
    
    return 0;
}

