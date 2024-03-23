#include <stdio.h>
#include <stdlib.h>

int calculate(int *temp, int n, int search){
    int sum;
    //ROW CHECK
    for (int i=0;i<n;i++){
        sum=0;
        for(int j=0;j<n;j++){
            sum+= temp[n*i+j];
        }
        if (sum != search)
            return 0;
    }
    // COLUMN CHECK
    for (int i=0;i<n;i++){
        sum=0;
        for(int j=0;j<n;j++){
            sum+= temp[n*j+i];
        }
        if (sum != search)
            return 0;
    }
    sum=0;
    for (int i=0;i<n;i++){
        sum+= temp[n*i+i];
    }
    if (sum != search)
        return 0;
    sum=0;
    for (int i=1;i<=n;i++){
        sum+= temp[n*i-i];
    }
    if (sum != search)
        return 0;
    return 1;
}

void magic_square(FILE *fp, int *temp, int n, int search, int *mark, int depth){
    if (depth == n*n) {
        if (calculate(temp, n, search)){
            for(int i=0; i<n*n;i++){
                if (i != 0 && i%n == 0)
                    fprintf(fp, "\n");
                fprintf(fp, "%d ", temp[i]);
            }
            fprintf(fp, "\n\n");
        }
        return;
    }

    for (int i=1;i<=n*n;i++){
        if (!mark[i-1]) {
            temp[depth] = i;
            mark[i - 1] = 1;
            magic_square(fp, temp, n, search, mark, depth+1);
            mark[i-1] = 0;
        }
    }
}

int main(int argc, char *argv[]){
    if (argc != 3)
        return EXIT_FAILURE;

    int n = atoi(argv[1]);
    FILE *fp = fopen(argv[2], "w");

    int *temp = malloc(sizeof(int)*n*n);
    int *mark = calloc(n*n, sizeof(int));

    magic_square(fp, temp, n, n*(n*n+1)/2, mark, 0);

    free(temp);
    free(mark);
    fclose(fp);
    return 0;
}