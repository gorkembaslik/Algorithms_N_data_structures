#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]) {
    int n, i, j, left, right;
    if (argc != 2){
        printf("Run with one odd integer value");
        return (EXIT_FAILURE);
    }
    n = atoi(argv[1]);
    if (n%2==0)
        return (EXIT_FAILURE);
    left = right = n/2;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (j == left || j == right)
                printf("+");
            else
                printf("-");
        }
        printf("\n");
        if (i < n/2){
            left--; right++;
        }
        else {
            left++; right--;
        }
    }
    return EXIT_SUCCESS;
}
