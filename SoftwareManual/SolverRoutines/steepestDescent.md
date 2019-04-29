# Software Manual

**Routine Name:** steepestDescent

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function solves the square linear system of equations A**x** = **b** using the Steepest Descent method.

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:**

```cpp
array1D steepestDescent(array2D& A, array1D& b, array1D x0, double tol, int maxIter) {

	int m = A.getRows();
	int n = A.getCols();
	int p = b.getLength();

	if (m != n || m != p) {
		throw "steepestDescent: Incompatible Matrix Sizes";
	}

	array1D x1, r, q;
	x1.allocateMem(p);
	r.allocateMem(p);
	q.allocateMem(p);

	x1 = x0;

	int cntr = 0;
	double error = 10.0*tol;
	double sum = 0.0;

	double num = 0.0;
	double den = 0.0;
	double step = 0.0;

	//Calculate an initial value for the residual
	for (int i = 0; i < n; i++) {
		sum = 0.0;
		for (int j = 0; j < n; j++) {
			sum = sum + A(i, j) * x0(j);
		}
		r(i) = b(i) - sum;
	}

	while (error > tol && cntr < maxIter) {

		cntr += 1;

		//Calculate q = A*r

		num = 0.0;
		den = 0.0;

		for (int i = 0; i < n; i++) {
			sum = 0.0;
			for (int j = 0; j < n; j++) {
				sum = sum + A(i, j) * r(j);
			}
			q(i) = sum;
			num = num + r(i) * r(i);
			den = den + r(i) * sum;
		}

		step = num / den;

		//Calculate the next steps of x and r.
		for (int i = 0; i < n; i++) {
			x1(i) = x0(i) + step * r(i);
			r(i) = r(i) - step * q(i);
		}

		error = absErrVecTwoNorm(x1, x0);

		x0 = x1;
	}

	return x1;
}
```

**Last Modified:** April/2019