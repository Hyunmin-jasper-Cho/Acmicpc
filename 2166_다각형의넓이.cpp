// 신 발끈 공식 

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    int N; // N <= 10000
    cin >> N;
    
    
    double x[10001] = {0, }; // [1, N]
    double y[10001] = {0, };
    cin >> x[1] >> y[1];
    
    double sum = 0, sub = 0;
    for (int i = 2; i <= N; ++i) {
        scanf("%lf %lf", x + i, y + i);
        sum += (x[i - 1] * y[i]);
        sub += (y[i - 1] * x[i]);
    }
    sum += (x[N] * y[1]);
    sub += (y[N] * x[1]);
    
    double ans = (sum - sub) / 2;
    
    ans *= 10;
    ans = round(ans);
    ans /= 10;
    printf("%.1lf\n", ans < 0 ? -ans : ans);
    
    return 0;
}
