#include <stdio.h>
#include <stdlib.h>

int* ins_sort(int *arr, int N) {
    for(int i=1;i< N;i++) {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return arr;
}

void print_array(int* arr, int N) {
    int i=0;
    while(N--){
        printf("%d ", arr[i++]);
    }
    printf("\n");
}

int* input_array(int N) {

    int* arr = malloc(sizeof(int)*N);
    for(int i=0;i< N;i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

int main(int argc, char* argv) {
    int N;
    scanf("%d",&N);
    int *A = input_array(N);
    print_array(A,N);
    print_array(ins_sort(A,N), N);

}