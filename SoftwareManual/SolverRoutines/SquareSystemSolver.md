# Software Manual

**Routine Name:** SquareSystemSolver

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function solves the square linear system of equations *A***x** = **b** using Gaussian Elimination. This is an inlined version of the [slowSquareSystemSolver](https://brandonfurman.github.io/math5610/SoftwareManual/SolverRoutines/slowSquareSystemSolver). A speed comparison of these two functions can be found [here](https://brandonfurman.github.io/math5610/homework/homework5/SquareSystemSolverComparison).

**Input:** This function requires a coefficient matrix, *A*, in the form of an [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object and a vector of constant terms, **b**, in the form of a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object. The coefficient matrix should have a nonzero entries for all of its diagonal elements. If there are zero entries, an exception will be thrown.

**Output:** The function returns a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object that is the solution to the linear system of equations.

**Usage/Example:** An example of the usage of this function can be found below for the problem where *A* = [[1,2,3],[5,6,7],[11,9,11]] and **b** = [6,1,9].
```cpp
int m, n, l;
m = 3; n = 3; l = 3;

//Create and populate the coefficient matrix.
array2D A;
A.allocateMem(m, n);
A(0, 0) = 1; A(0, 1) = 2; A(0, 2) = 3;
A(1, 0) = 5; A(1, 1) = 6; A(1, 2) = 7;
A(2, 0) = 11; A(2, 1) = 9; A(2, 2) = 11;

//Create and populate the vector of constant terms.
array1D b;
b.allocateMem(n);
b(0) = 6; b(1) = 1; b(2) = 9;

//Use Gauss Elimination to solver the linear system.
array1D x;
x = SquareSystemSolver(A,b);

//Print the results.
for (int i = 0; i < l; i++) {
	std::cout << x(i) << " ";
}
```
This code outputs the following to the console:
```
0.8125 -11.375 9.3125
```
which is the exact solution of the stated problem.

**Implementation/Code:** The SquareSystemSolver() function is implemented as follows:
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

			if (augMat(k, k) == 0.0) throw "SquareSystemSolver: Division by zero";

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