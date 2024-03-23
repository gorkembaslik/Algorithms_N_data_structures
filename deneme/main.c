#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LEFT(i) (2*i+1)
#define RIGHT(i) (2*i+2)
#define PARENT(i) ((int)(i-1)/2)

typedef int Item;

typedef struct heap_s {
    Item *A;
    int heapsize
} heap_t;

void heapify (heap_t *heap, int i) {
    int l, r, largest;
    l = LEFT(i);
    r = RIGHT(i);
    if (l < heap->heapsize && heap->A[l] >= heap->A[i])
        largest = l;
    else
        largest =i;

    if (r < heap->heapsize && heap->A[r] >= heap->A[largest])
        largest = r;

    if (largest != i){
        swap(heap, i, largest);
        heapify(heap, largest);
    }
}

void heapbuild (heap_t *heap) {
    int i;

    for (i = (heap->heapsize) / 2 - 1; i >= 0; i--){
        heapify(heap, i);
}
}














/*
void mul (int *v1, int *v2, int n, int **pv){
    int f=0,s=0;
    int x;
    for (int i=0;i<n;i++){
        x = pow(10,n-i-1);
        f+=v1[i]*x;
        s+=v2[i]*x;
    }
    long int res=f*s;
    *pv = calloc(pow(2,n),sizeof(int));
    int a = pow(10,pow(2,n)-1);
    for (int i=0;i<pow(2,n);i++){
        while((int)(res/a) == 0){
            a/=10;
            i++;
        }
        (*pv)[i] = (int) res/a;
        res -= (*pv)[i]*a;
        a /=10;
    }
    for(int i=0;i<pow(2, n);i++){
        printf("%d", (*pv)[i]);
    }
}
int main(){
    int v1[] = {0,3,2};
    int v2[] = {2,4,3};
    int **pv = malloc(sizeof(int *));
    mul(v1,v2,3, pv);
    return 0;
}
*/
/*
typedef struct node {
    char *key;
    struct node *next;
}node_t;

node_t *splitStr(char *str){
    node_t *head = NULL;
    char *token = strtok(str,".");
    while(token != NULL){
        node_t *node = malloc(sizeof(node_t));
        node->key = malloc(sizeof(char)*strlen(token)+1);
        strcpy(node->key, token);
        node->next = head;
        head = node;
        token = strtok(NULL, ".");
    }
    return head;
}

int main(){
    char str[]="a.bb.ccc.dddd.eeeee.ffffff";
    node_t *a = splitStr(str);
    while(a != NULL){
        printf("%s\n", a->key);
        a = a->next;
    }
    return 0;
}
*/
/*
void localMax(int **mat, int n, int k){
    int i, j, r, c, a, b, max;
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            max = mat[i][j];
            a = (i-k<0) ? 0 : (i-k);
            b = (j-k<0) ? 0 : (j-k);
            for(r = a; r<=i+k && r<n ; r++){
                for(c = b; c<=j+k && c<n; c++){
                    if (mat[r][c]>=max) {
                        max = mat[r][c];
                    }
                }
            }
            if (max == mat[i][j] ){
                printf("ELEMENT %d LOCATED AT [%d, %d] is LOCAL MAX in RANGE %d\n", max, i, j, k);
            }
        }
    }
}
*/

/*
typedef struct node{
    char *key;
    struct node *L, *R;
}node_t;

void doubleTree(node_t *root, char flag){
    if (root == NULL)
        return;

    doubleTree(root->L, flag);
    doubleTree(root->R, flag);
    node_t *node = malloc(sizeof(node_t));
    if (node == NULL) exit(EXIT_FAILURE);
    strcpy(node->key, root->key);
    if (flag == 'L'){
        node->L= root->L;
        node->R= NULL;
        root->L = node;
    }
    else if (flag == 'R'){
        node->L= NULL;
        node->R= root->R;
        root->R = node;
    }
    return;
}
int main(){
    char s[10];
    sprintf(s, "paaapa");
    printf("%s", s);
}
*/


/*
int binarySearch(int v[], int l, int r, int key){
    if (r >= l){
        int mid = (l+r)/2;
        if (v[mid] == key)
            return mid;
        if (v[mid]<key)
            return binarySearch(v, mid+1, r, key);
        return binarySearch(v, l, mid-1, key);
    }
    return -1;
}
*/


/*
void invertString (char *s1, char **s2){
    *s2 = malloc(strlen(s1)*sizeof(char)+1);
    if (*s2 == NULL)
        exit(EXIT_FAILURE);

    int start, i=0, j=0;

    while (i<strlen(s1)){
        start=i;
        while (s1[i]<s1[i+2]){
            i+=2;
        }
        if (start != i) {
            for (int k = i; k >= start; k--) {
                (*s2)[j++] = s1[k];
            }
            i+=2;
            (*s2)[j++] = ' ';
        }
        if (s1[i]>=s1[i+2]){
            (*s2)[j++] = s1[i++]; (*s2)[j++] = s1[i++];
        }
    }
}

int main(){
    char s1[] = "A B C D D D D Z Y X W E F G";
    char *s2 = NULL;

    invertString(s1, &s2);

    printf("Original string: %s\n", s1);
    printf("Inverted string: %s\n", s2);

    free(s2);

    return 0;
}
*/

/*
void generate(int *temp, int n, int depth){
    if (depth == n) {
        for (int i=0;i<n;i++){
            printf("%d", temp[i]);
        }
        printf("\n");
        return;
    }

    for (int i=0;i<2;i++){
        temp[depth] = i;
        generate(temp, n, depth+1);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int *temp = calloc(n, sizeof(int));
    generate(temp, n, 0);
}
*/
