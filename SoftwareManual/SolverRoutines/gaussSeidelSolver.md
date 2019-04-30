# Software Manual

**Routine Name:** gaussSeidelSolver

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function solves the square linear system of equations A**x** = **b** using the Gauss-Seidel algorithm.

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:**

```cpp
array1D gaussSeidelSolver(array2D& A, array1D& b, array1D x0, double tol, int maxIter) {

	int m = A.getRows();
	int n = A.getCols();
	int p = b.getLength();

	if (m != n || m != p) {
		throw "gaussSeidelSolver: Incompatible Matrix Sizes";
	}

	array1D x1;
	x1.allocateMem(p);
	x1 = x0;

	int cntr = 0;
	double error = 10.0*tol;
	double sum = 0.0;

	while (error > tol && cntr < maxIter) {

		cntr += 1;
		cntr2 = cntr2 + 1;

		for (int i = 0; i < m; i++) {
			sum = 0.0;
			for (int j = 0; j < n; j++) {
				if (i != j) {
					sum = sum + A(i, j)*x1(j);
				}
			}
			x1(i) = (1.0 / A(i, i))*(b(i) - sum);
		}

		error = absErrVecTwoNorm(x1, x0);

		x0 = x1;
	}

	return x1;
}
```

**Last Modified:** April/2019