#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct time_val TV;
struct time_val {
    int sta_time, end_time;
};

int end_time_compare(const void *a, const void *b);

int main() {
    int ans = 0;

    char input[51];
    scanf("%s", input);
    getchar();

    int N = (int) strtol(input, NULL, 10);
    TV *time_val_arr = (TV *) malloc(sizeof (TV) * N);

    for (int i = 0; i < N; ++i) {
        fgets(input, 51, stdin);
        time_val_arr[i].sta_time = (int) strtol(strtok(input, " "), NULL, 10);
        time_val_arr[i].end_time = (int) strtol(strtok(NULL, " "), NULL, 10);
    } qsort(time_val_arr, N, sizeof(TV), end_time_compare);

    int end = time_val_arr[0].end_time;
    ans += 1;
    for (int i = 1; i < N; ++i) {
        if (time_val_arr[i].sta_time >= end) {
            ans += 1;
            end = time_val_arr[i].end_time;
        }
    }

    printf("%d\n", ans);

    return 0;
}

int end_time_compare(const void *a, const void *b) {
    // end time 이 작은 게 앞에..
    if (((TV *)a)->end_time == ((TV *)b)->end_time) {
        return ((TV *)a)->sta_time - ((TV *)b)->sta_time;
    } else return ((TV *)a)->end_time - ((TV *)b)->end_time;
}
