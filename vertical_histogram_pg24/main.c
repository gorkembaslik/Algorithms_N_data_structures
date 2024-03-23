#include <stdio.h>

#define SIZE 10

int main() {
    int val;
    int class[SIZE] = {0};
    scanf("%d", &val);
    while (val>=0 && val<=99){
        class[val/SIZE]++;
        scanf("%d", &val);
    }
    int flag = 1;
    while (flag == 1) {
        flag = 0;
        for (int i = 0; i < SIZE; i++) {
            if (class[i] > 0) {
                printf("#");
                class[i]--;
                flag=1;
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}