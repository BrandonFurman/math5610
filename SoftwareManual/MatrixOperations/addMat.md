# Software Manual

**Routine Name:** addMat

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function returns the sum of two matrices of the same size.

**Input:** This functions accepts two [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) objects of equal size as inputs.

**Output:** This function returns a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object that is the sum of the inputs.

**Usage/Example:** Usage of this function is straightforward. The following code
```cpp
int m = 2;
int n = 2;

array2D mat1,mat2,mat3;

mat1 = emptyMat(m, n);
mat2 = emptyMat(m, n);

mat1(0, 0) = 1; mat1(0, 1) = 2;
mat1(1, 0) = 3; mat1(1, 1) = 4;

mat2(0, 0) = 5; mat2(0, 1) = 6;
mat2(1, 0) = 7; mat2(1, 1) = 8;

mat3 = addMat(mat1, mat2);

for (int i = 0; i < m; i++) {
	for (int j = 0; j < m; j++) {
		std::cout << mat3(i, j) << " ";
	}
	std::cout << std::endl;
}
```
outputs the following to the console
```
6 8
10 12
```

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