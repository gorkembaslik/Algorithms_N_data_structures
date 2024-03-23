#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char str[MAX];
    scanf("%s", str);
    int len = strlen(str), k;
    for (int i=0; i<len; i++){
        for (int j=0; j<len; j++){
            k = (i+j) % len;
            printf("%c", str[k]);
        }
        printf("\n");
    }
    return 0;
}