#include <stdio.h>

#define N_B 64
#define N_O 22
#define N_H 16

int main() {
    int i, n, tmp, bit, cnt=0;
    int bin[N_B], oct[N_O];
    char hex[N_H+1];
    char c[] = {'A','B','C','D','E','F'}; // FOR HEXADECIMAL NUMBER REPRESENTATION

    fscanf(stdin, "%d", &n);
    if (n<=0)
        return 1;
    tmp = n;
    do{
        bit = tmp % 2;
        bin[cnt++] = bit;
        tmp /= 2;
    } while (tmp > 0);
    printf("BINARY REPRESENTATION: ");
    for (i = cnt-1; i >= 0; i--)
        printf("%d", bin[i]);
    printf("\n");

    tmp = n;
    cnt=0;
    do{
        bit = tmp % 8;
        oct[cnt++] = bit;
        tmp /= 8;
    } while (tmp > 0);
    printf("OCTAL REPRESENTATION: ");
    for (i = cnt-1; i >= 0; i--)
        printf("%d", oct[i]);
    printf("\n");

    tmp = n;
    cnt=0;
    do{
        bit = tmp % 16;
        if (bit>9)
            hex[cnt++] = c[bit-10];
        else
            hex[cnt++] = '0' + bit;
        tmp /= 16;
    } while (tmp > 0);
    printf("HEXADECIMAL REPRESENTATION: ");
    for (i = cnt-1; i >= 0; i--)
        printf("%c", hex[i]);

    return 0;
}
