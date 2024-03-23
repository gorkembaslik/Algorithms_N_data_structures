#include <stdio.h>
#include <stdlib.h>

#define DIM1 5
#define DIM2 2

int main() {
    int i, j, v1[DIM1], v2[DIM2], count=0;
    printf("FIRST ARRAY OF INTEGERS: ");
    for(i=0;i<DIM1;i++){
        scanf("%d", &v1[i]);
    }
    printf("\nSECOND ARRAY OF INTEGERS: ");
    for(i=0;i<DIM2;i++){
        scanf("%d", &v2[i]);
    }
    for (i=0;i<DIM1-DIM2;i++){
        count = 0;
        for (j=0;j<DIM2;j++) {
            while(v1[i+j] == v2[j] && j != DIM2) {
                count++;
                j++;
            }
        }
        if (count == DIM2)
            break;
    }
    printf("\n");
    if (count == DIM2)
        return i;
    else
        return (EXIT_FAILURE);
}