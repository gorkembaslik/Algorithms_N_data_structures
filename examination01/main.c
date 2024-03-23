#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Given 3 arrays of integer values of given length and ordered in ascending order, implement a merging operation.
 * The prototype of the function is the following: int *merge3(int *a, int *b, int *c, int na, int nb, int nc);
 * The parameters a, b and c are the 3 ordered input arrays of sizes na, nb and nc, respectively.
 * The function must return the ordered array of size (na+nb+nc) resulting from merging the 3 original arrays.
 * The output has to be dynamically allocated by the function.
 * The merge operation has to be unique for the three arrays, i.e. it is not allowed to merge the 3 arrays
 * by merging two of them and then the resulting array with the 3rd one.

int *merge3(int *a, int *b, int *c, int na, int nb, int nc){
    int *p, tot=na+nc+nb, i, x=0, y=0, z=0;
    p = (int *) malloc(tot*sizeof(int));
    if (p==NULL) exit(EXIT_FAILURE);

    for (i=0;i<tot;i++){
        if (x<na && a[x]<=b[y]){
            if (z<nc && c[z]<=a[x]){ // c[z] is the smallest
                p[i] = c[z]; z++;
            }
            else{ // a[x] is the smallest
                p[i] = a[x]; x++;
            }
        }
        else {
            if (y<nb && b[y]<=c[z]){ // b[y] is the smallest
                p[i] = b[y]; y++;
            }
            else{ // c[z] is the smallest
                p[i] = c[z]; z++;
            }
        }
    }
    return p;
}
*/

/* Exercise2: Write a C function able to insert some registry data in the correct position in an ordered list.
 * Data include the surname and name of a person. Both fields are strings of characters of max length equal to 20.
 * Use the surname as primary ordering key and the name as secondary ordering key.
 * The prototype of the function is the following:
 * int list_insert_in_order (list_t **headP, char *surname, char *name);
 * It receives the reference to the list pointer(of type list_t) and the two strings storing surname and name.
 * It returns integer value which is false when the person is already present in the list
 * and true when the insertion operation succeed.
 * Define the list_t type, considering that, for each person, surname and name have to be copied in new
 * dynamically allocated and separated fields.


typedef struct list_s {
    char *name;
    char *surname;
    struct list_s *next;
} list_t;

int list_insert_in_order (list_t **headP, char *surname, char *name){
    list_t *head = *headP, *node, *ptr;

    for(node=head;node!=NULL;node=node->next){
        if (strcmp(node->surname, surname) == 0 && strcmp(node->name, name) == 0 )
            return 0;
    }

    node =(list_t *) malloc(sizeof(list_t));
    if (node==NULL) exit(EXIT_FAILURE);

    strcpy(node->name, name);
    strcpy(node->surname,surname);

    // adjusting head
    if (head == NULL || strcmp(surname, head->surname)<0 ||
    (strcmp(surname, head->surname)==0 && strcmp(name, head->name)<0)){
        node->next = head;
        *headP = node;
        return 1;
    }

    ptr = head;
    while (ptr->next != NULL && (strcmp(surname, ptr->next->surname)>0 ||
    (strcmp(surname, ptr->next->surname)==0 && strcmp(name, ptr->next->name)>0))){
        ptr=ptr->next;
    }
    node->next = ptr->next;
    ptr->next = node;

    return 1;
}
*/

int main() {
    /* int a[] = {1,2,3,4,5};
    int b[] = {3,5,5,7,21,89};
    int c[] = {2,4,5,6,8,9};
    int *ml, i;
    ml = merge3(a,b,c,5,6,6);
    for (i=0;i<5+6+6;i++){
        printf("%d ", ml[i]);
    }
    */

    return 0;
}
