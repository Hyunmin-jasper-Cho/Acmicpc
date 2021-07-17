#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define max 1000000


int parse_int(char *str);
bool p_arr[max + 1];

int main() {

    p_arr[0] = true;
    p_arr[1] = true;

    // 짝수처리
    for (int i = 4; i <= max; i += 2) {
        p_arr[i] = true;
    }

    for (int i = 3; i <= sqrt(max) + 1; i += 2) {
        if (p_arr[i] == true) continue;
        for (int j = 2; i * j <= max; ++j) {
            p_arr[i * j] = true;
        }
    }




    char input[15];

    while (true) {
        scanf("%s", input);
        int val = parse_int(input);

        if (val == 0) return 0;

        int l_i = -1, l_j = -1;
        // 2 ~ val 까지..
        for (int i = 3; i <= val; ++i) {

            if (!p_arr[val - i] && !p_arr[i]) {
                l_i = i; l_j = val - i;
                break;
            }
        }

        printf("%d = %d + %d\n", val, l_i, l_j);

    }



}

int parse_int(char *str) {
    return (int) strtol(str, NULL, 10);

}
