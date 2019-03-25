# Software Manual

**Routine Name:** scaleMat

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function returns a scalar multiple of a given matrix.

**Input:** This function accepts a double-precision number and a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object as inputs.

**Output:** This function returns a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object with each entry multiplied by the double-precision input.

**Usage/Example:** Usage of this function is straightforward. The following code
```cpp
int m = 2;
int n = 2;
double c = 2.4;

array2D mat1,mat2;

mat1 = emptyMat(m, n);

mat1(0, 0) = 1; mat1(0, 1) = 2;
mat1(1, 0) = 3; mat1(1, 1) = 4;

mat2 = scaleMat(c,mat1);

for (int i = 0; i < m; i++) {
	for (int j = 0; j < m; j++) {
		std::cout << mat2(i, j) << " ";
	}
	std::cout << std::endl;
}
```
outputs the following to console
```
2.4 4.8
7.2 9.6
```

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