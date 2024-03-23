#include <stdio.h>
#include <stdlib.h>

/* Exercise 1: Write the following function in c:
 void subMat_copy(int **m1, int r1, int c1, int **m2, int r2, int c2, int x, int y);
 it receives two matrices m1 and m2 of size (r1. c1) and (r2 c2) respectively.
 It copies the content of matrix m2 into matrix m1, such that the element
 in the upper-left corner of m2 is placed over element (x, y) of m1 and m1 and m2 overlap.
*/

void subMat_copy(int **m1, int r1, int c1, int **m2, int r2, int c2, int x, int y) {

    if (x < 0 || y < 0 || x > r1 || y > c1)
        return;
    for (int i = 0; i < r2 && i < r1 - x; i++) {
        for (int j = 0; j < c2 && j < c1 - y; j++)
            m1[x + i][y + j] = m2[i][j];
    }
}
/*
 * Exercise 2: A n-ary tree is defined as a left_child right-sibling structure as
 * the one reported on the left-hand side of the following picture. Node keys are
 * single characters. Augment the data structure such that each tree node stores
 * all necessary information to define a left_child right-sibling structure plus
 * an integer field to store the number of children and a pointer to the parent
 * Define the C data structure to store the augmented tree and write function:
 * void tree_complete(struct element *root, ...);
 * which given the original tree, stores in each node the number of children and
 * the pointer to the parent.
 */

typedef struct node {
    char key;
    int child;
    struct node *c, *s;
    struct node *p;
} element ;

int tree_complete (element *root, element *p){
    if (root == NULL)
        return 0;

    root->p = p;
    root->child = tree_complete(root->c, root);

    return (tree_complete(root->s, p) + 1);
}

int main() {
    element *root = malloc(sizeof(element));
    tree_complete (root, NULL);

    return 0;
}
