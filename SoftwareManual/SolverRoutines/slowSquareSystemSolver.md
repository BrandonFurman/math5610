# Software Manual

**Routine Name:** slowSquareSystemSolver

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function solves the square linear system of equations A**x** = **b** using Gaussian Elimination. To do so it utilizes the [matRowReduction](https://brandonfurman.github.io/math5610/SoftwareManual/SolverRoutines/matRowReduction) and [augMatBackSub](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/backSub) functions.

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:**

```cpp
array1D slowSquareSystemSolver(array2D& A, array1D& b) {

	int m = A.getRows();
	int n = A.getCols();
	int l = b.getLength();

	if (m != n || m != l) {
		throw "slowSquareSystemSolver: Incompatible Sizes";
	}

	array1D sol;
	array2D augMat;

	//Allocate memory for the augmented matrix.
	//We need an additional column to account 
	//for the constant terms.
	augMat.allocateMem(m, n + 1);

	//Compose the augmented matrix using the
	//coefficient matrix and constant terms.
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			augMat(i, j) = A(i, j);
		}
		augMat(i, n) = b(i);
	}

	//Perform row reduction on the
	//augmented matrix.
	augMat = matRowReduction(augMat);

	//Perform back substitution on
	//the row reduced matrix to get
	//the final solution.
	sol = augMatBackSub(augMat);

	return sol;
}

```

**Last Modified:** March/2019