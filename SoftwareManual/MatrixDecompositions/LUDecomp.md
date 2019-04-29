# Software Manual

**Routine Name:** LUDecomp

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** The purpose of this function is to compute the LU Decomposition of a square matrix.

**Input:** This function accepts a square matrix, in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object, as input.

**Output:** This function returns a matrix of the same size as the input. The lower triangular part of this matrix is the *L* part of the factorization, and the upper triangular part of the returned matrix is the *U* part of the factorization.

**Usage/Example:** Usage of this function is relatively straightforward, but caution should be employed when parsing the ouput of this function. The following code
```cpp
int m, n;
m = 3; n = 3;

array2D mat, decompMat;

mat = emptyMat(m, n);

mat(0, 0) = 1; mat(0, 1) = -1; mat(0, 2) = 3;
mat(1, 0) = 1; mat(1, 1) = 1; mat(1, 2) = 0;
mat(2, 0) = 3; mat(2, 1) = -2; mat(2, 2) = 1;
	
decompMat = LUDecomp(mat);
	
for (int i = 0; i < m; i++) {
	for (int j = 0; j < n; j++) {
		std::cout << decompMat(i, j) << " ";
	}
	std::cout << std::endl;
}
```
outputs the following to console:
```
1  -1    3
1   2   -3
3 0.5 -6.5
```
Be careful to note that this means
```
    1   0 0
L = 1   1 0
    3 0.5 1
```
and
```
    1 -1    3
U = 0  2   -3
    0  0 -6.5
```
so that *A* = *LU*.

**Implementation/Code:**

```cpp
array2D LUDecomp(array2D A) {

	int m = A.getRows();
	int n = A.getCols();

	if (m != n) {
		throw "LUDecomp: Matrix not square";
	}

	double factor = 0.0;

	for (int k = 0; k < m - 1; k++) {
		for (int i = k + 1; i < m; i++) {

			if (A(k, k) == 0.0) throw "LUDecomp: Division by zero";

			factor = A(i, k) / A(k, k);

			for (int j = k + 1; j < n; j++) {
				A(i, j) = A(i, j) - factor * A(k, j);
			}

			A(i, k) = factor;
		}
	}

	return A;
}
```

**Last Modified:** April/2019