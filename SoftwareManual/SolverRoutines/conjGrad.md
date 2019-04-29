# Software Manual

**Routine Name:** conjGrad

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function solves the square linear system of equations A**x** = **b** using the Conjugate Gradient method.

**Input:**

**Output:**

**Usage/Example:**

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