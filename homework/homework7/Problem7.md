The purpose of this page is to list some of the iterative methods for solving linear systems of equations. Methods can be broadly split into Stationary and Nonstationary methods. Examples of both methods are listed below.

## Stationary Iterative Methods

1. **Jacobi Method**
	- "The Jacobi method is a method of solving a matrix equation on a matrix that has no zeros along its main diagonal. Each diagonal element is solved for, and an approximate value plugged in. The process is then iterated until it converges." [Source](http://mathworld.wolfram.com/JacobiMethod.html)
2. **Weighted Jacobi Method**
	- The Weighted Jacobi Method is the same as the Jacobi Method except with the iterator multiplied by some constant, typically 2/3. [Source](https://en.m.wikipedia.org/wiki/Jacobi_method#Weighted_Jacobi_method)
3. **Gauss-Seidel Method**
	- "The Gauss-Seidel method is a technique for solving the *n* equations of the linear system of equations *A***x** = **b** one at a time in sequence, and uses previously computed results as soon as they are available." [Source](http://mathworld.wolfram.com/Gauss-SeidelMethod.html)
4. **Successive Over-Relaxation Method**
	- "The successive overrelaxation method (SOR) is a method of solving a linear system of equations *A***x** = **b** derived by extrapolating the Gauss-Seidel method. This extrapolation takes the form of a weighted average between the previous iterate and the computed Gauss-Seidel iterate successively for each component." [Source](http://mathworld.wolfram.com/SuccessiveOverrelaxationMethod.html)

## Nonstationary Iterative Methods

1. **Steepest Descent**
	- "An algorithm for finding the nearest local minimum of a function which presupposes that the gradient of the function can be computed. The method of steepest descent, also called the gradient descent method, starts at a point P_0 and, as many times as needed, moves from P_i to P_(i+1) by minimizing along the line extending from P_i in the direction the local downhill gradient." [Source](http://mathworld.wolfram.com/MethodofSteepestDescent.html)
2. **Conjugate Gradient**
	- "The conjugate gradient method is an algorithm for finding the nearest local minimum of a function of *n* variables which presupposes that the gradient of the function can be computed. It uses conjugate directions instead of the local gradient for going downhill. If the vicinity of the minimum has the shape of a long, narrow valley, the minimum is reached in far fewer steps than would be the case using the method of steepest descent." [Source](http://mathworld.wolfram.com/ConjugateGradientMethod.html)
3. **Generalized Minimal Residual Method**
	- "The generalized minimal residual method is designed to solve nonsymmetric linear systems. The most popular form of GMRES is based on a modified Gram-Schmidt orthonormalization procedure and uses restarts to control storage requirements." [Source](http://mathworld.wolfram.com/GeneralizedMinimalResidualMethod.html)
4. **Biconjugate Gradient Method**
	- "The conjugate gradient method is not suitable for nonsymmetric systems because the residual vectors cannot be made orthogonal with short recurrences. The generalized minimal residual method retains orthogonality of the residuals by using long recurrences, at the cost of a larger storage demand. The biconjugate gradient method (BCG) takes another approach, replacing the orthogonal sequence of residuals by two mutually orthogonal sequences, at the price of no longer providing a minimization." [Source](http://mathworld.wolfram.com/BiconjugateGradientMethod.html)