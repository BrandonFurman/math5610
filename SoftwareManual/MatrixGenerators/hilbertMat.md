# Software Manual

**Routine Name:** hilbertMat

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This routine returns a square hilbert matrix, in the form of an [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object.

**Input:** This routine accepts a single integer, *m*, that defines the number of rows and columns in the matrix.

**Output:** This routine outputs a Hilbert matrix of order *m*. A hilbert matrix is one in which each element is of the form 1 / (*i* + *j* + *1*) where *i* and *j* are the row and column respectively.

**Usage/Example:** Usage is straightforward. The following code

```cpp
array2D mat;

mat = randSymPosDefMat(4);

for (int i = 0; i < 4; i++) {
	for (int j = 0; j < 4; j++) {
		std::cout << mat(i, j) << " ";
	}
	std::cout << std::endl;
}
```
outputs the following to console:
```cpp

```

**Implementation/Code:** The following is the code for randSymDiagDomMat(int m):

```cpp
array2D hilbertMat(int m) {

	array2D mat;

	mat.allocateMem(m, m);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			mat(i, j) = 1.0 / (i + j + 1);

		}
	}

	return mat;
}
```

**Last Modified:** April/2019