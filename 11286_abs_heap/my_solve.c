#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define max 100000

void reconstruct_push(int *heap, int idx);
void reconstruct_pop(int *heap, int idx);
void init_min_heap(int *heap);

int main() {
    int positive_min_heap[max + 1];
    int pos_idx = 1;


    int negative_min_heap[max + 1];
    int neg_idx = 1;

    init_min_heap(positive_min_heap);
    init_min_heap(negative_min_heap);

    char input[13];
    scanf("%s", input);

    int N = (int) strtol(input, NULL, 10);
    for (int i = 0; i < N; ++i) {
        scanf("%s", input);
        if (!strcmp(input, "0")) { // pop 연산

            if (pos_idx == 1 && neg_idx == 1) { // 둘 다 비어있을 때 pop
                printf("0\n");
                continue;
            }


            if (neg_idx == 1 || (positive_min_heap[1] < negative_min_heap[1])) { // negative heap 만 비어있을 때 혹은 pos abs 가 neg abs 보다 작을 때
                printf("%d\n", positive_min_heap[1]);
                pos_idx -= 1;
                positive_min_heap[1] = positive_min_heap[pos_idx];
                positive_min_heap[pos_idx] = INT_MAX;

                if (pos_idx > 2) {
                    reconstruct_pop(positive_min_heap, pos_idx);
                }
            } else {
                printf("-%d\n", negative_min_heap[1]);
                neg_idx -= 1;
                negative_min_heap[1] = negative_min_heap[neg_idx];
                negative_min_heap[neg_idx] = INT_MAX;

                if (neg_idx > 2) {
                    reconstruct_pop(negative_min_heap, neg_idx);
                }

            }

        } else { // push 연산
            int val = (int) strtol(input, NULL, 10);

            if (val >= 0) { // insert to positive_min_heap
                positive_min_heap[pos_idx++] = val;

                if (pos_idx != 2) { // reconstruct
                    reconstruct_push(positive_min_heap, pos_idx);
                }
            } else {        // insert to negative_min_heap
                negative_min_heap[neg_idx++] = abs(val);

                if (neg_idx != 2) { // reconstruct
                    reconstruct_push(negative_min_heap, neg_idx);
                }
            }
        }
    }

    return 0;
}

void init_min_heap(int *heap) {
    for (int i = 1; i < max; ++i) {
        heap[i] = INT_MAX;
    }
}

void reconstruct_push(int *heap, int idx) {
    int tmp_idx = idx - 1;
    while (tmp_idx != 1) {
        if (heap[tmp_idx] < heap[tmp_idx / 2]) {
            // swap
            int tmp_val = heap[tmp_idx];
            heap[tmp_idx] = heap[tmp_idx / 2];
            heap[tmp_idx / 2] = tmp_val;
        } else return;
        tmp_idx /= 2;
    }
}
void reconstruct_pop(int *heap, int idx) {
    int tmp_idx = 1;

    while (tmp_idx < idx) {

        if (heap[tmp_idx * 2] == INT_MAX && heap[tmp_idx * 2 + 1] == INT_MAX) { // 좌측, 우측 자식이 모두 존재하지 않는다면..
            break; // 정지한다.
        }

        if (heap[tmp_idx * 2] < heap[tmp_idx * 2 + 1]) { // 왼쪽 자식이 더 작다면..
            if (heap[tmp_idx] > heap[tmp_idx * 2]) {     // 그 왼쪽 자식이 부모보다 작다면..
                // swap
                int tmp_val = heap[tmp_idx];
                heap[tmp_idx] = heap[tmp_idx * 2];
                heap[tmp_idx * 2] = tmp_val;

                tmp_idx *= 2;
            } else return;
        } else {
            if (heap[tmp_idx] > heap[tmp_idx * 2 + 1]) { // 그 우측 자식이 부모보다 작다면..
                // swap
                int tmp_val = heap[tmp_idx];
                heap[tmp_idx] = heap[tmp_idx * 2 + 1];
                heap[tmp_idx * 2 + 1] = tmp_val;

                tmp_idx = tmp_idx * 2 + 1;
            } else return;
        }

    }
}
