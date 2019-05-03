# Software Manual

**Routine Name:** inverseIteration_JACOBI

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** The purpose of this function is to calculate eigenvalues of a given square matrix using the Inverse Iteration Algorithm. Whereas [inverseIteration](https://brandonfurman.github.io/math5610/SoftwareManual/SolverRoutines/gaussSeidelSolver) computes the solution to the linear system using Gauss Elimination, this version of the function uses Jacobi Iteration to solve the linear system.

**Input:** This function requires the following 5 items as inputs:

- A square matrix *A* in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object.
- An initial guess **v0** for the eigenvector in the form of a [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object.
- A shift *a* in the form of a double precision number. This function will return the eigenvalue that is closest to *a*.
- A tolerance in the form of a double precision number. The function stops iterating when the L2 norm of *A***v** - e**v** is less than the tolerance.
- An integer that limits the maximum number of iterations. 

**Output:** This function returns a double precision number that is the eigenvalue of the given matrix that is closest to the shift.

**Usage/Example:** Because Jacobi iteration only works on diagonally dominant matrices, caution should be employed when using this function. In diagonally dominant matrices, eigenvalues can often be on the same order as the diagonal entries. Consequently, a shift that is near these eigenvalues can often result in the matrix *A* - **a***I* not being diagonally dominant. This means that Jacobi iteration will not be able to solve the necessary equation, and the function will throw an exception. To summarize, getting a usable shift may require some trial and error. As an example, the following code finds an eigenvalue of a randomly generated diagonally dominant matrix:
```cpp
int m = 5;
int maxIter = 10000;
double tol = 1e-8;	
double a = 5;

//Create a random diagonally
//dominant matrix
array2D A;
A = randDiagDomMat(m);

std::cout << "The random matrix is:" << std::endl;
for (int i = 0; i < m; i++) {
	for (int j = 0; j < m; j++) {
		std::cout << A(i, j) << " ";
	}
	std::cout << std::endl;
}
std::cout << std::endl;

//Create an initial guess for
//the eigenvector.
array1D v0;
v0 = oneVec(m);

//Find an eigenvalue of A
try {
	double ev = 0.0;
	ev = inverseIteration_JACOBI(A, v0, a, tol, maxIter);
	std::cout << "The calculated Eigenvalue is: " << ev << std::endl;
}
catch (const char* msg) {
	std::cout << msg << std::endl;
}
```
This code outputs the following to console:
```
The random matrix is:
1.56688 0.00125126 0.563585 0.193304 0.808741
0.585009 2.31114 0.479873 0.350291 0.895962
0.82284 0.746605 2.6025 0.174108 0.858943
0.710501 0.513535 0.303995 1.54302 0.0149846
0.0914029 0.364452 0.147313 0.165899 0.769066

The calculated Eigenvalue is: 3.69035
```
which is the largest eigenvalue of the matrix.

**Implementation/Code:** The inverseIteration() function is implemented as follows:

```cpp
double inverseIteration_JACOBI(array2D& A, array1D v, double a, double tol, int maxIter) {

	int m = A.getRows();
	int n = A.getCols();
	int l = v.getLength();

	if (m != n || m != l) {
		throw "powerMethod: Incompatible Sizes";
	}

	array2D B;
	B = A;

	array1D vt, x0;
	vt.allocateMem(m);
	x0 = oneVec(m);

	int cntr = 0;

	double norm = 0.0;
	double ev = 0.0;
	double sum = 0.0;
	double error = 10.0*tol;

	//Form B = A - aI
	for (int i = 0; i < m; i++) {
		B(i, i) = A(i, i) - a;
	}

	while (error > tol && cntr < maxIter) {

		cntr += 1;

		//Solve (A - aI)vt = v_(k-1) for vt.
		vt = jacobiSolver(B, v, x0, tol, maxIter);

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
		throw "inverseIteration Failed to converge";
	}
}
```

**Last Modified:** April/2019