#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

int main(int argc, char* argv) {
    int N;
    //scanf("%d",&N);
    N = 10;
    int A[] = {19, 49, 30, 5, 69, 100, 2, 8, 37, 87};
    print_array(A,N);
    print_array(ins_sort(A,N), N);

    N = 0;
    int B[] = {};
    print_array(B,N);
    print_array(ins_sort(B,N), N);

    N = 9;
    int C[] = {1,2,3,4,5,6,7,8,9};
    print_array(C,N);
    print_array(ins_sort(C,N), N);
    
    N = 20;
    int D[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    print_array(D,N);
    print_array(ins_sort(D,N), N);
}