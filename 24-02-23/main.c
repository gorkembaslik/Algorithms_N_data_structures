#include <stdio.h>

void searchSubArray(float *v, int n, int k){
    float sum, maxs=0, maxdif=0, min, max;
    int maxsi, maxdifi, i, j;
    for (i=0;i<n-2;i++){
        sum=0; min=99; max=0;
        for (j=0;j<k;j++){
            sum += v[i+j];
            if (v[i+j]<min)
                min=v[i+j];
            if (v[i+j]>max)
                max=v[i+j];
        }
        if ((max-min)>maxdif){
            maxdif= max-min;
            maxdifi = i;
        }
        if (sum > maxs){
            maxs = sum;
            maxsi = i;
        }
    }
    printf("max sum: ");
    for (i=maxsi;i<maxsi+k;i++){
        printf("%.1f ", v[i]);
    }
    printf("\nmax dif: ");
    for (i=maxdifi;i<maxdifi+k;i++){
        printf("%.1f ", v[i]);
    }
}

int main() {
    float v[] = {12.5, 2.1, 3.3, 4.1, 5.4, 6.2, 7.9, 8.3, -9.9, 5.1};

    searchSubArray(v, 10, 3);
    return 0;
}
