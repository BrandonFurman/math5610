# Software Manual

**Routine Name:** condNumApprox

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** The purpose of this function is to approximate the condition number of a given normal matrix with positive eigenvalues. It does so by using Power Iteration to find the largest eigenvalue, and Inverse Iteration to find the smallest eigenvalue. It the takes the ratio of the two eigenvalues to find the condition number.

**Input:** This function requires the following 4 items as inputs:

- A square matrix *A* in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object.
- A tolerance in the form of a double precision number. The function stops iterating to find eigenvalues when the L2 norm of *A***v** - e**v** is less than the tolerance.
- An integer that limits the maximum number of iterations. 

**Output:** This function returns a double precision number that is likely to be the condition number of the matrix. If it cannot find such a number, the function will throw an exception.

**Usage/Example:** Usage of this function is straightforward. The following code finds the condition number for a Hilbert matrix of size 8:
```cpp
int m = 8;
int maxIter = 10000;
double tol = 1e-12;

//Create a Hilbert matrix.
array2D A;
A = HilbertMat(m);

double condNum;

try {
	condNum = condNumApprox(A, tol, maxIter);
	std::cout << condNum << std::endl;
}
catch (const char* msg) {
	std::cout << msg << std::endl;
}
```
This code outputs the following to console:
```
1.52576e+10
```
which is verified as the condition number of the matrix.

**Implementation/Code:** The condNumApprox() function is implemented as follows:

```cpp
double condNumApprox(array2D& A, double tol, int maxIter) {

	int m = A.getRows();
	int n = A.getCols();

	if (m != n) {
		throw "condNumApprox: Matrix not square";
	}

	array1D v0;
	v0 = oneVec(m);

	double ev1 = 0.0;
	ev1 = powerMethod(A, v0, tol, maxIter);

	double ev2 = 0.0;
	ev2 = inverseIteration(A, v0, 0.0, tol, maxIter);

	double condNum;
	condNum = ev1 / ev2;

	return condNum;
}
```

**Last Modified:** April/2019