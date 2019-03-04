# Software Manual

**Routine Name:** addMat

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:** 
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