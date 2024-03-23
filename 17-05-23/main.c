#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

typedef struct list2_s {
    int val, count;
    struct list2_s *next;
} list2_t ;

typedef struct list1_s {
    char *string;
    list2_t *list2;
    struct list1_s *next;
} list1_t ;

list1_t *insert (char *name){
    FILE *fp;
    char str[MAX];
    int val;

    fp = fopen(name, "r");
    if (fp==NULL) exit(EXIT_FAILURE);

    list1_t *head1=NULL;
    while(fscanf(fp, "%s %d", str, &val)==2){
        list1_t *p = head1;
        // SEARCH FOR SAME STR
        if (head1==NULL){
            list1_t *node1 = (list1_t *) malloc(sizeof(list1_t));
            node1->string = (char *) malloc(sizeof(char) * (strlen(str)+1)); //***
            strcpy(node1->string, str);
            node1->list2 = (list2_t *) malloc(sizeof(list2_t));
            node1->list2->val = val;
            node1->list2->count = 1;
            node1->list2->next = NULL;
            node1->next = NULL;
            head1 = node1;
            continue; //***
        }
        while (p->next!=NULL && strcmp(p->next->string, str) != 0){
            p=p->next;
        }
        if (p->next != NULL){ //we found same string! let's analyze 2nd list.
            p =p->next;
            list2_t *p2 = p->list2;
            if (p2->val == val){
                p2->count +=1;
                continue;
            }
            while(p2->next!=NULL && p2->next->val != val){
                p2 = p2->next;
            }
            if (p2->next != NULL){
                p2->next->count +=1;
            }
            else {
                p2->next = (list2_t *) malloc(sizeof(list2_t));
                p2->next->val = val;
                p2->next->count = 1;
                p2->next->next = NULL;
            }
        }
        else { // string not found, add a new node to list 1.
            list1_t *node1 = malloc(sizeof(list1_t));
            node1->string = (char *) malloc(sizeof(char) * (strlen(str)+1));
            strcpy(node1->string, str);
            node1->list2 = malloc(sizeof(list2_t));
            node1->list2->val = val;
            node1->list2->count = 1;
            node1->list2->next = NULL;
            node1->next = head1;
            head1 = node1;
        }
    }
    fclose(fp);
    return head1;
}

// WHİLE LOOP
/*
        //list2_t *head2 = NULL;
        list1_t *p=head1;
        list1_t *p1 = (list1_t *) malloc(sizeof(list1_t));
        strcpy(p1->n, str);
        p1->list2 = NULL;

        while (p && strcmp(str, p->n)!=0){
            p=p->next;
        }

        if (p == NULL) { // same string not found
            p1->next = head1;
            head1 = p1;
            p1->list2 = (list2_t *)malloc(sizeof(list2_t));
            p1->list2->val = val;
            p1->list2->count = 1;
            p1->list2->next = NULL;
            head2 = p1->list2;
        }
        else { // same string found check the value. if same increase counter 1 else add new list2 node.
            list2_t *q = p->list2;
            list2_t *q1 = NULL;

            // search for the value in the secondary list
            while(q && q->val !=val){
                q1 = q;
                q=q->next;
            }

            if (q == NULL){
                q = (list2_t *) malloc(sizeof(list2_t));
                q->val = val;
                q->count = 1;
                q->next = NULL;

                if (q1 == NULL){
                    p->list2 = q;
                }
                else{
                    q1->next = q;
                }
            }
            else {
                q->count++;
            }
        }
         */

// ANOTHER SOLUTION
/*
 * #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

typedef struct list2 {
    int key, row;
    struct list2 *next;
} list2_t;

typedef struct list1 {
    char *name;
    struct list1 *next;
    list2_t *cont;
} list1_t;

list1_t *insert (char *name) {
    char string[MAX];
    int num;
    list1_t *head = NULL;

    FILE *fp = fopen(name, "r");
    if (fp == NULL) exit(EXIT_FAILURE);

    while (fscanf(fp, "%s %d", string, &num) != 2) {
        list1_t *p = head;
        if (head == NULL) {
            list1_t *node = malloc(sizeof(list1_t));
            node->name = malloc(strlen(string) * sizeof(char) + 1);
            strcpy(node->name, string);
            node->next = NULL;
            head = node;
            node->cont = malloc(sizeof(list2_t));
            node->cont->key = num;
            node->cont->row = 1;
            node->cont->next = NULL;
            continue;
        }
        while (p != NULL) {
            if (strcmp(p->name, string) == 0) {
                list2_t *p2 = p->cont;
                while (p2 != NULL) {
                    if (p2->key == num) {
                        p2->row++;
                        break;
                    }
                    p2 = p2->next;
                }
                if (p2 == NULL) {
                    list2_t *new = malloc(sizeof(list2_t));
                    new->key = num;
                    new->next = p->cont;
                    new->row = 1;
                    p->cont = new;
                }
                break;
            }
            p = p->next;
        }
        if (p == NULL) {
            list1_t *node = malloc(sizeof(list1_t));
            node->name = malloc(strlen(string) * sizeof(char) + 1);
            strcpy(node->name, string);
            node->next = head;
            head = node;
            node->cont = malloc(sizeof(list2_t));
            node->cont->key = num;
            node->cont->row = 1;
            node->cont->next = NULL;
        }
    }
    fclose(fp);
    return head;
}

int main() {


    return 0;
}

 *
 *
 */

int main() {


    return 0;
}
