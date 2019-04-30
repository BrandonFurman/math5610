# Software Manual

**Routine Name:** QRSquareSystemSolver

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** The purpose of this function is to solve the square linear system of equations A**x** = **b** using QR factorization. To do so it factors A into an orthogonal component Q and upper triangular component R. It then calculates **z** = (Q^T)**b** and uses back substitution to solve R**x** = **z**. The QR factorization is performed using the modified Gram-Schmidt process.

**Input:** This function accepts a coefficient matrix, A, in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object and a vector of constant terms, **b**, in the form of a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object as inputs. Both inputs are passed by reference.

**Output:** This function returns the solution to the system of equations, **x**. The function will throw an exception if any of the diagonal entries of the coefficient matrix are zero.

**Usage/Example:** Usage is straightforward. The following code defines a coefficient matrix and vector of constant terms and solves the resulting linear system of equations:
```cpp
int m = 3;

array1D b, x;
array2D A;

A.allocateMem(m, m);
b.allocateMem(m);

A(0, 0) = 7; A(0, 1) = 3; A(0, 2) = 1;
A(1, 0) = -3; A(1, 1) = 10; A(1, 2) = 2;
A(2, 0) = 1; A(2, 1) = 7; A(2, 2) = -15;

b(0) = 3; b(1) = 4; b(2) = 2;

x = QRSquareSystemSolver(A, b);

for (int i = 0; i < l; i++) {
	std::cout << x(i) << " ";
}
```
This code outputs the following to the console:
```
0.223242 0.448777 0.0909786
```


**Implementation/Code:** The code for the LUSquareSystemSolver() functions is as follows:

```cpp
array1D QRSquareSystemSolver(array2D& A, array1D& b) {

	int m = A.getRows();
	int n = A.getCols();

	if (n != m) {
		throw "QRSquareSystemSolver: Matrix Not Square";
	}

	array1D x;
	x.allocateMem(n);

	//Get the QR factorization of A.
	array2D QR;
	QR = QRDecomp_MGS(A);

	double sum = 0.0;

	//Calculate x' = (Q^T)*b
	for (int i = 0; i < n; i++) {
		sum = 0.0;
		for (int j = 0; j < n; j++) {
			sum += QR(j, i)*b(j);
		}
		x(i) = sum;
	}

	//Perform back substitution on the equation Rx = x'.
	for (int i = m - 1; i >= 0; i--) {
		for (int j = i + 1; j < m; j++) {
			x(i) = x(i) - QR(i, j + n)*x(j);
		}
		x(i) = x(i) / QR(i, i + n);
	}

	return x;
}
```

**Last Modified:** April/2019