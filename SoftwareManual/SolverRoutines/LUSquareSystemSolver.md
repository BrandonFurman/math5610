# Software Manual

**Routine Name:** LUSquareSystemSolver

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** The purpose of this function is to solve the square linear system of equations A**x** = **b** using LU factorization.

**Input:** This function accepts an upper triangular coefficient matrix, A, in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object and a vector of constant terms, **b**, in the form of a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object as inputs. Both inputs are passed by reference.

**Output:** This function returns the solution to the system of equations, **x**. The function will throw an exception if any of the diagonal entries of the coefficient matrix are zero.

**Usage/Example:** Usage is straightforward. The following code
```cpp
int m, n, l;
m = 3; n = 3; l = 3;

array1D vec, sol;
array2D mat;

vec = emptyVec(l);
mat = emptyMat(m, n);

vec(0) = 2; vec(1) = 4; vec(2) = 1;

mat(0, 0) = 1; mat(0, 1) = -1; mat(0, 2) = 3;
mat(1, 0) = 1; mat(1, 1) = 1; mat(1, 2) = 0;
mat(2, 0) = 3; mat(2, 1) = -2; mat(2, 2) = 1;

sol = LUSquareSystemSolver(mat,vec);

for (int i = 0; i < l; i++) {
	std::cout << sol(i) << " ";
}
```
outputs the following to the console:
```
1.61538 2.38462 0.923077
```
If any of the diagonal entries in the coefficient matrix above is changed to zero, then this function will be unable to solve the system and an exception will be thrown. This exception can be caught by wrapping the function call in a try-catch block:
```cpp
try {
	sol = LUSquareSystemSolver(mat, vec);
}
catch (const char* msg) {
	std::cerr << msg << std::endl;
}
```
which outputs
```
LUSquareSystemSolver: Incompatible Sizes
```


**Implementation/Code:** The code for the LUSquareSystemSolver() functions is as follows:

```cpp
array1D LUSquareSystemSolver(array2D& A, array1D& b) {

	int m = A.getRows();
	int n = A.getCols();
	int l = b.getLength();

	if (m != n || m != l) {
		throw "LUSquareSystemSolver: Incompatible Sizes";
	}

	array2D LU;
	array1D y, x;

	LU = LUFactorizer(A);

	y.allocateMem(m);

	//Perform Forward Substitution
	for (int i = 0; i < m; i++) {
		y(i) = b(i);
		for (int j = 0; j < i; j++) {
			y(i) = y(i) - LU(i, j)*y(j);
		}
	}

	x = backSub(LU, y);

	return x;
}
```

**Last Modified:** April/2019