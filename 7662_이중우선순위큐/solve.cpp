#include <iostream>
#include <map>
#include <cstring>

using namespace std;
typedef long long int ll;

int main() {
    int test_case;
    char input[50];
    scanf("%d", &test_case);

    for (int i = 0; i < test_case; ++i) {
        map<ll, int> m;

        int n_of_cmd;
        scanf("%d", &n_of_cmd); getchar();

        for (int j = 0; j < n_of_cmd; ++j) {


            fgets(input, 50, stdin);
            char *cmd = strtok(input, " ");
            ll val = strtol(strtok(nullptr, " "), nullptr, 10);

            if (!strcmp(cmd, "I")) {

                auto itr = m.find(val);
                if (itr == m.end()) { // 없디면..
                    m.insert(make_pair(val, 1));
                } else { // 있다면..
                    itr->second += 1;
                }

            } else {
                // map 이 비어있으면 skip..
                if (m.empty()) continue;

                map<ll, int>::iterator itr;


                if (val == 1) { // 최댓값 삭제..
                    itr = prev(m.end());
                } else {
                    itr = m.begin();
                }
                if (itr->second - 1 == 0) {
                    m.erase(itr->first);
                } else itr->second -= 1;
            }


        }


        if (m.empty()) {
            printf("EMPTY\n");
        } else {

            auto f_itr = m.begin();
            auto r_itr = prev(m.end());

            printf("%lld %lld\n", r_itr->first, f_itr->first);
        }
    }




    return 0;
}
