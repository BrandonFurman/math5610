The purpose of this page is to document three different preconditioning strategies for solving linear systems of equations. A preconditioner of a matrix *A* is a matrix *P* such that (*P*^-1)*A* has a smaller condition number than *A* alone. Multiplying the original system of equations by *P*^-1, (*P*^-1)*A***x**=(*P*^-1)**b**, means that the system is more suitable for iterative methods. Three preconditioners are listed below.

1. **Jacobi Preconditioner**
	- The Jacobi Preconditioner is the simplest preconditioner. It is chosen to be the diagonal of *A*, *P* = diag(*A*). This preconditioner has very small storage requirements and is easy to implement. However, it does not yield particularly large improvements when compared to more sophisticated preconditioners. [Source](http://www.netlib.org/linalg/html_templates/node55.html#SECTION00820000000000000000)
2. **Conjugate Gradient Preconditioning**
