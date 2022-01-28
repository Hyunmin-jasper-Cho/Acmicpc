/**
 -100 -96 -17 -2 -1 1 9 98
 의 경우를 생각해보자.
 
 이 때, 배열의 sta, end 를 기준으로 두고 시작하면,
 우선 두 값을 합해본다. -> -100 + 98 = -2.
 이 수는 0보다 작기 때문에, 음의 부분의 수를 키워보면 0에 더 근접한 값을 얻을 수 있다. (key idea)
 */

#include <iostream>
#include <map>

#define LM 100000

using namespace std;
typedef long long int ll;

ll arr[LM + 1];

int main() {
    map<ll, pair<int, int>> m;
    
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) {
        scanf("%lld", arr + i);
    }
    
    int sta = 1, end = N; // [1, N], not [0, N - 1]
     
    if (N == 2) {
        printf("%lld %lld", arr[1], arr[2]); return 0;
    }
    while (sta != end) {
        ll mixed = arr[sta] + arr[end];
        
        // Terminate immediately
        if (mixed == 0) {
            cout << arr[sta] << " " << arr[end] << endl;
            return 0;
        }
        
        if (mixed < 0) { // -> to geet closure to 0..
            m.insert({-mixed, {sta, end}});
            sta++;
        } else {
            m.insert({mixed, {sta, end}});
            end--;
        }
        
    }
    
    auto itr = m.begin();
    cout << arr[itr->second.first] << " " << arr[itr->second.second];
    
    return 0;
}
