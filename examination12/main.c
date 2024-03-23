#include <stdio.h>

/* EXERCISE 2: Write function:
 * int distance (node_t *root, int key1, int key2);
 * that receives a BST root referenced by root, storing
 * integer keys and two integer values key1 and key2 and
 * it returns the number of edges that it is necessary to
 * traverse to reach the node of key key1 starting from
 * key2 or vica-versa.
 */

typedef struct node {
    int key;
    struct node *r, *l;
}node_t;

int visit (node_t *root, int key){
    int d;
    if (root == NULL)
        return -1;

    if (key<root->key){
        d = visit(root->l, key);
        if (d>-1)
            return (d+1);
    }
    if (key>root->key){
        d = visit(root->r, key);
        if (d>-1)
            return (d+1);
    }

    return 0;
}

int distance (node_t *root, int key1, int key2){
    int d, d_left, d_right;

    if (root == NULL)
        return 0;

    if (key1<root->key && key2<root->key){
        d = distance(root->l, key1, key2);
    }
    else if (key1>root->key && key2>root->key) {
        d = distance(root->r, key1, key2);
    }
    else {
        if (key1<key2) {
            d_left = visit(root->l, key1);
            d_right = visit(root->r, key2);
        }
        else {
            d_left = visit(root->l, key2);
            d_right = visit(root->r, key1);
        }
        d = d_right+d_left;
    }

    return d;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
