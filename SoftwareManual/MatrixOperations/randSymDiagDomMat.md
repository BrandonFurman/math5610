# Software Manual

**Routine Name:** randSymDiagDomMat

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This routine returns a square matrix, in the form of an [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object, that is symmetric, diagonally dominant, and whose non-diagonal entries have been randomized to between 0 and 1. 

**Input:** This routine accepts a single integer, *m*, that defines the number of rows and columns in the matrix.

**Output:** This routine outputs a symmetric, diagonally dominant matrix with *m* rows and *m* columns whose non-diagonal entries have been randomized to between 0 and 1.

**Usage/Example:** Usage is straightforward. The following code

```cpp
array2D mat;

mat = randSymDiagDomMat(4);

for (int i = 0; i < 4; i++) {
	for (int j = 0; j < 4; j++) {
		std::cout << mat(i, j) << " ";
	}
	std::cout << std::endl;
}
```
outputs the following to console:
```cpp
1.56563  0.563585 0.193304 0.808741
0.563585 1.39375  0.479873 0.350291
0.193304 0.479873 1.49602  0.82284
0.808741 0.350291 0.82284  1.98187
```

**Implementation/Code:** The following is the code for randSymDiagDomMat(int m):

```cpp
array2D randSymDiagDomMat(int m) {

	array2D mat;

	mat.allocateMem(m, m);

	double tmp = 0.0;

	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			tmp = (double)rand() / (double)RAND_MAX;
			mat(i, j) = tmp;
			mat(j, i) = tmp;
		}
	}

	double sum = 0.0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (j != i) {
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