# Software Manual

**Routine Name:** diagSolver

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:**

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