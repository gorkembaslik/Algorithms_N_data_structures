#include <stdio.h>
#include <stdlib.h>

int main() {
    int mat[6][5];
    int **m, r=6, c=5;
    m = (int **) malloc(r*  sizeof(int *));
    for (int i=0;i<r;i++){
        m[i] = malloc(c* sizeof(int));
    }
    printf("%d\n%d\n%d\n", sizeof(mat), sizeof(mat[3]), sizeof(mat[4][2]));

    printf("m\n%d\n%d\n%d\n", sizeof(*m), sizeof(m), sizeof(*(*m)));
    return 0;
}
