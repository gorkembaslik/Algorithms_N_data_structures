#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Exercise 1: Write function void sequence_invert (int *v1, int n, int *v2);
 * where v1 and v2 are arrays of size n and such that the function receives v1
 * and it stores into v2 the same numbers stored in v1 but such that all
 * ascending sub-sequences appearing in v1 are transformed into descending
 * sub-sequences in v2.
 * For example, if v1 is 1 2 3 4 5 0 12 13 14 2, the v2 should be 5 4 3 2 1 14 13 12 0 2
 */
/*
void sequence_invert (int *v1, int n, int *v2){
    int i, f, j;

    for (i=0, f=1; f<n; f++){
        if (v1[f] <= v1[f-1]) { // be careful here
            // End of sequence: Copy it in reverse order into v2
            for(j=0;j<(f-i);j++){
                v2[i+j] = v1[f-j-1];
            }
            i = f;
        }
    }
    // Deal with the last sub-sequence
    for (j=0; j<(f-i); j++){
        v2[i+j] = v1[f-j-1];
    }
}
*/

/* Exercise 2: A binary tree defined using the following C structure:
 * struct node {
 *  int key;
 *  struct node *left;
 *  struct node *right;
 * };
 * Write function: void path_write (struct node *root, int height, ...);
 * that, given a binary tree root of height equal to height, prints out
 * all keys along all of its root-to-leaf paths. Notice that, each path
 * has to be printed out entirely from root to leaf, i.e. the "path so far"
 * needs to be communicated between recursive calls.
 * If its necessary, its possible to add arguments to the path_write function.
 */

/* MY SOLUTION

typedef struct node {
    int key;
    struct node *left, *right;
}node_t ;

void path_write_r (node_t *root, int height, int *temp, int depth) {
    if (root == NULL){
        for (int i=0; i<depth;i++){
            printf("%d ", temp[i]);
        }
        printf("\n");
        return;
    }

    temp[depth] = root->key;
    path_write_r(root->left, height, temp, depth+1);
    path_write_r(root->right, height, temp, depth+1);
}

void path_write (node_t *root, int height) {
    int *temp = malloc(sizeof(int) * height);
    path_write_r(root->right, height, temp, 0);
}
*/

/* BOOK SOLUTION
struct node {
    int key;
    struct node *left;
    struct node *right;
};

static void path_write_r (struct node *, int, int, struct node **);

void path_write (struct node *root, int height) {
    //array of pointers to nodes of type struct node
    struct node **vet;

    vet = (struct node**) malloc(height*sizeof(struct node*));

    if (vet == NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    path_write_r(root, height, 0, vet);

    free(vet);
}
static void path_write_r (struct node *root, int height, int level, struct node **vet){

    if (root == NULL){
        fprintf(stdout, "Path: ");
        for (int i=0;i<level;i++) {
            fprintf(stdout, "%d ", vet[i]->key);
        }
        fprintf(stdout, "\n");
        return; // when we reach a leaf, return from the function.
    }
    vet[level] = root;
    path_write_r(root->left, height, level+1, vet);
    path_write_r(root->right, height, level+1, vet);
}
*/
/* EXERCISE 3: A password is a string of 5 characters, where:
 * The first 3 characters are capital alphabetic characters (A,B,...,Z).
 * The last 2 characters are digits (0,...,9).
 * The same letter or digit may appear in the password at most n times,
 * where n<=3 and its value is specified by the user.
 * For example; with n=2, passwords AAB11, ZDZ09 and ABC34 are acceptable, whereas XXX12 is not.
 * Write a recursive function able to generate all passwords satisfying
 * the previous constraints and to write them on standard output.
 */


int main() {
    int v1[] = {1, 2, 3, 4, 5, 0, 12, 13, 14, 2};
    int v2[10];

    for (int i=0; i<10; i++)
        printf("%d ", v2[i]);
    return 0;
}
