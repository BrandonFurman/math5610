# Software Manual

**Routine Name:** vecOuterProduct

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:**

```cpp
array2D vecOuterProduct(array1D& vec1, array1D& vec2) {

	int m = vec1.getLength();
	int n = vec2.getLength();

	array2D mat;

	mat.allocateMem(m, n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			mat(i, j) = vec1(i)*vec2(j);
		}
	}

	return mat;
}
```

**Last Modified:** March/2019