#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "max_subarray.h"

/****
The maximum subarray must exactly lie in one of these cases.

1. $A[low...mid]$ or,
2. $A[mid+1...high]$ or,
3. a subarray $A[i..j]$ crossing the midpoint, that is $low < i < mid < j < high$.
*****/

void max_subarray(int *arr, int *i, int *j, int *max, int low, int high) {

    if(high > low) {
        int mid= (low + high)/2 ;
        int left_low,left_high,left_max,right_low,right_high,right_max,cross_low,cross_high,cross_max;

        max_subarray(arr,&left_low,&left_high,&left_max,low,mid);
        max_subarray(arr,&right_low,&right_high,&right_max,mid+1,high);
        max_subarray_crossing(arr,&cross_low,&cross_high,&cross_max,low,high);

        if(left_max >= right_max && left_max >= cross_max) {
            *max = left_max;
            *i = left_low;
            *j = left_high;
        } else if(right_max >= left_max && right_max >= cross_max) {
            *max = right_max;
            *i = right_low;
            *j = right_high;
        } else {
            *max = cross_max;
            *i = cross_low;
            *j = cross_high;
        }
    } else if(high == low) {
        *i = low;
        *j = high;
        *max = arr[low];
    }
}

/*******
1. Initialize sum to zero.
2. Initialize left-sum and right-sum to INT_MIN.
3. Iterate from mid to low and find the point where max sum is attained.
4. Iterate from mid+1 to high and find the point where max sum is attained.
5. Points obtained from above are the two endpoints of the max-subarray-crossing the midpoint.
*******/
void max_subarray_crossing(int *arr, int* i, int* j, int* max ,int low , int high) {
    //1.
    int sum =0;
    int mid =(low + high)/2 ;
    //2.
    int left_sum=INT_MIN;
    int right_sum=INT_MIN;
    //3.
    for(int k=mid; k>=low ;k--) {
        sum += arr[k];
        if(sum > left_sum) {
            left_sum = sum;
            *i = k;
        }
    }
    sum = 0;
    //4.
    for(int k=mid+1; k<=high; k++) {
        sum += arr[k];
        if(sum > right_sum) {
            right_sum = sum;
            *j = k;
        }
    }
    *max = right_sum + left_sum;
}

// Function to print array to stdout.
void print_array(int* arr, int p, int r) {
    int i=p;
    while(i<= r){
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