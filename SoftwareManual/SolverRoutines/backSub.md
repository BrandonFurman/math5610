# Software Manual

**Routine Name:** backSub

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:**

```cpp
array1D backSub(array2D& A, array1D& b) {

	int m = A.getRows();
	int n = A.getCols();
	int l = b.getLength();

	if (m != n || m != l) {
		throw "backSub: Incompatible Sizes";
	}

	for (int i = 0; i < m; i++) {
		if (A(i, i) == 0.0) throw "backSub: Division by zero";
	}

	array1D x;

	x.allocateMem(m);

	for (int i = m - 1; i >= 0; i--) {

		x(i) = b(i);

		for (int j = i + 1; j < m; j++) {

			x(i) = x(i) - A(i, j)*x(j);

		}

		x(i) = x(i) / A(i, i);
	}

	return x;
}
```

**Last Modified:** March/2019