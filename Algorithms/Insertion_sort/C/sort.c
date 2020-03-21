#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/****
1. Start by choosing the second element of the array as the key.
2. compare the key with predecessor element of the key.
3. If greater than key swap 
4. Continue step 3 until the key is smaller the comparing element.
5. Repeat from the begining but with next element of the array as the key.
6. Continue untill the key reaches end of the array.
*****/

int* ins_sort(int *arr, int N) {
    for(int i=1;i< N;i++) {
        // 1.
        int key = arr[i];
        int j = i-1;
        // 2.
        while(j>=0 && arr[j] > key){
            // 3.
            arr[j+1] = arr[j];
            j--;
        } // 4.
        arr[j+1] = key; // 5.
    } // 6.
    return arr;
}
// Function to print array to stdout.
void print_array(int* arr, int N) {
    int i=0;
    while(N--){
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