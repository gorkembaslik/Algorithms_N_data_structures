#include <stdio.h>
#define sum(a,b) (a+b)

int max_diff(int **mat, int r, int c){
    int i, j, min, max, diff, maxdiff=0, refi, refj;
    int row, column;

    for (i=0;i<r;i++){
        for (j=0;j<c;j++){
            min = 999; max = 0; // choosing the min and the max val in the diagonal
            refi= i; refj = j;
            while (refi>=0 && refj>=0){
                refi--; refj--;
            }
            while (refi<=r && refj<=c){
                if (mat[refi][refj]<min)
                    min = mat[refi][refj];
                if (mat[refi][refj]>max)
                    max = mat[refi][refj];
                refi++; refj++;
            }
            refi=i; refj=j;
            while (refi>=0 && refj<=c){
                refi--; refj++;
            }
            while (refi<=r && refj>=0){
                if (mat[refi][refj]<min)
                    min = mat[refi][refj];
                if (mat[refi][refj]>max)
                    max = mat[refi][refj];
                refi++; refj--;
            }
            diff = max-min;
            if (diff>maxdiff){
                row = i; column = j;
                maxdiff = diff;
            }
        }
    }
    printf("(%d, %d)", row, column);
    return maxdiff;
}

int main(void) {
    int s = sum(5,6);
    printf("%d ", s);
    return 22;
}