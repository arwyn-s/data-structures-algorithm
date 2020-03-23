# Merge Sort.

**Input**: Sequence of N numbers.  
**Output**: A permution of the input sequence such every next number in sequence is either greater than or less than zero.  

## Algorithm.

**Divide**: Divide the sequence of n number to be sorted into two subsequences of n/2 elements each.
**Conquer**: Sort the two subsequences recursively using merge sort.
**Combine**: Merge the two sorted sequences to produce one sorted sequence.

Key operation is combining two sorted arrays

### MERGE(A,p,q,r)

**Assumptions**: A[p...q] & A[q+1...r] are sorted.  
MERGE takes $\theta (n)$

1. Compute sizes of two arrays $n_{1} = q-p+1$ and $n_{2} = r-q$ .
2. Let arrays L and R of sizes $n_{1} +1$ and $n_{2} +1$ .
3. Copy contents of the two sorted arrays into L and R  with last element in each as $\infty$.
4. Have two markers i and j as the indices of the arrays L and R and iterate k from p to r.
5. Compare contents at the markers, the lesser value is assigned at k and the marker is incremented by 1.

### MERGE_SORT(A,p,r)

1. if $p < r$.  
2. $ q = (p+r)/2$
3. MERGE_SORT(A,p,q)
4. MERGE_SORT(A,q+1,r)
5. MERGE(A,p,q,r)

## Analysis.

1. average and worst case : $\theta (n \lg n)$