#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int val;
    struct node_s *next;
} node_t;

// Iterating over a list
void printl(node_t *head){
    node_t *current = head;
    while (current!=NULL){
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

// Adding an item to the end of the list
void add(node_t *head, int val) {
    node_t *current = head;
    while (current->next !=NULL)
        current = current->next;
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

// Adding an item to the beginning of the list (pushing to the list)
void push(node_t **head, int val){
    node_t *p;
    p = (node_t *) malloc(sizeof(node_t));
    if (p==NULL) exit(EXIT_FAILURE);
    p->val = val;
    p->next = *head;
    *head = p;
}

// Removing the first item (popping from the list)
int pop(node_t ** head){
    int retval;
    node_t *next_node;
    if (*head == NULL) return -1;
    retval = (*head)->val;
    next_node = (*head)->next;
    free(*head);
    *head = next_node;

    return retval;
}

// Removing the last item of the list
int remove_last(node_t *head){
    int retval=0;

    // if there is only one item in the list, remove it
    if (head->next==NULL){
        retval=head->val;
        free(head);
        return retval;
    }

    // get to the second to last node in the list
    node_t *current = head;
    while(current->next->next!=NULL){
        current = current->next;
    }

    // now current points to the second to last item of the list, so lets remove current->next
    retval = current->next->val;
    free(current->next);
    current->next=NULL;
    return retval;
}

// Removing a specific item
int rem_by_val(node_t **head, int val){
    node_t *p = *head, *next_val=NULL;

    if(*head == NULL) return -1;
    if((*head)->val == val) return pop(head);

    while (p->next !=NULL && p->next->val!=val){
        p = p->next;
    }
    if (p->next != NULL){
        next_val = p->next->next;
        free(p->next);
        p->next = next_val;
    }

}

int main() {
    int i=0;
    node_t *head=NULL;
    head = (node_t *) malloc(sizeof(node_t));
    if (head==NULL) exit(EXIT_FAILURE);
    head->val=1;
    head->next=NULL;
    while (i<4){
        push(&head, i);
        i++;
    }
    printl(head);
    pop(&head);
    printl(head);
    return 0;
}