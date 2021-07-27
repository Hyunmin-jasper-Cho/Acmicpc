// 우선순위 큐 를 활용하는 문제로 
// 예외 case(line 22-31) 파악이 중요

#include <iostream>
#include <queue>

using namespace std;

int N, val;

int main() {
    priority_queue<int, vector<int>, less<>> ans;
    priority_queue<int, vector<int>, greater<>> save;

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &val);
        ans.push(val);

        if (ans.size() == (save.size() + 1)) {
            if (((int) save.size() != 0) and (save.top() < ans.top()) ) {
                int s_t = save.top();
                int a_t = ans.top();

                ans.pop();
                save.pop();

                ans.push(s_t);
                save.push(a_t);
            }

            printf("%d\n", ans.top());
        } else if (ans.size() == (save.size() + 2)) {
            save.push(ans.top()); ans.pop();
            printf("%d\n", ans.top());
        }
    }

    return 0;
}
