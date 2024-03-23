#include <stdio.h>
int main() {
    int n, i, j;
    fscanf(stdin, "%d", &n);
    for(i=0;i<n+2;i++)
        printf("-");
    printf("\n");
    for(i=0;i<n;i++){
        printf("|");
        if (n%2==0) {
            if (i%2==0){
                for (j=0;j<n/2;j++)
                    printf("# ");
            }
            else {
                for (j=0;j<n/2;j++)
                    printf(" #");
            }
        }
        else {
            if (i%2==0){
                for (j=0;j<n/2;j++)
                    printf("# ");
                printf("#");
            }
            else {
                for (j=0;j<n/2;j++)
                    printf(" #");
                printf(" ");
            }
        }
        printf("|\n");
    }
    for(i=0;i<n+2;i++)
        printf("-");
    return 0;
}