#include <stdio.h>
#include <stdlib.h>


int display (float **mat, int n) {
    int a, j, i;
    for (int j=0;j<n; j++){
        a = j;
        i = 0;
        while(i<=j){
            fprintf(stdout, "%.2f ", mat[i][a]);
            i++; a--;
        }
        fprintf(stdout, "\n");
    }
    return 0;
}

float mat[5][5]= {{1,2,4,7,11},
                  {3,5,8,12,16},
                  {6,9,13,17, 20},
                  {10,14,18,21,23},
                  {15,19,22,24,25}};
int main() {
    float* matPtr[5]; // Array of float pointers
    for (int i = 0; i < 5; i++) {
        matPtr[i] = mat[i]; // Assign each row of mat to matPtr
    }
    display(matPtr, 5);
    return 0;
}
