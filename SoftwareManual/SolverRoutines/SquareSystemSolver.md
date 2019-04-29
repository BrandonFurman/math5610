# Software Manual

**Routine Name:** SquareSystemSolver

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function solves the square linear system of equations A**x** = **b** using Gaussian Elimination. This is an inlined version of the slowSquareSystemSolver function. A speed comparison of these two functions can be found here.

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:**

```cpp
array1D SquareSystemSolver(array2D& A, array1D& b) {

	int m = A.getRows();
	int n = A.getCols();
	int l = b.getLength();

	if (m != n || m != l) {
		throw "SquareSystemSolver: Incompatible Sizes";
	}
	
	array2D augMat;
	array1D augSol;

	augMat = A;
	augSol = b;

	double factor = 0.0;

	//Perform row reduction
	for (int k = 0; k < m - 1; k++) {
		for (int i = k + 1; i < m; i++) {

			if (augMat(k, k) == 0.0) throw "rowReducer: Division by zero";

			factor = augMat(i, k) / augMat(k, k);

			for (int j = 0; j < n; j++) {
				augMat(i, j) = augMat(i, j) - factor * augMat(k, j);
			}

			augSol(i) = augSol(i) - factor * augSol(k);

		}
	}
	//Perform back substitution
	for (int i = m - 1; i >= 0; i--) {
		for (int j = i + 1; j < m; j++) {

			augSol(i) = augSol(i) - augMat(i, j)*augSol(j);

		}

		augSol(i) = augSol(i) / augMat(i, i);
	}

	return augSol;
}
```

**Last Modified:** April/2019