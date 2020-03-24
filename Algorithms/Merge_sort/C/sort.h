/********
 *  
 *  MERGE SORT. 
 *  given a sequence of N numbers, insertion sort will sort the numbers with worst case running time of order O(n^2).
 * 
 * *******/

void merge_sort(int *arr, int p, int r);
void merge(int *arr, int p, int q, int r);
void print_array(int* arr,int p,  int N);
int* input_array(int N);