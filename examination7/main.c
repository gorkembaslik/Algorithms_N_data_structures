#include <stdio.h>
#include <stdlib.h>

/* EXERCISE 2: Write function void tree_dup (struct node *root);
 * that for each node in a binary tree, creates a new duplicate node
 * ,and it inserts the duplicate as the left child of the original node.
 *        2                                2
 *       / \        original was:         / \
 *      2   3                            1   3
 *     /   /
 *    1   3
 *   /
 *  1
 *
*/

typedef struct node {
    int key;
    struct node *left, *right;
}node_t;

void tree_dup(node_t *root) {
    if (root == NULL)
        return;

    node_t *temp = malloc(sizeof(node_t));
    temp->key = root->key;
    temp->left = root->left;
    temp->right = NULL;
    root->left = temp;

    tree_dup(temp->left);
    tree_dup(root->right);
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
