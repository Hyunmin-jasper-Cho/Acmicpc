#include <stdlib.h>
#include <stdio.h>

typedef struct node Node;
typedef struct heap Heap;
struct heap {
    Node *root;
    Node **total_nodes;
    int heap_size;
};
struct node {
    int data, idx;
    Node *left_child, *right_child;
    Node *parent;
};

Heap *new_max_heap(int max_size);

int get_left_child_data(Node *p);
int get_right_child_data(Node *p);
int get_large_child_data(Node *p);

int pop_max(Heap *h);

int main() {
    int N;
    scanf("%d", &N);

    Heap *max_heap = new_max_heap(N);
    Node **total_nodes = max_heap->total_nodes;
    int node_itr = 1;

    for (int i = 0; i < N; ++i) {
        int cmd;
        scanf("%d", &cmd);

        if (cmd == 0) { // pop
            if (max_heap->heap_size == 0) printf("%d\n", 0);
            else {
                printf("%d\n", pop_max(max_heap));
                node_itr -= 1;
            }
        } else { // push
            total_nodes[node_itr++]->data = cmd;
            max_heap->heap_size += 1;

            int last_idx = max_heap->heap_size;
            Node *tmp = total_nodes[last_idx];

            while (tmp->idx != 1) {
                if (tmp->parent->data < tmp->data) {
                    int v = tmp->data;
                    tmp->data = tmp->parent->data;
                    tmp->parent->data = v;

                    tmp = tmp->parent;
                } else break;
            }
        }
    }


    return 0;
}

Heap *new_max_heap(int max_size) {
    Heap *h = (Heap *) malloc(sizeof(Heap));
    Node **nodes = (Node **) malloc(sizeof(Node *) * (max_size + 1));

    for (int i = 1; i <= max_size; ++i) {
        nodes[i] = (Node *) malloc(sizeof (Node));
        nodes[i]->data = 0;
        nodes[i]->idx = i;
        nodes[i]->parent = NULL;
    }

    for (int i = 1; i <= max_size; ++i) {
        if (i * 2 <= max_size) {
            nodes[i]->left_child = nodes[i * 2];
            nodes[i * 2]->parent = nodes[i];
        } else {
            nodes[i]->left_child = NULL;
        }
        if ((i * 2) + 1 <= max_size) {
            nodes[i]->right_child = nodes[(i * 2) + 1];
            nodes[(i * 2) + 1]->parent = nodes[i];
        } else {
            nodes[i]->right_child = NULL;
        }
    }
    h->root = nodes[1];
    h->heap_size = 0;
    h->total_nodes = nodes;
    return h;
}

int pop_max(Heap *h) {
    if (h->heap_size == 1) {
        int val = h->root->data;

        h->root->data = 0;
        h->heap_size -= 1;
        return val;
    }

    int last_idx = h->heap_size;
    int root_value = h->root->data;

    h->root->data = h->total_nodes[last_idx]->data; // 맨 마지막 data 위로 올리고..
    h->total_nodes[last_idx]->data = 0; // 맨 마지막 자리에 있는 data 0 으로 초기화한뒤..
    h->heap_size -= 1;     // 하나를 뺐으므로 size 하나 줄인다.

    // reconstruct
    Node *tmp = h->root;
    while (tmp->data < get_large_child_data(tmp)) {
        if (get_left_child_data(tmp) > get_right_child_data(tmp)) {
            int v = tmp->data;
            tmp->data = tmp->left_child->data;
            tmp->left_child->data = v;

            tmp = tmp->left_child;
        } else {
            int v = tmp->data;
            tmp->data = tmp->right_child->data;
            tmp->right_child->data = v;

            tmp = tmp->right_child;
        }
    }

    return root_value;
}

int get_left_child_data(Node *p) {
    if (p->left_child != NULL) return p->left_child->data;
    else return 0;
}
int get_right_child_data(Node *p) {
    if (p->right_child != NULL) return p->right_child->data;
    else return 0;
}
int get_large_child_data(Node *p) {
    return get_left_child_data(p) > get_right_child_data(p) ?
           get_left_child_data(p) : get_right_child_data(p);
}
