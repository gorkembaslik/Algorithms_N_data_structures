#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 31

int main(int argc, char *argv[]) {
    char s1[MAX_LEN], s2[MAX_LEN];
    int occurences[26] = {}, i;

    if (argc != 3)
        return EXIT_SUCCESS;

    strcpy(s1, argv[1]);
    strcpy(s2, argv[2]);

    if (strlen(s1) != strlen(s2)) {
        printf("Strings doesn't have same length");
        return EXIT_FAILURE;
    }
    for (i=0; i< strlen(s1); i++){
        occurences[tolower(s1[i])-'a']++;
    }
    for (i=0; i< strlen(s2); i++){
        occurences[tolower(s2[i])-'a']--;
    }
    for (i=0; i<26; i++) {
        if (occurences[i] == 1) {
            printf("They are not anagrams!!\n");
            return 0;
        }
    }
    printf("They are anagrams\n");
    return 0;
}