# Software Manual

**Routine Name:** scaleMat

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function returns a scalar multiple of a given matrix.

**Input:** This function accepts a double-precision number and a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object as inputs.

**Output:** This function returns a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object with each entry multiplied by the double-precision input.

**Usage/Example:**

**Implementation/Code:** This function is implemented as follows:
```cpp
array2D scaleMat(double c, array2D& mat) {

	int m = mat.getRows();
	int n = mat.getCols();

	array2D newMat;

	newMat.allocateMem(m, n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			newMat(i, j) = c * mat(i, j);
		}
	}
	return newMat;
}
```

**Last Modified:** March/2019