# Software Manual

**Routine Name:** vecOuterProduct

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function returns the outer product of two vectors.

**Input:** This function accepts two [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) objects of equal size as inputs.

**Output:** This function returns a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object that is the outer product of the inputs.

**Usage/Example:**

**Implementation/Code:** This function is implemented as follows:

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