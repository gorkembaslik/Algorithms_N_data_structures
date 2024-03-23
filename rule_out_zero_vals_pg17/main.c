#include <stdio.h>
#define DIM 10

int main() {
    int i, j, arr[DIM], cnt=0;
    for(i=0;i<DIM;i++){
        scanf("%d ", &arr[i]);
    }
    for (i=0;i<DIM;i++){
        j = i;
        if (arr[i] == 0){
            cnt++;
            while(i<DIM-1){
                arr[i] = arr[i+1];
                i++;
            }
            if (j!=0)
                i = j-1;
            else
                i=j;
        }
    }
    for(i=0;i<DIM-cnt;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}