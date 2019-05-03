# Software Manual

**Routine Name:** inverseIteration

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** The purpose of this function is to calculate eigenvalues of a given square matrix using the Inverse Iteration Algorithm.

**Input:** This function requires the following 5 items as inputs:

- A square matrix *A* in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object.
- An initial guess **v0** for the eigenvector in the form of a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object.
- A shift *a* in the form of a double precision number. This function will return the eigenvalue that is closest to *a*.
- A tolerance in the form of a double precision number. The function stops iterating when the L2 norm of *A***v** - e**v** is less than the tolerance.
- An integer that limits the maximum number of iterations. 

**Output:** This function returns a double precision number that is the eigenvalue of the given matrix that is closest to the shift.

**Usage/Example:** Usage of this function is straightforward. The following code finds the second largest eigenvalue of a Hilbert matrix of size 8:
```cpp
int m = 8;
int maxIter = 1000;
double tol = 1e-4;

//The Inverse Iteration Algorithm returns
//the eigenvalue closest to this number.
double a = 0.2;

//Create a Hilbert matrix.
array2D A;
A = HilbertMat(m);

//Create an initial guess for
//the eigenvector corresponding
//to the largest eigenvalue.
array1D v0;
v0 = oneVec(m);

//Find the largest eigenvalue of A.
double ev1 = 0.0;
ev1 = inverseIteration(A, v0, a, tol, maxIter);

std::cout << ev1 << std::endl;
```
This code outputs the following to console:
```
0.298125
```
which can be easily verified as the second largest eigenvalue of the Hilbert Matrix of size 8.

**Implementation/Code:** The inverseIteration() function is implemented as follows:

```cpp
double inverseIteration(array2D& A, array1D v, double a, double tol, int maxIter) {

	int m = A.getRows();
	int n = A.getCols();
	int l = v.getLength();

	if (m != n || m != l) {
		throw "inverseIteration: Incompatible Sizes";
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

	//Form B = A - aI
	for (int i = 0; i < m; i++) {
		B(i, i) = A(i,i) - a;
	}

	while (error > tol && cntr < maxIter) {

		cntr += 1;

		//Solve (A - aI)vt = v_(k-1) for vt.
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

	return ev;
}
```

**Last Modified:** April/2019