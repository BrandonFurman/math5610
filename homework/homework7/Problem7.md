## Stationary Iterative Methods

1. **Jacobi Method**
	- "The Jacobi method is a method of solving a matrix equation on a matrix that has no zeros along its main diagonal. Each diagonal element is solved for, and an approximate value plugged in. The process is then iterated until it converges." [Source](http://mathworld.wolfram.com/JacobiMethod.html)
2. **Damped Jacobi Method**
	- 
3. **Gauss-Seidel Method**
	- "The Gauss-Seidel method is a technique for solving the *n* equations of the linear system of equations *A***x** = **b** one at a time in sequence, and uses previously computed results as soon as they are available." [Source](http://mathworld.wolfram.com/Gauss-SeidelMethod.html)
4. **Success Over-Relaxation Method**
	- "The successive overrelaxation method (SOR) is a method of solving a linear system of equations *A***x** = **b** derived by extrapolating the Gauss-Seidel method. This extrapolation takes the form of a weighted average between the previous iterate and the computed Gauss-Seidel iterate successively for each component." [Source](http://mathworld.wolfram.com/SuccessiveOverrelaxationMethod.html)

## Nonstationary Iterative Methods

1. **Steepest Descent**
	- "An algorithm for finding the nearest local minimum of a function which presupposes that the gradient of the function can be computed. The method of steepest descent, also called the gradient descent method, starts at a point P_0 and, as many times as needed, moves from P_i to P_(i+1) by minimizing along the line extending from P_i in the direction the local downhill gradient." [Source](http://mathworld.wolfram.com/MethodofSteepestDescent.html)
2. **Conjugate Gradient**
	- "The conjugate gradient method is an algorithm for finding the nearest local minimum of a function of *n* variables which presupposes that the gradient of the function can be computed. It uses conjugate directions instead of the local gradient for going downhill. If the vicinity of the minimum has the shape of a long, narrow valley, the minimum is reached in far fewer steps than would be the case using the method of steepest descent." [Source](http://mathworld.wolfram.com/ConjugateGradientMethod.html)
3. **Generalized Minimal Residual Method**
	- 
4. **Biconjugate Gradient Method**