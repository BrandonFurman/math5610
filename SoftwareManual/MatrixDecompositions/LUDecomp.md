# Software Manual

**Routine Name:** LUDecomp

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function returns the LU Decomposition of a square matrix.

**Input:**

**Output:**

**Usage/Example:**

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