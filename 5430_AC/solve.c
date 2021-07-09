#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int test_case;
    scanf("%d", &test_case);

    for (int i = 0; i < test_case; ++i) {



        char cmd[100001];
        int N;

        scanf("%s", cmd);
        scanf("%d", &N);


        char *set = (char *) malloc(sizeof (char) * ((3 * N) * 2) + 3);
        scanf("%s", set);

        set[0] = '0';

        int *val = (int * ) malloc(sizeof (int) * N);
        int val_idx = 0;
        int left = 0, right = N - 1;
        bool to_right = true;
        bool to_left = false; // standard


        char *tok = strtok(set, ",");
        val[val_idx++] = (int) strtol(tok, NULL, 10);

        // Node *tmp = lst->root;
        while ((tok = strtok(NULL, ",")) != NULL) {
            val[val_idx++] = (int) strtol(tok, NULL, 10);
        }


        int pop_cnt = 0;
        bool is_error = false;
        int len = (int) strlen(cmd);

        for (int j = 0; j < len; ++j) {
            if (cmd[j] == 'R') { // reverse list
                if (to_right) {
                    to_right = false;
                    to_left = true;
                } else {
                    to_left = false;
                    to_right = true;
                }
            } else { // pop front

                // pop 하기 전에, pop 을 몇번 했는지 확인한다.
                // 만약, pop 을 N 번 했다면, 비어있다는 것이다.
                if (pop_cnt == N) {
                    is_error = true;
                    printf("error\n");
                    break;
                }

                // 우측방향이라면..
                if (to_right) {
                    left += 1;
                } else { // 좌측방향이라면..
                    right -= 1;
                }
                pop_cnt += 1;
            }
        }

        if (!is_error) {
            printf("[");
            if (to_right) {
                for (int j = left; j <= right; ++j) {
                    printf("%d", val[j]);
                    if (j != right) {
                        printf(",");
                    }
                }
            } else {
                for (int j = right; j >= left; --j) {
                    printf("%d", val[j]);
                    if (j != left) {
                        printf(",");
                    }
                }
            }
            printf("]\n");
        }
    }

    return 0;
}
