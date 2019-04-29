# Software Manual

**Routine Name:** CholeskyDecomp

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function returns the Cholesky Decomposition of a square matrix.

**Input:**

**Output:**

**Usage/Example:**

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