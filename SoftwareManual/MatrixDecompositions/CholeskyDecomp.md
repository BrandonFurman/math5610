# Software Manual

**Routine Name:** CholeskyDecomp

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** The purpose of this function is to generate the Cholesky decomposition for a given square symmetric, positive definite matrix. The Cholesky decomposition turns the given matrix into a product of a lower triangular matrix and its conjugate transpose.

**Input:** This function receives a square symmetric, positive definite matrix in the form of an [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object. The input is not checked for correctness. Hence, the function may fail if the matrix passed is not symmetric positive definite.

**Output:** The function returns an [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object of the same size of the input. The lower triangular portion of this matrix is the desired Cholesky Decomposition. The upper half of the matrix remains unchanged and should be ignored.

**Usage/Example:** The function can be used as in the following example:
```cpp
int m = 3;
array2D mat;

mat = randSymPosDefMat(m);

for (int i = 0; i < m; i++) {
	for (int j = 0; j < m; j++) {
		std::cout << mat(i, j) << " ";
	}
	std::cout << std::endl;
}

std::cout << std::endl;

mat = CholeskyDecomp(mat);

for (int i = 0; i < m; i++) {
	for (int j = 0; j < m; j++) {
		std::cout << mat(i, j) << " ";
	}
	std::cout << std::endl;
}
```
This code has the following output:
```
3.355 0.423476 0.664448
0.423476 4.22658 1.2023
0.664448 1.2023 4.60252

1.83166 0.423476 0.664448
0.231197 2.04282 1.2023
0.362756 0.547493 2.04235
```
and the Cholesky Decomposition is the lower triangular portion of the second matrix. That is,
```
    1.83166  0        0
G = 0.231197 2.04282  0
    0.362756 0.547493 2.04235
```


**Implementation/Code:**

```cpp
array2D CholeskyDecomp(array2D A) {

	int m = A.getRows();
	int n = A.getCols();

	if (m != n) {
		throw "CholeskyDecomp: Matrix Not Square";
	}

	double tmp = 0.0;

	for (int k = 0; k < n - 1; k++) {

		tmp = sqrt(A(k, k));

		A(k, k) = tmp;

		for (int i = k + 1; i < n; i++) {

			A(i, k) = A(i, k) / tmp;

		}

		for (int j = k + 1; j < n; j++) {
			for (int i = j; i < n; i++) {

				A(i, j) = A(i, j) - A(i,k) * A(j, k);

			}
		}
	}

	A(n - 1, n - 1) = sqrt(A(n - 1, n - 1));

	return A;
}
```

**Last Modified:** April/2019