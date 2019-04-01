# Software Manual

**Routine Name:** backSub

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function computes the solution to the linear system of equations A**x** = **b** where A is a upper triangular coefficient matrix, **b** is a vector of constant terms, and **x** is the solution vector.

**Input:** This function accepts an upper triangular coefficient matrix, A, in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object and a vector of constant terms, **b**, in the form of a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object as inputs. Both inputs are passed by reference.

**Output:** This function returns a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object that is the solution to the linear system of equations.

**Usage/Example:**
```cpp
int m, n, l;
m = 4; n = 4; l = 4;

array1D vec, solVec;
array2D mat;

vec = emptyVec(l);
vec(0) = 1; vec(1) = 2; vec(2) = 3; vec(3) = 4;

mat = emptyMat(m,n);
mat(0, 0) = 1; mat(0, 1) = 2; mat(0, 2) = 3; mat(0, 3) = 4;
               mat(1, 1) = 5; mat(1, 2) = 6; mat(1, 3) = 7;
                              mat(2, 2) = 8; mat(2, 3) = 9;
                                             mat(3, 3) = 10;

solVec = backSub(mat, vec);

for (int i = 0; i < l; i++) {
	std::cout << solVec(i) << " ";
}
```
outputs the following to the console
```
-0.235 -0.07 -0.075 0.4
```

**Implementation/Code:**

```cpp
array1D backSub(array2D& A, array1D& b) {

	int m = A.getRows();
	int n = A.getCols();
	int l = b.getLength();

	if (m != n || m != l) {
		throw "backSub: Incompatible Sizes";
	}

	for (int i = 0; i < m; i++) {
		if (A(i, i) == 0.0) throw "backSub: Division by zero";
	}

	array1D x;

	x.allocateMem(m);

	for (int i = m - 1; i >= 0; i--) {

		x(i) = b(i);

		for (int j = i + 1; j < m; j++) {

			x(i) = x(i) - A(i, j)*x(j);

		}

		x(i) = x(i) / A(i, i);
	}

	return x;
}
```

**Last Modified:** March/2019