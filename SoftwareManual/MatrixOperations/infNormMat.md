# Software Manual

**Routine Name:** infNormMat

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This method returns the infinity-norm of a given square matrix.

**Input:** This function accepts a square matrix, in the form of [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object, as input. This input is passed by reference.

**Output:** This function returns a double-precision number that represents the infinity-norm of the input.

**Usage/Example:**
```cpp
array2D mat;

mat = emptyMat(3,3);
mat(0, 0) = 1; mat(0, 1) = 2; mat(0, 2) = 3;
mat(1, 0) = 4; mat(1, 1) = 5; mat(1, 2) = 6;
mat(2, 0) = 7; mat(2, 1) = 8; mat(2, 2) = 9;

double infNorm = infNormMat(mat);

std::cout << infNorm;
```
outputs the following to console
```
24
```

**Implementation/Code:** 

```cpp
double infNormMat(array2D& mat) {

	int m = mat.getRows();
	int n = mat.getCols();

	double sum = 0.0;
	double max = 0.0;

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n;  j++) {
			sum += abs(mat(i,j));
		}

		if (sum > max) max = sum;
		sum = 0.0;
	}

	return max;
}
```

**Last Modified:** February/2019