# Software Manual

**Routine Name:** diagSolver

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function computes the solution to a square linear system of equations where the coefficient matrix is a diagonal matrix.

**Input:** This function accepts a coefficient matrix, in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object and a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object as inputs.

**Output:** This function returns a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object that is the solution to the linear system of equations.

**Usage/Example:** Usage of this function is relatively straightforward. Be cautious of the fact that this function does not check if the input matrix is actually diagonal.
```cpp
int m, n, l;
m = 4; n = 4; l = 4;

array1D vec, solVec;
array2D mat;

vec = emptyVec(l);
vec(0) = 1; vec(1) = 2; vec(2) = 3; vec(3) = 4;

mat = emptyMat(m,n);
mat(0, 0) = 4; mat(1, 1) = 5; mat(2, 2) = 6; mat(3, 3) = 8;

solVec = diagSolver(mat, vec);

for (int i = 0; i < l; i++) {
	std::cout << solVec(i) << " ";
}
```
outputs the following to the console
```
0.25 0.4 0.5 0.5
```
Note that additional entries in the coefficient matrix will have the exact same output.

**Implementation/Code:** This function is implemented as follows:

```cpp
array1D diagSolver(array2D& A, array1D& b) {

	int m = A.getRows();
	int n = A.getCols();
	int l = b.getLength();

	if (m != n || m != l) {
		throw "diagSolver: Incompatible Sizes";
	}

	array1D x;

	x.allocateMem(l);

	for (int i = 0; i < l; i++) {
		x(i) = b(i) / A(i, i);
	}

	return x;
}
```

**Last Modified:** March/2019