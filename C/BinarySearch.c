
#define N 11
#include <stdio.h>

int binary_search(int* arr, int arr_len, int search){
    int start = 0;
    int end = arr_len-1;

    int mid = (end- start)/2;
    while(start <= end) {
        if(search == arr[mid]){
            return mid;
        } else if(arr[mid] > search){
            end= mid-1;

        } else {
            start= mid+1;
        }
        mid = start +(end-start)/2;
    }
    return -1;
}
int main(){
    /* Fixed size array of Length N*/
    /*Hardwired input*/
    int arr[N] = { 2,3,5 ,7 ,10,14,17,20,21,25,31 };
    
    /* Testcases*/
    printf("%d\n",binary_search(arr,N, 2));
    printf("%d\n",binary_search(arr,N,20));
    printf("%d\n",binary_search(arr,N,25));
    printf("%d\n",binary_search(arr,N,4));

}
    
