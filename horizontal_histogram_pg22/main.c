#include <stdio.h>

int main() {
    int i, a, vec[10] = {0};
    scanf("%d", &a);
    while (a >= 0 && a<=99){
        vec[a/10]++;
        scanf("%d", &a);
    }
    for(i=0;i<=90;i+=10){
        if (i<10)
            printf(" %d- %d ", i, i+9);
        else
            printf("%d-%d ", i, i+9);
        for (a=0;a<vec[i/10];a++){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}