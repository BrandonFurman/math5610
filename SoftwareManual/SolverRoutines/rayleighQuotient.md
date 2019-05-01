# Software Manual

**Routine Name:** powerMethod

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** The purpose of this function is to calculate the largest eigenvalue of a given square matrix using the Power Method.

**Input:** This function requires the following 4 items as inputs:

- A square matrix *A* in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object.
- An initial guess **v0** for the eigenvector corresponding to the largest eigenvalue in the form of a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object.
- A tolerance in the form of a double precision number. The function stops iterating when the L2 norm of *A***v** - e**v** is less than the tolerance.
- An integer that limits the maximum number of iterations. 

**Output:** This function returns a double precision number that is the largest eigenvalue of the given matrix.

**Usage/Example:** Usage of this function is straightforward. The following code finds the largest eigenvalue of a Hilbert matrix of size 8:
```cpp
int m = 8;
int maxIter = 10;
double tol = 1e-4;

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
ev1 = powerMethod(A, v0, tol, maxIter);

std::cout << ev1;
```
This code outputs the following to console:
```
1.69594
```
which can be easily verified as the largest eigenvalue of Hilbert Matrix of size 8.

**Implementation/Code:** The powerMethod() function is implemented as follows:

```cpp
double powerMethod(array2D& A, array1D v, double tol, int maxIter) {

	int m = A.getRows();
	int n = A.getCols();
	int l = v.getLength();

	if (m != n || m != l) {
		throw "powerMethod: Incompatible Sizes";
	}

	array1D vt;
	vt.allocateMem(m);

	int cntr = 0;

	double norm = 0.0;
	double ev = 0.0;
	double sum = 0.0;
	double error = 10.0*tol;

	while (error > tol && cntr < maxIter) {

		cntr += 1;

		//Calculate vt = Av_(k-1) and ||vt||.
		norm = 0.0;
		for (int i = 0; i < m; i++) {
			sum = 0.0;
			for (int j = 0; j < m; j++) {
				sum += A(i, j)*v(j);
			}
			vt(i) = sum;
			norm += sum * sum;
		}

		norm = sqrt(norm);

		//Calculate v_k = vt / ||vt||
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