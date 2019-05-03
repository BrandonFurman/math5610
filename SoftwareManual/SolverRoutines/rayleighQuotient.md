# Software Manual

**Routine Name:** rayleighQuotient

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** The purpose of this function is to calculate an eigenvalue for a given matrix using the Rayleigh Quotient algorithm.

**Input:** This function requires the following 4 items as inputs:

- A square matrix *A* in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object.
- An initial guess **v0** for the eigenvector corresponding to the largest eigenvalue in the form of a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object.
- A tolerance in the form of a double precision number. The function stops iterating when the L2 norm of *A***v** - e**v** is less than the tolerance.
- An integer that limits the maximum number of iterations. 

**Output:** This function returns a double precision number that is an eigenvalue of the given matrix. This eigenvalue is the one corresponding to the eigenvector closest to **v0**.

**Usage/Example:** Usage of this function is straightforward. The following code finds the largest eigenvalue of a Hilbert matrix of size 8:
```cpp
int m = 3;
int maxIter = 1000;
double tol = 1e-8;

//Create a Hilbert matrix.
array2D A;
A = HilbertMat(m);

//Create an initial guess for
//the eigenvector corresponding
//to the largest eigenvalue.
array1D v0;
v0 = oneVec(m);
//v0 = scaleVec(-1.0 / sqrt(3.0), v0);
v0(0) = 0.5; v0(1) = -0.5; v0(2) = 0.5;

//Find the largest eigenvalue of A.
double ev1 = 0.0;
ev1 = rayleighQuotient(A, v0, tol, maxIter);

std::cout << ev1 << std::endl;
```
This code outputs the following to console:
```
0.00268734
```
which is the third eigenvalue of the Hilbert matrix of size 3.

**Implementation/Code:** The rayleighQuotient() function is implemented as follows:

```cpp
double rayleighQuotient(array2D& A, array1D v, double tol, int maxIter) {

	int m = A.getRows();
	int n = A.getCols();
	int l = v.getLength();

	if (m != n || m != l) {
		throw "powerMethod: Incompatible Sizes";
	}

	array2D B;
	B = A;

	array1D vt;
	vt.allocateMem(m);

	int cntr = 0;

	double norm = 0.0;
	double ev = 0.0;
	double sum = 0.0;
	double error = 10.0*tol;

	//Calculate an initial guess for the eigenvalue.
	ev = 0.0;
	for (int i = 0; i < m; i++) {
		sum = 0.0;
		for (int j = 0; j < m; j++) {
			sum += A(i, j)*v(j);
		}
		ev += v(i)*sum;
	}
	sum = 0.0;

	while (error > tol && cntr < maxIter) {

		cntr += 1;

		//Form B = A - evI
		for (int i = 0; i < m; i++) {
			B(i, i) = A(i,i) - ev;
		}

		//Solve (B)vt = v_(k-1) for vt.
		vt = SquareSystemSolver(B, v);

		//Calculate v_k = vt / ||vt||
		norm = twoNormVec(vt);
		for (int i = 0; i < m; i++) {
			v(i) = vt(i) / norm;
		}

		//Calculate the eigenvalue using
		//ev = (v^T)_k A v_k
		ev = 0.0;
		for (int i = 0; i < m; i++) {
			sum = 0.0;
			for (int j = 0; j < m; j++) {
				sum += A(i, j)*v(j);
			}
			ev += v(i)*sum;
		}

		//Calculate the L2 norm of A(v_k) - ev(v_k)
		//This L2 norm is used as the stopping criteria
		error = 0.0;
		for (int i = 0; i < m; i++) {
			sum = 0.0;
			for (int j = 0; j < m; j++) {
				sum += A(i, j)*v(j);
			}
			sum = sum - ev * v(i);
			error += sum * sum;
		}

		error = sqrt(error);
	}

	if (cntr != maxIter) {
		return ev;
	}
	else {
		throw "rayleighQuotient: Failed to converge";
	}
}
```

**Last Modified:** April/2019