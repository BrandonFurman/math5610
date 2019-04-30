# Software Manual

**Routine Name:** steepestDescent

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function solves the square linear system of equations A**x** = **b** using the Steepest Descent Algorithm. The Steepest Descent Algorithm is an iterative method that can be used when the coefficient matrix is symmetric and positive-definite.

**Input:** This function requires the following 5 items as inputs:

- A symmetric and positive-definite coefficent matrix, *A*, in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object.
- A vector of constant terms, **b**, in the form of a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object. 
- A initial guess for the solution, **x0**, in the form of a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object.
- A tolerance that specifies when to stop iterating in the form of a double precision number.
- A limit to the number of iterations in the form of an integer. 

**Output:** This function returns an [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object that is the solution to the square linear system of equations A**x** = **b**. 

**Usage/Example:** An example of the usage of this function can be found below for the problem where *A* = [[7,3,1],[3,10,2],[1,2,15]] and **b** = [28,31,22].
```cpp
int m = 3;
int maxIter = 1000;
double tol = 0.000001;

//Create the desired coefficient matrix.
array2D A;
A.allocateMem(m, m);
A(0, 0) = 7; A(0, 1) = 3; A(0, 2) = 1;
A(1, 0) = 3; A(1, 1) = 10; A(1, 2) = 2;
A(2, 0) = 1; A(2, 1) = 2; A(2, 2) = 15;

//Create the desired vector of constant terms
array1D b;
b.allocateMem(m);
b(0) = 28; b(1) = 31; b(2) = 22;

//Create an initial guess for the algorithm.
array1D x;
x.allocateMem(m);
x(0) = 0; x(1) = 0; x(2) = 0;

//Call the Conjugate Gradient algorithm.
x = steepestDescent(A, b, x, tol, maxIter);

//Output the solution.
for (int i = 0; i < m; i++) {
	std::cout << x(i) << " ";
}
```
outputs the following to console:
```
3 2 1
```
which is the exact solution to the stated problem.

**Implementation/Code:** The steepestDescent() function is implemented as follows:

```cpp
array1D steepestDescent(array2D& A, array1D& b, array1D x0, double tol, int maxIter) {

	int m = A.getRows();
	int n = A.getCols();
	int p = b.getLength();

	if (m != n || m != p) {
		throw "steepestDescent: Incompatible Matrix Sizes";
	}

	array1D x1, r, q;
	x1.allocateMem(p);
	r.allocateMem(p);
	q.allocateMem(p);

	x1 = x0;

	int cntr = 0;
	double error = 10.0*tol;
	double sum = 0.0;

	double num = 0.0;
	double den = 0.0;
	double step = 0.0;

	//Calculate an initial value for the residual
	for (int i = 0; i < n; i++) {
		sum = 0.0;
		for (int j = 0; j < n; j++) {
			sum = sum + A(i, j) * x0(j);
		}
		r(i) = b(i) - sum;
	}

	while (error > tol && cntr < maxIter) {

		cntr += 1;

		//Calculate q = A*r

		num = 0.0;
		den = 0.0;

		for (int i = 0; i < n; i++) {
			sum = 0.0;
			for (int j = 0; j < n; j++) {
				sum = sum + A(i, j) * r(j);
			}
			q(i) = sum;
			num = num + r(i) * r(i);
			den = den + r(i) * sum;
		}

		step = num / den;

		//Calculate the next steps of x and r.
		for (int i = 0; i < n; i++) {
			x1(i) = x0(i) + step * r(i);
			r(i) = r(i) - step * q(i);
		}

		error = absErrVecTwoNorm(x1, x0);

		x0 = x1;
	}

	return x1;
}
```

**Last Modified:** April/2019