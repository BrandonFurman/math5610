# Software Manual

**Routine Name:** oneNormMat

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This method returns the 1-norm of a given square matrix.

**Input:** This function accepts a square matrix, in the form of [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object, as input. This input is passed by reference.

**Output:** This function returns a double-precision number that represents the 1-norm of the input.

**Usage/Example:**
```cpp
array2D mat;

mat = emptyMat(3,3);
mat(0, 0) = 1; mat(0, 1) = 2; mat(0, 2) = 3;
mat(1, 0) = 4; mat(1, 1) = 5; mat(1, 2) = 6;
mat(2, 0) = 7; mat(2, 1) = 8; mat(2, 2) = 9;

double oneNorm = oneNormMat(mat);

std::cout << oneNorm;
```
outputs the following to console
```
18
```

**Implementation/Code:** 

```cpp
double oneNormMat(array2D& mat) {

	int m = mat.getRows();
	int n = mat.getCols();

	if (m != n) {
		throw "oneNormMat: Matrix is not square";
	}

	double sum = 0.0;
	double max = 0.0;

	for (int j = 0; j < n; j++) {

		for (int i = 0; i < m; i++) {
			sum += abs(mat(i,j));
		}

		if (sum > max) max = sum;
		sum = 0.0;
	}

	return max;
}
```

**Last Modified:** February/2019