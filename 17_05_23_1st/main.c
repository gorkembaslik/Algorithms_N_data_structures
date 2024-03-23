#include <stdio.h>

void check(int m[][6], int n, int k){
    int i, j,i2,j2, minm= 99, maxm=0;
    int sum, minr, minc, maxr, maxc;

    for(i=0; i<=n-k;i++){
        for(j=0;j<=n-k;j++){
            sum=0;
            for(i2=i;i2<i+k;i2++){
                for(j2=j;j2<j+k;j2++){
                    sum+=m[i2][j2];
                }
            }
            if (sum<minm){
                minr=i; minc=j; minm=sum;
            }
            if (sum>maxm){
                maxr=i; maxc=j; maxm=sum;
            }
        }
    }
    printf("the submatrix of size three with the larger sum is\n");
    for(i=maxr;i<maxr+k;i++){
        for(j=maxc;j<maxc+k;j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("and the one with the smaller sum is\n");
    for(i=minr;i<minr+k;i++){
        for(j=minc;j<minc+k;j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int m[][6] = {{0,1,0,1,0,1,},
    {1, 0, 1, 0, 1, 0 },
    {0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0},
    {3, 0, 1, 0, 2, 0}};
    check(m,6,3);

    return 0;
}
