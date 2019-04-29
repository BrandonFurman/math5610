# Software Manual

**Routine Name:** LUSquareSystemSolver

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:**

```cpp
array1D LUSquareSystemSolver(array2D& A, array1D& b) {

	int m = A.getRows();
	int n = A.getCols();
	int l = b.getLength();

	if (m != n || m != l) {
		throw "LUSquareSystemSolver: Incompatible Sizes";
	}

	array2D LU;
	array1D y, x;

	LU = LUFactorizer(A);

	y.allocateMem(m);

	//Perform Forward Substitution
	for (int i = 0; i < m; i++) {
		y(i) = b(i);
		for (int j = 0; j < i; j++) {
			y(i) = y(i) - LU(i, j)*y(j);
		}
	}

	x = backSub(LU, y);

	return x;
}
```

**Last Modified:** April/2019