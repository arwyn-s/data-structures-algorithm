# Growth of functions.

## Asymtotic notations.

### $\Theta$ notation.

$$ \Theta(g(n)) = \{ f(n) : \exist \quad c_1, c_2,n_0 \quad| \quad c_1, c_2, n_0> 0 \quad and\quad 0 < c_1 g(n) < f(n) < c_2 g(n) \quad \forall n >= n_0\} $$  

intutively, $f(n) = \Theta (g(n))$  
$f(n)$ is tightly bounded by $g(n)$.

### $O$ notation.

$$ O(g(n)) = \{ f(n) : \exist \quad c ,n_0 \quad| \quad c, n_0 > 0 \quad and\quad 0 < f(n) < cg(n) \quad \forall n >= n_0\} $$

Usually describes worst running time of an algorithm.  
*worst case running time of insertion sort is $O(n^2)$*

### $\Omega$ notation.


$$ \Omega (g(n)) = \{ f(n) : \exist \quad c,n_0 \quad| \quad c, n_0> 0 \quad and\quad 0 < c g(n) < f(n) \quad \forall n >= n_0\} $$

Equivalently the best case running time of an algorithm.  
*best case running time of insertion sort is $O(n)$*

---
The $o(g(n))$ noatation and $\omega g((n))$ are similar but not tighter asymtotic functions.

## Comparing functions.

If $f(n)$ and $g(n)$ are asymtotically positive then they are

* Transitive
* Reflexive
* Symmetric
* Transpose symmetric.
