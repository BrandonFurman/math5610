# Software Manual

**Routine Name:** conjGrad

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** The purpose of this function is to solve the square linear system of equations A**x** = **b** using the Conjugate Gradient method.

**Input:** This function requires the following 5 items as inputs:

	- A symmetric positive definite coefficent matrix, *A*, in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object.
	- A vector of constant terms, **b**, in the form of a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object. 
	- A initial guess for the solution, **x0**, in the form of a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object.
	- A tolerance that specifies when to stop iterating in the form of a double precision number.
	- A limit to the number of iterations in the form of an integer. 

**Output:** This function returns an [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object that is the solution to the square linear system of equations A**x** = **b**. 

**Usage/Example:**
```cpp
int m = 3;

array2D A;
array1D b, x;
int maxIter = 1000;
double tol = 0.000001;

A.allocateMem(m, m);
b.allocateMem(m);
x.allocateMem(m);

A(0, 0) = 7; A(0, 1) = 3; A(0, 2) = 1;
A(1, 0) = 3; A(1, 1) = 10; A(1, 2) = 2;
A(2, 0) = 1; A(2, 1) = 2; A(2, 2) = 15;

b(0) = 28; b(1) = 31; b(2) = 22;
x(0) = 0; x(1) = 0; x(2) = 0;

x = conjGrad(A, b, x, tol, maxIter);

for (int i = 0; i < m; i++) {
	std::cout << x(i) << " ";
}
```
outputs the following to console:
```
3 2 1
```
which is the exact solution to the stated problem.

**Implementation/Code:**

```cpp
array1D conjGrad(array2D& A, array1D& b, array1D x, double tol, int maxIter) {

	int m = A.getRows();
	int n = A.getCols();
	int l = b.getLength();

	if (m != n || m != l) {
		throw "conjGrad: Incompatible Matrix Sizes";
	}

	array1D r, p, s;
	r.allocateMem(m);
	p.allocateMem(m);
	s.allocateMem(m);

	int cntr = 0;
	double error = 10.0*tol;
	double sum = 0.0;

	double den = 0.0;
	double step = 0.0;

	double d0 = 0.0;
	double d1 = 0.0;
	double bd = 0.0;
	double k = 0.0;

	//Calculate an initial value for the residual
	for (int i = 0; i < n; i++) {

		sum = 0.0;

		for (int j = 0; j < n; j++) {

			sum += A(i, j) * x(j);

		}

		r(i) = b(i) - sum;
		d0 += r(i) * r(i);
		bd += b(i) * b(i);
	}

	p = r;

	while (d0 > tol*tol*bd && cntr < maxIter) {

		cntr += 1;

		//Calculates the product s = A*r and p*s
		den = 0.0;
		for (int i = 0; i < n; i++) {

			sum = 0.0;

			for (int j = 0; j < n; j++) {

				sum += A(i, j) * p(j);

			}

			s(i) = sum;
			den += p(i) * sum;
		}

		step = d0 / den;


		//Calculates the next step in the solution, residual, and d.
		d1 = 0.0;
		for (int i = 0; i < n; i++) {

			x(i) += step * p(i);
			r(i) -= step * s(i);
			d1 += r(i) * r(i);

		}

		for (int i = 0; i < n; i++) {

			p(i) = r(i) + (d1 / d0) * p(i);

		}

		d0 = d1;
	}

	return x;
}
```

**Last Modified:** April/2019