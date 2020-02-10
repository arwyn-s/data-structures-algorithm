# Sieve of Eratoshenes

Ancient algorithm for finding all primes numbers up to a limit.

## Pre-requisites

Prime no. is a natural numbers that has exactly 2 divisors 1 and itself.

## Algorithm

1. Create a list consecutive integers starting from smallest prime(2) to n.
2. Let p equals 2 (smallest prime no).
3. Starting from $p^2$, count up in increments of p and mark each of the numbers greater than or equal to p in the list ($p(p+1)p(p+2)(p+3)...$).
4. Find the first greater number than p in the list that is not marked. If there is no such no number then stop. Other wise let p equal to this no.
   
## Analysis

Memory complexity: $O(N)$
Computational complexity: $O(n \log\log n)$