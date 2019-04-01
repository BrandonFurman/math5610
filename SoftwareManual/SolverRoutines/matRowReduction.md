# Software Manual

**Routine Name:** matRowReduction

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function performs elementary row operations on a given matrix to take the matrix to row echelon form. The resulting matrix is upper triangular through the rows. 

**Input:** This functions accepts a matrix of arbitrary dimension in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object. The matrix does not need to be square. This input is passed by reference.

**Output:** This functions returns a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object that is the row echelon form of the input matrix. This matrix will always have the same dimensions as the input.

**Usage/Example:**

**Implementation/Code:**

```cpp
array2D matRowReduction(array2D& A) {

	int m = A.getRows();
	int n = A.getCols();

	if (m >= n) {
		throw "rowReducer: More rows than columns";
	}

	array2D newA;

	newA = A;

	double factor = 0.0;

	for (int k = 0; k < m-1; k++) {
		for (int i = k + 1; i < m; i++) {

			if (newA(k, k) == 0.0) throw "rowReducer: Division by zero";

			factor = newA(i, k) / newA(k, k);

			for (int j = 0; j < n; j++) {
				newA(i, j) = newA(i, j) - factor * newA(k, j);
			}
		}
	}

	return newA;
}
```

**Last Modified:** March/2019