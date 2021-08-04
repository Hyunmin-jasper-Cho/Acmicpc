#include <iostream>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

int is_prime[10000] = {0, }; // 0 <= v <= 9999
void clr();

int main() {
    clr();

    int test_case; scanf("%d", &test_case);
    for (int i = 0; i < test_case; ++i) {

        bool find = false;
        queue<int> q;
        map<int, int> visited;

        int a, b, tmp; scanf("%d %d", &a, &b);
        if (a > b) {
            tmp = a;
            a = b;
            b = tmp;
        }

        q.push(a); visited.insert(make_pair(a, 1)); int depth = 0;
        while (!q.empty()) {

            if (visited.contains(b)) {
                find = true;
                break;
            }

            if (depth == 5) {
                int v = 3;
            }


            int size = q.size();



            for (int j = 0; j < size; ++j) {


                int cur_val = q.front(); q.pop();

                // 현재 value 에 대해서 자릿수 변경해본다..


                // 각 자릿수 구하고..
                int tmp_val = cur_val;
                int idx[4];
                for (int & k : idx) {
                    k = tmp_val % 10; tmp_val /= 10;
                }


                for (int index = 0; index < 4; ++index) {


                    tmp_val = cur_val; // 현재 값에 대해....

                    for (int k = 0; k <= 9; ++k) {



                        tmp_val = idx[3] * (int) pow(10, 3)
                                + idx[2] * (int) pow(10, 2)
                                + idx[1] * (int) pow(10, 1)
                                + idx[0] * (int) pow(10, 0)
                                - idx[index] * (int) pow(10, index)
                                + k * (int) pow(10, index);

                        if (tmp_val < 1000 or tmp_val >= 10000) continue; // skip..

                        if (is_prime[tmp_val] == 0) { // 바뀐 수가 prime 이라면..
                            if (!visited.contains(tmp_val) and tmp_val < 10000) { // 방문하지 않았고 10000 보다 작다면..
                                q.push(tmp_val); // q 에 넣는다
                                visited.insert(make_pair(tmp_val, 1)); // 방문처리..
                            }
                        }
                    }
                }

            }


            depth += 1;
        }


        if (find) printf("%d\n", depth);
        else printf("Impossible\n");
    }

    return 0;
}

void clr() {
    is_prime[0] = 1;
    is_prime[1] = 1;

    // 짝수처리..
    for (int i = 4; i < 10000; i += 2) {
        is_prime[i] = 1; // 4, 6, 8, ...
    }

    for (int i = 3; i <= sqrt(10000) + 1; i += 2) {
        if (is_prime[i] == 1) continue; // skip...

        for (int j = 2; i * j < 10000; ++j) {
            is_prime[i * j] = 1;
        }
    }
}
