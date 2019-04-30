The purpose of this page is to evaluate...

|        n = 4       |    x1    |    x2   |    x3    |    x4   |
|:------------------:|:--------:|:-------:|:--------:|:-------:|
|  Steepest Descent  | -3.99826 | 59.9804 | -179.953 | 139.969 |
| Conjugate Gradient |       -4 |      60 |     -180 |     140 |

```cpp
int maxIter = 10000;
double tol = 0.00001;
int m = 5000;

array2D A;
array1D b, x, x1, x2, x3;

A = randDiagDomMat(m);
for (int i = 0; i < m; i++) A(i, i) += m;

b = randVec(m);
x = randVec(m);

std::clock_t time_req;

time_req = std::clock();
for (int i = 0; i < 100; i++) {
	x1 = gaussSeidelSolver(A, b, x, tol, maxIter);
}
time_req = clock() - time_req;


std::cout << "CPU time: "
	<< std::fixed << std::setprecision(10) << (double)time_req / (CLOCKS_PER_SEC*100.0) << " seconds" << std::endl;

	
time_req = std::clock();
for (int i = 0; i < 100000; i++) {
	x2 = SquareSystemSolver(A, b);
}
time_req = clock() - time_req;


std::cout << "CPU Time: "
	<< std::fixed << std::setprecision(10) << (double)time_req / (CLOCKS_PER_SEC*100000.0) << " seconds" << std::endl;
```