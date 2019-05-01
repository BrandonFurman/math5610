The purpose of this page is to document three different preconditioning strategies for solving linear systems of equations. A preconditioner of a matrix *A* is a matrix *P* such that (*P*^-1)*A* has a smaller condition number than *A* alone. Multiplying the original system of equations by *P*^-1, (*P*^-1)*A***x**=(*P*^-1)**b**, means that the system is more suitable for iterative methods. Three preconditioners are listed below.

1. **Jacobi Preconditioner**
	- The Jacobi Preconditioner is the simplest preconditioner. It is chosen to be the diagonal of *A*, *P* = diag(*A*). This preconditioner has very small storage requirements and is easy to implement. However, it does not yield particularly large improvements when compared to more sophisticated preconditioners. [Source](http://www.netlib.org/linalg/html_templates/node55.html#SECTION00820000000000000000)
2. **SSOR Preconditioner**
	- The SSOR preconditioner is similar to the Jacobi Preconditioner in that it can be derived from the coefficient matrix without any work. If a matrix is decomposed into *A* = *D* + *L* + *U* where *D*, *L*, and *U* are the diagonal, lower, and upper triangular parts respectively, then the preconditioner is *P* = (*D* + *L*)(*D*^-1)(*D* + *L*)^T. [Source](http://www.netlib.org/linalg/html_templates/node58.html)
3. **Incomplete Cholesky Preconditioner**
	- This preconditioner is created by performing Cholesky decomposition on the coefficient matrix while ignoring the fill elements. The corresponding preconditioner is then *P* = (*G*^T)G. [Source](http://www.cse.psu.edu/~b58/cse456/lecture20.pdf)
