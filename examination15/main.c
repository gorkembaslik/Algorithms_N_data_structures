#include <stdio.h>
#include <stdlib.h>

#define MAX 50
/* EXERCISE 2: A database of car models and car dealers is
 * organized as a BST of lists. The BST key is a string.
 * It represents car models. For each car model the corresponding
 * list stores the set of dealer names and the corresponding
 * selling prices (real values) selling that model.
 * The BST nodes are of type bst_t. The list nodes are of type
 * list1_t. Picture is provided in the book.
 * Write function:
 * void bst2list(bst_t *bst, list2_t **p, ...);
 * which receives BST of such a type and it created a list of
 * elements list2_t referenced by the pointer p. It is possible
 * to add other parameters if deemed as necessary.
 * The list list2_t has to store for each car model the model
 * name and the dealer name and price of the dealer with the
 * smallest price for that model.
 * The list has to be ordered alphabetically based on the car model.
 * Report the C struct definitions for types bst_t, list1_t and list2_t
 */

typedef struct list1 {
    char dealer[MAX];
    int price;
    struct list1 *next;
} list1_t;

typedef struct bst {
    char model[MAX];
    struct bst *l, *r;
    list1_t  *list;
} bst_t;

typedef struct list2 {
    char model[MAX];
    char dealer[MAX];
    int price;
    struct list2 *next;
} list2_t;

void bst2list(bst_t *bst, list2_t **p){
    if (bst == NULL)
        return;


    bst2list(bst->l, p);

    bst2list(bst->r, p);

}

int main() {
    list2_t **p = malloc(sizeof(list2_t *))
    return 0;
}
