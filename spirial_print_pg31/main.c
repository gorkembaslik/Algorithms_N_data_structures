#include <stdio.h>

#define N 5

int main() {
    int mat[N][N] = {};
    int i, j;
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            scanf("%d", &mat[i][j]);
        }
    }
     for (i=0;i<N/2;i++){
         for(j=i;j<N-i-1;j++){
             printf("%d", mat[i][j]);
         }
         printf("\n");
         for (j=i;j<N-i-1;j++){
             printf("%d", mat[j][N-i-1]);
         }
         printf("\n");

         for (j=N-1-i;j>i;j--){
             printf("%d", mat[N-i-1][j]);
         }
         printf("\n");

         for (j=N-i-1;j>i;j--){
             printf("%d", mat[j][i]);
         }
         printf("\n");
     }
     if (N%2)
         printf("%d", mat[N/2][N/2]);
    return 0;
}
