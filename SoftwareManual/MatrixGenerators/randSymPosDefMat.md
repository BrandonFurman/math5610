# Software Manual

**Routine Name:** randSymPosDefMat

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This routine returns a square matrix, in the form of an [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object, that is symmetric positive definite.

**Input:** This routine accepts a single integer, *m*, that defines the number of rows and columns in the matrix.

**Output:** This routine outputs a symmetric, positive definite matrix with *m* rows and *m* columns. It is calculated by multiplying a random matrix by its transpose and adding *m* to the diagonal entries.

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
array2D randSymPosDefMat(int m) {

	array2D A, B;

	A = randMat(m,m);

	B.allocateMem(m, m);

	double sum = 0.0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				sum = sum + A(i, k) * A(j, k);
			}
			if (i == j) sum = sum + m;

			B(i, j) = sum;

			sum = 0.0;
		}
	}

	return B;
}
```

**Last Modified:** April/2019