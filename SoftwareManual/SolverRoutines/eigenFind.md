# Software Manual

**Routine Name:** eigenFind

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** The purpose of this function is to find eigenvalues of a given matrix. It does so by first finding the largest and smallest eigenvalues, then using the Inverse Iteration method to check for other eigenvalues in the interval between the largest and smallest. This method does not guarantee that all eigenvalues will be found.

**Input:** This function requires the following 4 items as inputs:

- A square matrix *A* in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object.
- A tolerance in the form of a double precision number. The function stops iterating when the L2 norm of *A***v** - e**v** is less than the tolerance.
- An integer that limits the maximum number of iterations. 
- An integer that specifies how many points between the largest and smallest eigenvalue should be tested for other eigenvalues. Increasing this number can often result in more eigenvalues being found, but it will also take longer to execute.

**Output:** This function returns a vector of length *n* that contains between 2 and *n* unique eigenvalues.

**Usage/Example:** Usage of this function is straightforward. The following code finds the eigenvalues of the Hilbert matrix of size 4:
```cpp
int m = 4;
int maxIter = 100000;
int subDivs = 100;
double tol = 1e-4;

//Create a Hilbert matrix.
array2D A;
A = HilbertMat(m);

//Create a vector to store the eigenvalues.
array1D ev;

try {
	ev = eigenFind(A, tol, maxIter, subDivs);
}
catch (const char* msg) {
	std::cout << msg << std::endl;
}

for (int i = 0; i < m; i++) std::cout << ev(i) << std::endl;
```
This code outputs the following to console:
```
1.50021
9.67193e-05
0.00673725
0.169141
```
which can be verified as all four eigenvalues of the Hilbert matrix of size 4. If we were to instead use
```cpp
int m = 8;
```
in the above code, then the output would be
```
1.69594
6.45931e-10
0.0262127
0.298125
0
0
0
0
```
which means that only 4 of the eight eigenvalues were found. These results can be improved somewhat by increasing the number of subdivisions. If we set
```
int subDivs = 1000;
```
then the output becomes
```
1.69594
6.45931e-10
0.00146767
0.0262125
0.298125
0
0
0
```
which means that 5 of the eigenvalues have been found.

**Implementation/Code:** The powerMethod() function is implemented as follows:

```cpp
array1D eigenFind(array2D& A, array1D v, double tol, int maxIter) {

	int m = A.getRows();
	int n = A.getCols();

	if (m != n) {
		throw "eigenSolver: Matrix not square";
	}

	array1D v0, ev;
	v0 = oneVec(m);
	ev = emptyVec(m);

	double ev0 = 0.0;
	ev0 = powerMethod(A, v0, tol, maxIter);
	ev(0) = ev0;

	double ev1 = 0.0;
	ev1 = inverseIteration(A, v0, 0.0, tol, maxIter);
	ev(1) = ev1;

	double span = ev0 - ev1;
	double evk = 0.0;

	for (int i = 0; i < 1000; i++) {

		evk = inverseIteration(A, v0, ev1 + ((double)i/1000.0)*span, tol, maxIter);

		for (int j = 0; j < m; j++) {
			if (evk >= ev(j) - 5.0*tol && evk <= ev(j) + 5.0*tol) break;
			if (ev(j) == 0.0) {
				ev(j) = evk;
				break;
			}
		}

	}
	return ev;
}
```

**Last Modified:** April/2019