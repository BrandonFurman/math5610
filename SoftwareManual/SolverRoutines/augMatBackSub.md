# Software Manual

**Routine Name:** augMatBackSub

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:**

```cpp
array1D augMatBackSub(array2D& A) {

	int m = A.getRows();
	int n = A.getCols();

	if (n != m+1) {
		throw "backSub: Incompatible Sizes";
	}

	for (int i = 0; i < m; i++) {
		if (A(i, i) == 0.0) throw "backSub: Division by zero";
	}

	array1D x;

	x.allocateMem(m);

	for (int i = m - 1; i >= 0; i--) {

		x(i) = A(i, n-1);

		for (int j = i + 1; j < m; j++) {

			x(i) = x(i) - A(i, j)*x(j);

		}

		x(i) = x(i) / A(i, i);
	}

	return x;
}
```

**Last Modified:** March/2019