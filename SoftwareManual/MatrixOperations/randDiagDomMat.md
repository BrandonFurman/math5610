# Software Manual

**Routine Name:** randDiagDomMat

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This routine returns a square matrix, in the form of an [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object, that is diagonally dominant, and whose non-diagonal entries have been randomized to between 0 and 1. 

**Input:** This routine accepts a single integer, *m*, that defines the number of rows and columns in the matrix.

**Output:** This routine outputs a diagonally dominant matrix with *m* rows and *m* columns whose non-diagonal entries have been randomized to between 0 and 1.

**Usage/Example:** Usage is straightforward. The following code

```cpp
array2D mat;

mat = randDiagDomMat(4);

for (int i = 0; i < 4; i++) {
	for (int j = 0; j < 4; j++) {
		std::cout << mat(i, j) << " ";
	}
	std::cout << std::endl;
}
```
outputs the following to console:
```cpp
0.758141 0.00125126 0.563585 0.193304
0.808741 1.87362    0.585009 0.479873
0.350291 0.895962   2.06909  0.82284
0.746605 0.174108   0.858943 1.77966
```

**Implementation/Code:** The following is the code for randDiagDomMat(int m, int n):

```cpp
array2D randDiagDomMat(int m) {

	array2D mat;
	double sum = 0.0;

	mat.allocateMem(m, m);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (j != i) {
				mat(i, j) = (double)rand() / (double)RAND_MAX;
				sum += mat(i, j);
			}
		}
		mat(i, i) = sum;
		sum = 0.0;
	}

	return mat;
}
```

**Last Modified:** March/2019