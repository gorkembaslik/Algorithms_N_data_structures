#include <stdio.h>
#include <stdlib.h>

char operators[] = {'+', '-', '*', '/'};

int calculation(int *temp, char *temp_op, int size){
    int sum=temp[0];

    for (int i=0; i<size-1;i++){
        switch (temp_op[i]) {
            case '+' :
                sum+= temp[i+1];
                break;
            case '-' :
                sum-= temp[i+1];
                break;
            case '*' :
                sum*= temp[i+1];
                break;
            case '/' :
                sum/= temp[i+1];
                break;
            default:
                fprintf(stderr, "erororo\n");
                exit(EXIT_FAILURE);
        }
    }
    return sum;
}

void perm_op(int *temp, int size, int result, char *temp_op, int size_op, int depth){

    if (depth == size-1){
        if (calculation(temp, temp_op, size) == result){
            printf("%d ", temp[0]);
            for (int i=0; i<size-1;i++){
                printf("%c %d ", temp_op[i], temp[i+1]);
            }
            printf("\n");
        }
        return;
    }

    for (int i=0; i<size_op; i++){
        temp_op[depth] = operators[i];
        perm_op(temp, size, result, temp_op, size_op, depth+1);
    }
}

void perm_int(int *v, int size, int result, int *temp, int *mark, int depth){

    if (depth == size){
        char *temp_op = (char *) malloc((size-1) * sizeof(char));
        perm_op(temp, size, result, temp_op , 4, 0);
        return;
    }

    for(int i=0;i<size;i++){
        if (!mark[i]){
            temp[depth]= v[i];
            mark[i] = 1;
            perm_int(v, size, result, temp, mark, depth+1);
            mark[i] = 0;
        }
    }

}

void calculator(int *v, int n, int result){
    int *mark = (int *) calloc(n, sizeof(int));
    int *temp = (int *) malloc(n * sizeof(int));

    perm_int(v, n, result, temp, mark, 0);

}

int main(){
    int v[] = {3,2, 25, 5};

    calculator(v, 4, 5);

}