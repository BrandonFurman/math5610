The purpose of this page is to compare the execution time of the [slowSquareSystemSolver](https://brandonfurman.github.io/math5610/SoftwareManual/SolverRoutines/slowSquareSystemSolver) and the [SquareSystemSolver](https://brandonfurman.github.io/math5610/SoftwareManual/SolverRoutines/SquareSystemSolver) functions. The primary difference between the two functions is that slowSquareSystemSolver solves a given system by calling the [matRowReduction](https://brandonfurman.github.io/math5610/SoftwareManual/SolverRoutines/matRowReduction) and [backSub](https://brandonfurman.github.io/math5610/SoftwareManual/SolverRoutines/backSub) functions whereas the SquareSystemSolver function has everything inlined. A graph comparing the two functions for varying matrix sizes is given below.

![alt text](https://brandonfurman.github.io/math5610/homework/homework5/SquareSystemSolverComparison.png)

It can be seen that for small matrices (n < 100), the SquareSystemSolver(); function is nearly twice as fast as the slowSquareSystemSolver(); function. For large matrices (n > 3000), both functions perform identically. The execution time for each size was calculated using the code below

```cpp
int iters = 3;
int m = 3000;

array1D vec, sol;
array2D mat;

vec = randVec(m);
sol = emptyVec(m);
mat = randDiagDomMat(m);

std::clock_t time_req;

time_req = std::clock();

for (int i = 0; i < iters; i++) {
	sol = slowSquareSystemSolver(mat, vec);
}

time_req = clock() - time_req;

std::cout << "Processor time taken for multiplication: "
	<< std::fixed << std::setprecision(10) << (double)time_req / (CLOCKS_PER_SEC * iters) << " seconds" << std::endl;


sol = emptyVec(m);


time_req = std::clock();

for (int i = 0; i < iters; i++) {
	sol = SquareSystemSolver(mat, vec);
}

time_req = clock() - time_req;

std::cout << "Processor time taken for multiplication: "
	<< std::fixed << std::setprecision(10) << (float)time_req / (CLOCKS_PER_SEC * iters) << " seconds" << std::endl;
```