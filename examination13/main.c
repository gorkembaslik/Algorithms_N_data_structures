#include <stdio.h>
#include <stdlib.h>

/* EXERCISE 2: Write function
 * struct node *tree_mirror(struct node* root);
 * that receives a pointer referencing an existing tree ,and it returns
 * another pointer referencing a newly allocated tree in which the
 * left and the right pointers are swapped at every node. Write the
 * C structure used to represent each tree node in case of tree
 * storing integers
 */

typedef struct node {
  int key;
  struct node *left, *right;
} node_t;

node_t *tree_mirror(node_t *root){
    if (root == NULL)
        return NULL;

    node_t *node = (node_t *) malloc(sizeof(node_t));
    if (node == NULL) return NULL;

    node->key = root->key;
    node->right = tree_mirror(root->left);
    node->left = tree_mirror(root->right);

    return node;
}


int main() {
    printf("Hello, World!\n");
    return 0;
}
