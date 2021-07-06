#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    char name;
    Node *left, *right;
};
void init(Node **nodes, int cnt);

void preorder(Node *root);
void inorder(Node *root);
void postorder(Node *root);

int main() {
    char *data = (char *) malloc(sizeof (char) * 6);
    char p, l, r;
    scanf("%s", data);

    int cnt = (int) strtol(data, NULL, 10);
    Node **nodes = (Node **) malloc(sizeof (Node *) * cnt);

    init(nodes, cnt);

    for (int i = 0; i < cnt; ++i) {
        getchar();
        scanf("%c %c %c", &p, &l, &r);

        if (l != '.') {
            nodes[p - 'A']->left = nodes[l - 'A'];
        }

        if (r != '.') {
            nodes[p - 'A']->right = nodes[r - 'A'];
        }
    }

    preorder(nodes[0]);
    printf("\n");
    inorder(nodes[0]);
    printf("\n");
    postorder(nodes[0]);


    return 0;
}

void preorder(Node *root) {
    if (root == NULL) return;

    printf("%c", root->name);
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%c", root->name);
    inorder(root->right);
}
void postorder(Node *root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%c", root->name);
}


void init(Node **nodes, int cnt) {
    for (int i = 0; i < cnt; ++i) {
        nodes[i] = (Node *) malloc(sizeof (Node));
        nodes[i]->name = (char) ('A' + i);
        nodes[i]->left = NULL;
        nodes[i]->right = NULL;
    }
}
