# The maximum-subarray problem.

Given an one dimensional array of integers find the contigious sub array within the array such that sum of the sub array is maximum.

### Brute force approach.

Pick any two elements and find the sum of the contigous subarray between which can be done in $^nC_2$ ways.  
so therefore running time of this approach is $\Theta (n^2)$.  

### Divide and Conquer.

Given an array $A[low...high]$ is divided into two sub arrays $A[low...mid]$ and $A[mid+1...high]$.  
The maximum subarray must exactly lie in one of these cases.

1. $A[low...mid]$ or,
2. $A[mid+1...high]$ or,
3. a subarray $A[i..j]$ crossing the midpoint, that is $low < i < mid < j < high$.

Both (1.) and (2.) are subproblems of the maximum sub array problem. only restriction is the subarray crossing the midpoint.  
In case of the subarray crossing the midpoint, $A[i..j]$ can be split into $A[i..mid]$ and $A[mid+1..j]$, which can easily computed by finding the maximum from mid to i and mid+1 to j.

**Find-max-crossing-subarray**

1. Initialize sum to zero.
2. Initialize left-sum and right-sum to INT_MIN.
3. Iterate from mid to low and find the point where max sum is attained.
4. Iterate from mid+1 to high and find the point where max sum is attained.
5. Points obtained from above are the two endpoints of the max-subarray-crossing the midpoint.

Find-max-crossing-subarray has running time of $\Theta (n)$.  
Each recursive call of the maximum subarray takes running time of $\Theta (1)$.  
Cummulatively all recursive calls has running time of $\Theta (\lg n)$.  
Total running of the maximum subarray problem using divide and conquer is $\Theta (n \lg n)$. 

