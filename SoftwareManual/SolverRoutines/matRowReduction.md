# Software Manual

**Routine Name:** matRowReduction

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:**

```cpp
array2D matRowReduction(array2D& A) {

	int m = A.getRows();
	int n = A.getCols();

	if (m >= n) {
		throw "rowReducer: More rows than columns";
	}

	array2D newA;

	newA = A;

	double factor = 0.0;

	for (int k = 0; k < m-1; k++) {
		for (int i = k + 1; i < m; i++) {

			if (newA(k, k) == 0.0) throw "rowReducer: Division by zero";

			factor = newA(i, k) / newA(k, k);

			for (int j = 0; j < n; j++) {
				newA(i, j) = newA(i, j) - factor * newA(k, j);
			}
		}
	}

	return newA;
}
```

**Last Modified:** March/2019