#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
typedef struct student {
    char *last_name, *first_name;
    int registration_number;
    float average;
} stud;

int main() {
    int n=3, rn, a;
    char ln[N], fn[N];
    stud *v;
    v = (stud *) malloc(n * sizeof(stud));
    if (v == NULL) {exit(EXIT_FAILURE);}

    for (int i=0;i<n;i++){
        scanf("%s%s%i%d", ln,fn,&rn, &a);
        v[i].last_name = malloc((strlen(ln)+1)* sizeof(char));
        if (v[i].last_name==NULL){exit(EXIT_FAILURE);}
        v[i].first_name = malloc((strlen(fn)+1)* sizeof(char));
        if (v[i].first_name==NULL){exit(EXIT_FAILURE);}
        strcpy(v[i].last_name, ln);
        strcpy(v[i].first_name, fn);
        v[i]. registration_number = rn;
        v[i].average = (float) a;
    }
    for (int i=0; i<n;i++){
        printf("N: %s\nCN:%s\nNO:%d\nAverage:%.2f\n",v[i].first_name, v[i].last_name, v[i].registration_number, v[i].average);
    }
    for (int i=0;i<n;i++){
        free(v[i].first_name);
        free(v[i].last_name);
    }

}
