# Software Manual

**Routine Name:** matRowReduction

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function performs elementary row operations on a given matrix to take the matrix to row echelon form. The resulting matrix is upper triangular through the rows. 

**Input:** This functions accepts a matrix of arbitrary dimension in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object. The matrix does not need to be square. This input is passed by reference.

**Output:** This functions returns a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object that is the row echelon form of the input matrix. This matrix will always have the same dimensions as the input.

**Usage/Example:** Usage of this function is straightforward. Consider the problem of putting the matrix *A* = [[1,2,3,4],[5,6,7,8],[11,9,11,12]] into row echelon form. The following code performs this task:
```cpp
int m, n;
m = 3; n = 4;

//Create and populate coefficient matrix.
array2D mat, newMat;
mat.allocateMem(m,n);
mat(0, 0) = 1; mat(0, 1) = 2; mat(0, 2) = 3; mat(0, 3) = 4;
mat(1, 0) = 5; mat(1, 1) = 6; mat(1, 2) = 7; mat(1, 3) = 8;
mat(2, 0) = 11; mat(2, 1) = 9; mat(2, 2) = 11; mat(2, 3) = 12;

//Perform row reduction.
newMat = matRowReduction(mat);
	
//Print the reults.
for (int i = 0; i < m; i++) {
	for (int j = 0; j < n; j++) {
		std::cout << newMat(i, j) << " ";
	}
	std::cout << std::endl;
}
```
This piece of code outputs the following to the console:
```
1 2 3 4
0 -4 -8 -12
0 0 4 7
```
which is the row echelon form of *A*.

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

			for (int j = k + 1; j < n; j++) {
				newA(i, j) = newA(i, j) - factor * newA(k, j);
			}

			newA(i, k) = 0.0;
		}
	}

	return newA;
}
```

**Last Modified:** March/2019