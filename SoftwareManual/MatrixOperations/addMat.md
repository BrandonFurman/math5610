# Software Manual

**Routine Name:** addMat

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function returns the sum of two matrices of the same size.

**Input:** This functions accepts two [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) objects of equal size as inputs.

**Output:** This function returns a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object that is the sum of the inputs.

**Usage/Example:**

**Implementation/Code:** This function is implemented as follows:

```cpp
array2D addMat(array2D& mat1, array2D& mat2) {

	int m1 = mat1.getRows();
	int n1 = mat1.getCols();
	int m2 = mat2.getRows();
	int n2 = mat2.getCols();

	if (m1 != m2 || n1 != n2) {
		throw "addMat: Incompatible Matrix Sizes";
	}

	array2D mat;

	mat.allocateMem(m1, n1);

	double sum = 0.0;

	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n1; j++) {
			mat(i, j) = mat1(i, j) + mat2(i, j);
		}
	}

	return mat;
}
```

**Last Modified:** March/2019