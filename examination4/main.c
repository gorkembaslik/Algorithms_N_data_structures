#include <stdio.h>

#define MAX 11

/* A tree of degree equal to n can be represented using nodes
 * including n pointers or to avoid too large number of pointers,
 * using the left-child right-sibling technique is possible.
 * With this last method each node includes a pointer to the
 * leftmost child and to its nearest sibling to the right.
 * THE 3RD QUESTION:
 * Let us suppose that each node of the tree is represented
 * by a structure named node_t. node_t includes two strings
 * (first and last name) and an integer value (exam mark).
 * Define the C structure to represent the tree and write a
 * recursive function to print the entire content of a tree
 * once received its root pointer as a parameter.
 */

typedef struct node_s {
    char first[MAX], second[MAX];
    int mark;
    struct node_s *c, *s;
} node_t;

void print_tree(node_t *root){
    if (root == NULL)
        return;
    printf("%s %s %d", root->first, root->second, root->mark);
    print_tree(root->c);
    print_tree(root->s);
    return;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
