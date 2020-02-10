# Insetion Sort

**Input**: Sequence of N numbers.  
**Output**: A permution of the input sequence such every next number in sequence is either greater than or less than zero.  

## Algorithm.

1. Start by choosing the second element of the array as the key.
2. compare the key with predecessor element of the key.
3. If greater than key swap 
4. Continue step 3 until the key is smaller the comparing element.
5. Repeat from the begining but with next element of the array as the key.
6. Continue untill the key reaches end of the array.

## Analysis.

1. Depends on input, best running time when array is sorted.
2. average and worst case : O(n<sup>2</sup>)