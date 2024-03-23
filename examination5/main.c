#include <stdio.h>
#define N 3

typedef struct node {
    int key;
    struct node *child[N];
} node_t;

void levelByLevel_visit_r(node_t *root,int level,int l){
    int i;

    if (root == NULL)
        return;

    if (level == l)
        printf("%d ", root->key);

    for (i=0;i<N;i++){
        levelByLevel_visit_r(root->child[i], level, l+1);
    }
}

void levelByLevel_visit(node_t *root, int l1, int l2){
    int i;
    for (i=l1;i<=l2;i++){
        levelByLevel_visit_r(root, i, 1);
        printf("\n");
    }
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
