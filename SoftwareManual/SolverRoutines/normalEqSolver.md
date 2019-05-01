# Software Manual

**Routine Name:** normalEqSolver

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** The purpose of this function is to calculate a solution to the normal equations. The normal equations find the unique vector **x** that minimizes the L2 norm of **b** - *A***x**. This type of equation often shows up in data fitting.

**Input:** This function receives a *m* x *n* coefficient matrix, A, in the form of an [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object and a vector of constant terms, **b**, in the form of a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object as input. The coefficient matrix should have more rows than columns. The function will throw an exception if the coefficient matrix has more columns than rows.

**Output:** This function returns a vector, **x**, in the form of an [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object. This **x** minimizes the equation **b** - A**x**.

**Usage/Example:** Usage of this function is straightforward. Consider the problem of minimizing the L2 norm of **b** - *A***x** where *A* = [[1,0,1],[2,3,5],[5,3,-2],[3,5,4],[-1,6,3]] and **b** = [4,-2,5,-2,1]. The following code shows how this function can be used to accomplish this.
```cpp
int m = 5;
int n = 3;

//Create and populate a 5 x 3 matrix.
array2D A;
A.allocateMem(m, n);
A(0, 0) = 1; A(0, 1) = 0; A(0, 2) = 1;
A(1, 0) = 2; A(1, 1) = 3; A(1, 2) = 5;
A(2, 0) = 5; A(2, 1) = 3; A(2, 2) = -2;
A(3, 0) = 3; A(3, 1) = 5; A(3, 2) = 4;
A(4, 0) = -1; A(4, 1) = 6; A(4, 2) = 3;

//Create and populate a vector of constant terms.
array1D b;
b.allocateMem(m);
b(0) = 4; b(1) = -2; b(2) = 5; b(3) = -2; b(4) = 1;

//Find the x vector that minimizes the L2 norm of b - Ax.
array1D x;
x = normalEqSolver(A, b);

for (int i = 0; i < n; i++) {
	std::cout << x(i) << " ";
}
```
This code outputs the following to console:
```
0.347226 0.399004 -0.785917
```
which is the unique **x** vector that minimizes the L2 norm of **b** - *A***x**


**Implementation/Code:** The normalEqSolver() function is implemented as follows:

```cpp
array1D normalEqSolver(array2D& A, array1D b) {

	int m = A.getRows();
	int n = A.getCols();

	if (n > m) {
		throw "NormalEqSolver: More Columns Than Rows";
	}

	//Allocate memory for necessary matrices.
	array2D B;
	B.allocateMem(n, n);

	//Allocate memory for necessary vectors.
	array1D x;
	x.allocateMem(n);

	double sum = 0.0;

	//Form the matrix B = (A^T) * A
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum = 0.0;
			for (int k = 0; k < m; k++) {
				sum = sum + A(k,i) * A(k, j);
			}
			B(i, j) = sum;
		}
	}

	//Form the vector x = (A^T) * b
	for (int i = 0; i < n; i++) {
		sum = 0.0;
		for (int j = 0; j < m; j++) {
			sum = sum + A(j, i)*b(j);
		}
		x(i) = sum;
	}

	//Compute the Cholesky factorization of B.
	//The lower triangular portion of B will become G.
	//The upper triangular portion of B will be unchanged.
	B = CholeskyDecomposition(B);

	//Solve the equation Gx' = x for x'
	x = forwardSub(B, x);

	//Reflect the lower triangular portion of B across the diagonal.
	//This makes the upper triangular portion of B into G^T.
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			B(i, j) = B(j, i);
		}
	}

	//Solve the equation (G^T)x'' = x' for x''
	x = backSub(B, x);

	return x;
}
```

**Last Modified:** April/2019