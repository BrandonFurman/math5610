## Direct Methods Limitations

Below is a summary of some of the limitations of direct methods for solving linear systems of equations. Direct methods include Gauss Elimination with back substitution and factorization.

- Limitations of Gauss Elimination and Back Substitution:
	- Algorithm fails if there are any zeros on the diagonals, unless partial pivoting is employed.
	- Complexity grows with order n^3.
	- Space complexity can become an issue.
	- Error grows linearly with the size of the problem.

- Limitations of LU Decomposition:
	- Could easily be unstable.
	- Does not find approximate solutions.

- Limitations of LU Decomposition with partial pivoting:
	- Reduces instability, but in many cases still far from optimal stability

- Disadvantages of QR compared to LU:
	- More complicated to find QR decomposition
	- Slower than LU

[Source 1](https://www-old.math.gatech.edu/academic/courses/core/math2601/Web-notes/6num.pdf) , [Source 2](https://people.eecs.berkeley.edu/~newton/Classes/EE219fa98/ee219a2_2/ee219a2_2.pdf)