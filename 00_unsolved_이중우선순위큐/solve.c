#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct tree Tree;
typedef struct node Node;
struct node {
    int data;
    Node *left, *right;
};
struct tree {
    Node *root;
    int tree_size;
};

Tree *get_tree();
int del_least_child(Tree *t);
int del_max_child(Tree *t);

int main() {
    char input[50];

    scanf("%s", input);
    int test_case = (int) strtol(input, NULL, 10);

    for (int i = 0; i < test_case; ++i) {
        Tree *t = get_tree();

        scanf("%s", input);
        int k = (int) strtol(input, NULL, 10);
        getchar();


        for (int j = 0; j < k; ++j) {


            fgets(input, 50, stdin);

            char *cmd = strtok(input, " ");
            int value = (int) strtol(strtok(NULL, " "), NULL, 10);

            if (!strcmp(cmd, "I")) { // insert
                if (t->tree_size == 0) { // root
                    t->root->data = value;
                } else {
                    Node *tmp = t->root;

                    while (true) {
                        if (value > tmp->data) { // 크면 오른쪽
                            if (tmp->right != NULL) { // tmp 의 우측노드가 존재한다면..
                                tmp = tmp->right;
                            } else { // tmp 의 우측노드가 존재하지 않는다면..
                                tmp->right = (Node *) malloc(sizeof(Node));
                                tmp->right->data = value;
                                tmp->right->left = NULL;
                                tmp->right->right = NULL;

                                break;
                            }
                        } else { // 작거나 같으면 왼쪽
                            if (tmp->left != NULL) {
                                tmp = tmp->left;
                            } else {
                                tmp->left = (Node *) malloc(sizeof(Node));
                                tmp->left->data = value;
                                tmp->left->left = NULL;
                                tmp->left->right = NULL;

                                break;
                            }
                        }
                    }
                }
                t->tree_size += 1;
            } else { // delete

                if (t->tree_size >= 2) {
                    if (value == -1) {
                        del_least_child(t);
                    } else {
                        del_max_child(t);
                    }
                }

                if (t->tree_size != 0) {
                    t->tree_size -= 1;
                }

            }
        }


        if (t->tree_size == 0) {
            printf("EMPTY\n");
        } else if (t->tree_size == 1){
            printf("%d %d\n", t->root->data, t->root->data);
        } else if(t->tree_size == 2) {
            if (t->root->left == NULL) {
                printf("%d %d\n", t->root->right->data, t->root->data);
            } else {
                printf("%d %d\n", t->root->data, t->root->left->data);
            }
        } else {
            int l = del_least_child(t);
            int m = del_max_child(t);

            printf("%d %d\n", m, l);
        }
    }




    return 0;
}

int del_max_child(Tree *t) {
    // Assert: tree_size >= 2
    int ans = 0;

    Node *tmp = t->root;
    Node *p_tmp = NULL;
    while (tmp->right != NULL) {
        p_tmp = tmp;
        tmp = tmp->right;
    }


    if (p_tmp != NULL) {
        ans = tmp->data;
        if (tmp->left != NULL) {
            p_tmp->right = tmp->left;
        } else p_tmp->right = NULL;
    } else {
        ans = t->root->data;
        t->root = t->root->left;
    }
    return ans;
}

Tree *get_tree() {
    Tree *t = (Tree *) malloc(sizeof(Tree));
    t->root = (Node *) malloc(sizeof(Node));
    t->root->data = 0;

    t->root->left = NULL;
    t->root->right = NULL;
    t->tree_size = 0;

    return t;
}

int del_least_child(Tree *t) {
    // Assert: tree_size >= 2
    int ans = 0;

    Node *tmp = t->root;
    Node *p_tmp = NULL;
    while (tmp->left != NULL) {
        p_tmp = tmp;
        tmp = tmp->left;
    }


    if (p_tmp != NULL) {
        ans = tmp->data;

        if (tmp->right != NULL) {
            p_tmp->left = tmp->right;
        } else p_tmp->left = NULL;
    } else {
        ans = t->root->data;
        t->root = t->root->right;
    }
    return ans;
}
