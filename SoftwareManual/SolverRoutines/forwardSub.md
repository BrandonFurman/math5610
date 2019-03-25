# Software Manual

**Routine Name:** forwardSub

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function computes the solution to a linear system of equation whose coefficient matrix is lower triangular.

**Input:**

**Output:**

**Usage/Example:**
```cpp
int m, n, l;
m = 4; n = 4; l = 4;

array1D vec, solVec;
array2D mat;

vec = emptyVec(l);
vec(0) = 1; vec(1) = 2; vec(2) = 3; vec(3) = 4;

mat = emptyMat(m, n);
mat(0, 0) = 1;
mat(1, 0) = 2; mat(1, 1) = 3;
mat(2, 0) = 4; mat(2, 1) = 5; mat(2, 2) = 6;
mat(3, 0) = 7; mat(3, 1) = 8; mat(3, 2) = 9; mat(3, 3) = 10;

solVec = forwardSub(mat, vec);

for (int i = 0; i < l; i++) {
	std::cout << solVec(i) << " ";
}
```
outputs the following to the console
```
1 0 -0.166667 -0.15
```

**Implementation/Code:**

```cpp
array1D forwardSub(array2D& A, array1D& b) {

	int m = A.getRows();
	int n = A.getCols();
	int l = b.getLength();

	if (m != n || m != l) {
		throw "forwardSub: Incompatible Sizes";
	}

	for (int i = 0; i < m; i++) {
		if (A(i, i) == 0.0) throw "forwardSub: Division by zero";
	}

	array1D x;

	x.allocateMem(m);

	for (int i = 0; i < m; i++) {

		x(i) = b(i);

		for (int j = 0; j < i; j++) {

			x(i) = x(i) - A(i, j)*x(j);

		}

		x(i) = x(i) / A(i, i);
	}

	return x;
}
```

**Last Modified:** March/2019