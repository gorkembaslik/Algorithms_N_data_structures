#include <stdio.h>
#include <string.h>

/* EXERCISE 2: Write the function
 * int tree_ismorphism(struct node *t1, struct node *t2);
 * that given two binary trees, referenced by t1 and t2, it
 * returns a true value if they are structurally identical
 * i.e, they are made of nodes with the same values
 * arranged in the same way
 * Suppose the tree has dynamic strings as keys.
 * Report the C data structure of the tree node.
 */

typedef struct node {
    char *key;
    struct node *left, *right;
} node_t;

int tree_ismorphism (node_t *t1, node_t *t2){
    if (strcmp(t1->key, t2->key) != 0)
        return 0;
    if (t1 == NULL && t2 == NULL)
        return 1;
    if (t1 == NULL || t2 == NULL)
        return 0;

    int l = tree_ismorphism(t1->left, t2->left);
    if (!l)
        return 0;
    int r = tree_ismorphism(t1->right, t2->right);
    if (!r)
        return 0;

    return 1;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
