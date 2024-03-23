#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Exercise 1: Write function char *char_erase(char *str, int *pos);
 * Which receives a string str and an array of integer values pos and it returns
 * the string generated starting from str and erasing all characters in the position
 * indicated by the array pos. The returned string must be allocated. The array pos
 * has unknown size but its last element has value -1.
*/

char *char_erase(char *str, int *pos){
    char c;
    for (int i=0; pos[i] != -1; i++){
        c = str[pos[i]];
        int x,y;
        x = 0;
        while(x<strlen(str)) {
            if (str[x]==c){
                for (y=i; y<strlen(str); y++)
                    str[y]=str[y+1];
            } else x++;
        }
    }
    return str;
}

int main() {
    char *str = "ThisIsAString";
    int pos[] = {7, 4, 2, 0, 11, -1};
    printf("%s", char_erase(str, pos));
    return 0;
}
