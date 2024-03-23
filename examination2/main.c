#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Exercise1: Given an array vet of n integers, write function rotate which right or left-shift
 * the array of p positions, where p is an integer value (positive for right, negative for left shifts).
 * It is forbidden to implement the shift of p positions as the iteration of p shifts of 1 position each!
 * On the contrary, it is requested to implement an O(n) algorithm using an auxiliary array to move
 * all elements to their final destination "directly or through the temporary array itself".
 * The function has to allocate and free all required dynamic memory.
 * Example: If n=10, vet= {0 1 2 3 4 5 6 7 8 9} and p=-2,
 * the resulting array is {2 3 4 5 6 7 8 9 0 1} if  p=4,
 * the resulting array is {6 7 8 9 0 1 2 3 4 5}

void rotate(int vet[], int n, int p) {
    int d, i, j;
    d = p>0 ? p : -p;
    d = d>n ? d%n : d;

    int *tmp= (int *) malloc(n*sizeof(int));
    if (tmp == NULL) exit(EXIT_FAILURE);
    if (p>0){ // right rotation
        for (i=d,j=0;i<n;i++,j++)
            tmp[i]=vet[j];
        for(i=0, j=n-d;i<d;i++,j++)
            tmp[i]=vet[j];
        for(i=0;i<n;i++){
            vet[i]=tmp[i];
            printf("%d ", vet[i]);
        }
    }else {
        for(i=d, j=0;i<n;i++,j++)
            tmp[j]=vet[i];
        for(i=0, j=n-d;i<n;i++,j++)
            tmp[j]=vet[i];
        for(i=0;i<n;i++){
            vet[i]=tmp[i];
            printf("%d ", vet[i]);
        }
    }
    free(tmp);
}
*/

/* Exercise2: A matrix is said "sparse" when the majority of its elements are equal to 0. To store
 * a parse matrix, it may be convenient to use a data structure including only non-zero elements.
 * One possibility is to use an array of pointers to list of non-zero elements.
 * Write C function: void mat_insert (matr_t *mat, int r, int c, float value);
 * which insert the real value "value" into the element of row 'r' and column 'c' of the matrix "mat"
 * The type for matr_t is a structure which includes the two dimensions (number of rows nr and columns nc),
 * it points to an array of pointers (of size nr) to rows, each of which is implemented through a list,
 * containing only non-zero elements. Define the structure matr_t and the data structure used to implement
 * the lists along each row.
 */

typedef struct matr_s {
    

} matr_t;

int main() {


    return 0;
}