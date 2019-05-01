# Software Manual

**Routine Name:** jacobiSolver

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function solves the square linear system of equations A**x** = **b** using the Jacobi Algorithm. The Jacobi algorithm is an iterative algorithm for finding solutions to systems of equations in which the coefficient matrix is diagonally dominant.

**Input:** This function requires the following 5 items as inputs:

- A diagonally dominant coefficent matrix, *A*, in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object.
- A vector of constant terms, **b**, in the form of a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object. 
- A initial guess for the solution, **x0**, in the form of a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object.
- A tolerance that specifies when to stop iterating in the form of a double precision number.
- A limit to the number of iterations in the form of an integer. 

**Output:** This function returns an [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object that is the solution to the linear system of equations. If the algorithm is unable to converge to a solution within the specified number of iterations, an exception is thrown.

**Usage/Example:** Usage of this function is straightforward. Consider the problem of solving the linear system with *A* = [[7,3,1],[-3,10,2],[1,7,-15]] and **b** = [3,4,2]. The following code will solve the given system:
```cpp
int m = 3;
int maxIter = 100;
double tol = 0.0001;

//Create and populate the coefficient matrix.
array2D A;
A.allocateMem(m, m);
A(0, 0) = 7; A(0, 1) = 3; A(0, 2) = 1;
A(1, 0) = -3; A(1, 1) = 10; A(1, 2) = 2;
A(2, 0) = 1; A(2, 1) = 7; A(2, 2) = -15;

//Create and populate the vector of constant terms.
array1D b;
b.allocateMem(m);
b(0) = 3; b(1) = 4; b(2) = 2;

//Create and populate the initial guess.
array1D x;
x.allocateMem(m);
x(0) = 1.5; x(1) = -1.5; x(2) = 1;

//Use Jacobi Iteration to solve the system Ax = b.
x = jacobiSolver(A, b, x, tol, maxIter);

//Print the results.
for (int i = 0; i < 3; i++) {
	std::cout << x(i) << " ";
}
```
This code outputs the following to the console:
```
0.223222 0.448796 0.0910068
```
which is the correct solution to the linear system. This function can also be used to solve must larger systems of equations. The following code generates a random coefficient 1000 x 1000 matrix and solves it. The answer is then verified to be correct by checking the L2 norm of the residual.
```cpp
int m = 1000;
int maxIter = 10000;
double tol = 0.0001;

//Create and populate a random
//diagonally dominant 1000 x 1000 matrix.
array2D A;
A = randDiagDomMat(m);
for (int i = 0; i < m; i++) A(i, i) += 10;

//Create and populate a random vector
//of length 1000
array1D b;
b = randVec(m);

//Create and populate an initial guess.
array1D x;
x = randVec(m);

//Solve the system of equations Ax = b for x.
x = jacobiSolver(A, b, x, tol, maxIter);

//Calculate the residue: r = b - Ax.
array1D res;
res = multMatVec(A, x);
res = subVec(b, res);
	
//Calculate the L2 norm of the residue.
double error;
error = twoNormVec(res);

//Print the error in the solution.
std::cout << error << std::endl;
```
which outputs the following to the console:
```
0.0499034
```
which shows that the function did indeed find a correct solution. If the function is unable to converge to an answer within the number of iterations specified by maxIter, then an exception will be thrown. This exception can be caught with a try-catch block and results in the following message:
```
jacobiSolver: Failed to converge
```

**Implementation/Code:** The jacobiSolver() function is implemented as follows:

```cpp
array1D jacobiSolver(array2D& A, array1D& b, array1D x0, double tol, int maxIter) {

	int m = A.getRows();
	int n = A.getCols();
	int p = b.getLength();

	if (m != n || m != p) {
		throw "jacobiSolver: Incompatible Matrix Sizes";
	}

	array1D x1;
	x1.allocateMem(p);

	int cntr = 0;
	double error = 10.0*tol;
	double sum = 0.0;

	while (error > tol && cntr < maxIter) {

		cntr += 1;

		for (int i = 0; i < m; i++) {
			sum = 0.0;
			for (int j = 0; j < n; j++) {
				if (i != j) {
					sum = sum + A(i, j)*x0(j);
				}
			}
			x1(i) = (1.0 / A(i,i))*(b(i) - sum);
		}

		error = absErrVecTwoNorm(x1, x0);

		x0 = x1;
	}

	if (cntr != maxIter) {
		return x1;
	}
	else {
		throw "jacobiSolver: Failed to converge";
	}
}
```

**Last Modified:** April/2019