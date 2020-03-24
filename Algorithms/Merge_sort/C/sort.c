#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "sort.h"

/****
1. if $p < r$.  
2. $ q = (p+r)/2$
3. MERGE_SORT(A,p,q)
4. MERGE_SORT(A,q+1,r)
5. MERGE(A,p,q,r)
*****/

void merge_sort(int *arr, int p, int r) {

    if(p < r) {
        int q = (p+r)/2 ;
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

/*******
1. Compute sizes of two arrays $n_{1} = q-p+1$ and $n_{2} = r-q$ .
2. Let arrays L and R of sizes $n_{1} +1$ and $n_{2} +1$ .
3. Copy contents of the two sorted arrays into L and R  with last element in each as $\infty$.
4. Have two markers i and j as the indices of the arrays L and R and iterate k from p to r.
5. Compare contents at the markers, the lesser value is assigned at k and the marker is incremented by 1.
*******/
void merge(int* arr, int p, int q, int r) {
    // 1.
    int n1 = q-p+1 + 1;
    int n2 = r-q + 1;
    // 2.
    int *L = (int*)malloc(sizeof(int)*n1);
    int *R = (int*)malloc(sizeof(int)*n2);

    // 3.
    for(int i=0;i< n1-1;i++){
        L[i] = arr[p+i];
    }
    for(int i=0;i< n2-1;i++){
        R[i] = arr[q+1+i];
    } 
    L[n1-1] = INT_MAX;
    R[n2-1] = INT_MAX;
    
    // 4.
    int i = 0, j=0;
    for(int k=p;k < r+1;k++) {
         
         //5. 
         if(L[i] < R[j]) {
             arr[k] = L[i];
             i+=1;
         }
         else {
             arr[k] = R[j];
             j+=1;
         }
    }
    // printf("%d :",n1);
    // print_array(L, 0,n1);
    // printf("%d :",n2);
    // print_array(R,0, n2);
    // print_array(arr, p, r+1);
    free(L);
    free(R);
}

// Function to print array to stdout.
void print_array(int* arr, int p, int r) {
    int i=p;
    while(i<=r){
        printf("%d ", arr[i++]);
    }
    printf("\n");
}
// Function to get input from stdin.
int* input_array(int N) {

    int* arr = malloc(sizeof(int)*N);
    for(int i=0;i< N;i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}