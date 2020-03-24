/********
*  
* The maximum-subarray problem.
*
* Given an one dimensional array of integers find the contigious sub array within the array such that sum of the sub array is maximum.
*******/

void max_subarray(int *arr, int *i, int *j, int *max, int low, int high);
void max_subarray_crossing(int *arr, int* i, int* j, int* max ,int low , int high);
void print_array(int* arr,int p,  int N);
int* input_array(int N);