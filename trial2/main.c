#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

int main() {
    int i,j, r;
    char **mat, str[N];
    printf("Number of rows: ");
    scanf("%d", &r);
    getchar();
    mat = (char **) malloc(r* sizeof(char *));
    if (mat == NULL){exit(EXIT_FAILURE);}
    for (i=0; i<r; i++){
        printf("String %d: ", i+1);
        fgets(str, N, stdin);
        mat[i] = malloc((strlen(str)+1)* sizeof(char));
        if (mat[i] == NULL){exit(EXIT_FAILURE);}
        strcpy(mat[i], str);
    }
    for (i=0;i<r;i++){
        printf("%s", mat[i]);
    }
    for (i=0;i<r;i++){
        free(mat[i]);
    }
    free(mat);
    return 0;
}
