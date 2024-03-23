#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Exercise 1: Searching array of intergers in another array of integers.
 * Return the starting index of array if its found, otherwise, -1.
 *

int search(int *v1, int *v2, int d1, int d2){
    int i, j, count;
    for (i = 0; i<d1-d2+1;i++){
        count=0;
        for(j=0;j<d2;j++){
            if(v2[j]==v1[i+j])
                count++;
        }
        if (count == d2)
            return i;
    }
    return -1;
}
*/
/*
 * Exercise 2: A bi-linked list (linked on both right and left sides) of integer is given. Let node_t be
 * the basic data type of each element of the list. Implement the following two functions:
 * --> void list_insert (node_t **left, node_t **right, int key, int leftRight);
 * to insert the value key on the left extreme of the list (pointer left) if the parameter
 * leftRight=0 or to the right extreme of the list (pointer right) if the parameter
 * leftRight=1.
 * --> void list_write (node_t *left, node_t *right, int leftRight);
 * to print-out (on standard output) the content of the entire list, visiting it from
 * left-to-right if the parameter leftRight=0 or from right-to-left if leftRight=1
 * The definition of node_t has to be given by the student.
 */

typedef struct node_s{
    int key;
    struct node_s *left, *right;
} node_t;

void list_insert (node_t **left, node_t **right, int key, int leftRight){
    node_t *new = (node_t *) malloc(sizeof(node_t));
    if (new == NULL) exit(EXIT_FAILURE);
    new->key = key;

    if (*left == NULL || *right == NULL){
        new->right = NULL;
        new->left = NULL;
        *left = new;
        *right = new;
    }

    if (leftRight == 0) { // left insertion
        new->right = *left;
        new->left = NULL;
        *left = new;
    }
    else if (leftRight == 1) { // right insertion
        new->left = *right;
        new->right = NULL;
        *right = new;
    }
    else {
        fprintf(stderr,"wrong leftRight input\n");
        exit(EXIT_FAILURE);
    }
}

void list_write (node_t *left, node_t *right, int leftRight){
    node_t *p;
    if (leftRight==0){
        p = left;
        while (p != NULL){
            printf("%d ", p->key);
            p = p->right;
        }
    }
    else if (leftRight==1){

    }
    else{
        fprintf(stderr,"wrong leftRight input\n");
        exit(EXIT_FAILURE);
    }
}
/*
void list_insert (node_t **left, node_t **right, int key, int leftRight){
    node_t *p;
    p = malloc(sizeof(node_t)); // node allocation and field initialization
    if (p == NULL){
        fprintf(stderr, "memory allocation problem\n");
        exit(EXIT_FAILURE);
    }
    p->key = key;

    if (leftRight == 0){
        // insert to left
        p->right = *left;
        p->left = NULL;
        if (*left != NULL)
            (*left)->left = p;
        *left = p;
        if (*right == NULL)
            *right = *left;
    }
    else if (leftRight == 1){
        p->left = *right;
        p->right = NULL;
        if (*right != NULL)
            (*right)->right = p;
        *right=p;
        if (*left == NULL)
            *left = *right;
    }
    else{
        fprintf(stderr, "wrong side 0 for left, 1 for right\n");
        exit(EXIT_FAILURE);
    }
}

void list_write (node_t *left, node_t *right, int leftRight){
    node_t *p;

    if (leftRight == 0){
        fprintf(stdout,"LEFT2RIGHT: ");
        p = left;
        while (p != NULL){
            fprintf(stdout, "%d ", p->key);
            p = p->right;
        }
        fprintf(stdout, "\n");
    }
    else if (leftRight == 1){
        fprintf(stdout, "RIGHT2LEFT: ");
        p = right;
        while (p != NULL){
            fprintf(stdout,"%d ", p->key);
            p = p->left;
        }
        fprintf(stdout,"\n");
    }
    else {
        fprintf(stderr, "wrong side 0 for left, 1 for right\n");
        exit(EXIT_FAILURE);
    }
}
*/


int main() {
    int v1[] = {1, 2, 3,4,5,6,7,8,9,10};
    int v2[] = {4,5,6,7};

    //int a = search(v1, v2, 10, 4);
    //printf("%d ", a);
    return 0;
}