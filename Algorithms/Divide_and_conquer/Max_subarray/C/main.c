#include <stdio.h>
#include <stdlib.h>

#include "max_subarray.h"

int main(int argc, char* argv) {
    int N;
    int low, high, max;
    //scanf("%d",&N);
    N = 10;
    int A[] = {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1};
    
    print_array(A,0,N-1);
    max_subarray(A, &low, &high, &max,0,N-1);
    printf("Maximum of %d from %d to %d .\n", max, low, high);

    N = 1;
    int B[] = {9};
    print_array(B,0,N-1);
    max_subarray(B, &low, &high, &max,0,N-1);
    printf("Maximum of %d from %d to %d .\n", max, low, high);

    N = 9;
    int C[] = {1,2,3,4,5,6,7,8,9};
    print_array( C,0,N-1);
    max_subarray(C, &low, &high, &max,0,N-1);
    printf("Maximum of %d from %d to %d .\n", max, low, high);
    
    N = 16;
    int D[] = {13, -3, -25, 20 , -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    print_array(D,0,N-1);
    max_subarray(D, &low, &high, &max,0,N-1);
    printf("Maximum of %d from %d to %d .\n", max, low, high);

}