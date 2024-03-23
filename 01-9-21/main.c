#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void substring (char *str, int *letter, int *digit){
    int i,maxl=0, maxd=0, count;
    unsigned int len = strlen(str);

    for (i=0;i<len;i++){
        count=0;
        while (str[i] >= 'a' && str[i] <= 'z'){
            count++;
            i++;
        }
        if (count > maxl)
            maxl=count;
        count=0;
        while (str[i] >= '0' && str[i] <= '9'){
            count++;
            i++;
        }
        if (count > maxd)
            maxd=count;
    }
    *letter = maxl;
    *digit = maxd;
}

int main() {
    char str[] = "This is 1 string inclUding diGIts: 12345 678 9";
    int *letter=malloc(sizeof(int));
    int *digit=malloc(sizeof(int));
    substring(str, letter, digit);
    printf("maxL: %d\nmaxD: %d\n", *letter, *digit);
    free(letter);
    free(digit);
    return 0;
}
