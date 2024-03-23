#include <stdio.h>
#include <stdlib.h>

/* Write function void sequence_invert (int *v1, int n, int *v2);
 * where v1 and v2 are arrays of size n and such that the function receives v1, and it stores into v2
 * the same numbers stored int v1 but such that all ascending sub-sequences appearing in v1 are
 * transformed into descending sub-sequences in v2.
 * if v1 is the following: 1 2 3 4 5 0 12 13 14 2,
 * the function has to store into v2 the following numbers: 5 4 3 2 1 14 13 12 0 2
 */

void sequence_invert (int *v1, int n, int *v2){
    int i, f, j;

    for(i=0, f=1;f<n;f++){
        if (v1[f]<=v1[f-1]){
            for (j=0;j<(f-i);j++){
                v2[i+j]=v1[f-j-1];
            }
            i=f;
        }
    }
    for (j=0;j<(f-i);j++)
        v2[i+j] = v1[f-j-1];
}

int main() {
    int v1[] = {1,2,3,4,5,0,12,13,14,2};
    int n= 10, v2[n];

    sequence_invert(v1,n,v2);

    for(int i=0; i<n;i++){
        printf("%d ", v2[i]);
    }
    return 0;
}
