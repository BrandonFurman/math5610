The purpose of this page is to compare results on symmetric positive definite linear systems of equations using Jacobi Iteration and the Conjugate Gradient Method. A plot of CPU Time vs. Matrix Size and Residual Norm vs. Iterations is provided for these two algorithms below. In both cases a tolerance of 0.0001 is used.

![alt text](https://brandonfurman.github.io/math5610/homework/homework7/JacobiConjugateComparison1.png)

From this graph it can be seen that the Conjugate Gradient Method is more than an order of magnitude faster than Jacobi Iteration at every matrix size between *n* = 100 and *n* = 2000.

```cpp
int N = 100;
int maxIter = 10000;
double tol = 1e-4;

for (int m = 100; m <= 2000; m += 100) {

	std::cout << m << " ";

	array2D A;
	array1D b, x, x1, x2, x3;

	A = randSymDiagDomMat(m);
	for (int i = 0; i < m; i++) A(i, i) *= 1.1;

	b = oneVec(m);
	b = scaleVec(m, b);
	x = emptyVec(m);

	std::clock_t time_req;

	time_req = clock();
	for (int i = 0; i < N; i++) {
		x1 = jacobiSolver(A, b, x, tol, maxIter);
	}
	time_req = clock() - time_req;

	std::cout << std::fixed << std::setprecision(10) << (double)time_req / (CLOCKS_PER_SEC*N) << " ";


	time_req = clock();
	for (int i = 0; i < N; i++) {
		x2 = conjGrad(A, b, x, tol, maxIter);
	}
	time_req = clock() - time_req;

	std::cout << std::fixed << std::setprecision(10) << (double)time_req / (CLOCKS_PER_SEC*N) << " ";

	x3 = subVec(x1, x2);

	double norm = twoNormVec(x3);

	if (norm <= 0.01) {
		std::cout << "Pass" << std::endl;
	}
		
}
```