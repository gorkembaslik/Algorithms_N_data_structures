#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Exercise1: A file stores an undefined number of rectangles. Each rectangle is defined by specifying on a single row
its bottom-left and top-right vertices. All rectangles have their sides parallel to the Cartesian axes
and they are places within the area in the Cartesian plane defined by points (0,0) and (10, 10).
 */
/*
#define SIZE 10
int area (FILE *fp);
int main() {
    FILE *fp;
    int a;
    fp = fopen("../file.txt", "r");

    a = area(fp);
    printf("area: %d", a);
    fclose(fp);
    return 0;
}
int area (FILE *fp) {
    int mat[SIZE][SIZE], count;
    int x1, y1, x2, y2;
    int r, c;
    for (r = 0; r < SIZE; r++) {
        for (c = 0; c < SIZE; c++)
            mat[r][c] = 0;
    }
    while (fscanf(fp, "%d%d%d%d", &x1, &y1, &x2, &y2) != EOF) {
        if (x1 < 0 || x1 > SIZE || y1 < 0 || y1 > SIZE
            || x2 < 0 || x2 > SIZE || y2 < 0 || y2 > SIZE) {
            fprintf(stderr, "Skipping rectangle out of bound\n");
            continue;
        }
        for (r = x1; r < x2; r++) {
            for (c = y1; c < y2; c++)
                mat[r][c] = 1;
        }
    }

    count = 0;
    for (r = 0; r < SIZE; r++) {
        for (c = 0; c < SIZE; c++) {
            if (mat[r][c] == 1)
                count++;
        }
    }
    return count;
}
*/

/*
Exercise2: The list_t structure is used to define a list of integer values. Write function:
void split(list_t **head, int threshold, list_t **head1, list_t **head2);
able to split such a list into two similar list based on the threshold value. The function receives by reference
the pointers to the head of the input list head and it returns two list pointers head1 and head2. It extracts all
elements from head and it inserts in head1 all elements smaller than the threshold and in head2 all elements larger
or equal to the threshold.
The order of the elements withing the original list head must be maintained into head1 and head2. At the end of
the function the list head must be empty. Notice that it is requested to write the code for the entire split function
without using library functions to manipulate lists.
 */
/*
typedef struct list_s {
    int val;
    struct list_s *next;
} list_t;

static list_t *enqueue (list_t *, list_t *);

void split(list_t **head, int threshold, list_t **head1, list_t **head2) {
    list_t *p, *tmp, *pTail1, *pTail2;
    pTail1 = NULL;
    pTail2 = NULL;
    p= *head;

    while (p!=NULL){
        // POP
        tmp = p;
        p = p->next;
        // ENQUEUE = add
        if (tmp->val < threshold){
            pTail1 = enqueue(pTail1, p);
        } else {
            pTail2 = enqueue(pTail2, p);
        }
    }
    *head = NULL;

    if (pTail1->next != NULL){
        *head1 = pTail1->next;
        pTail1->next = NULL;
    }
    if (pTail2->next != NULL){
        *head2 = pTail2->next;
        pTail1->next = NULL;
    }
}
// circular list implementation
list_t *enqueue (list_t *pTail, list_t *p) {
    if (pTail == NULL){
        pTail = p;
        pTail->next = p;
    } else {
        p->next = pTail->next;
        pTail->next = p;
        pTail = p;
    }

    return pTail;
}
 */

/* Exercise3: A set of bulbs are turned-on and off by a set of switches. Initially, all bulbs are turned off.
 * Each switch is connected to some set of bulbs; pressing the switch will turn each of them on if they are off,
 * and it will turn each of them off if they are on. An electrician would like to understand which is the
 * smaller set of switches (if it exists) that have to be pressed to turn-on all bulbs.
 * A matrix stores the "electrical connections", i.e.,
 * the set of bulbs that can be turned on and off by each switch.
 */
/*
#define NS 4
#define NB 5

void switchAndBulb (int mat[NS][NB], int ns, int nb, int *nBest, int switchBest[NS], int switchCurrent[NS], int level){
    int i, j, c, n, flag;
    

}
*/

