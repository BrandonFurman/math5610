The purpose of this page is to show how the condition number of the Hilbert matrix changes with size. This graph can be found belows.

![alt text](https://brandonfurman.github.io/math5610/homework/homework8/ConditionNumber.png)

From this graph it can be seen that the condition number for the Hilbert matrices grows exponentially. Past *n* = 10 the condition number became impossible to calculate with my functions due to the smallest eigenvalue approaching machine epsilon. The data for this graph was generated using the code below.

```cpp
int maxIter = 10000;
double tol = 1e-12;

array2D A;

double condNum;

try {
	for (int m = 1; m < 11; m++) {
		A = HilbertMat(m);
		condNum = condNumApprox(A, tol, maxIter);
		std::cout << m << " " << condNum << std::endl;
	}
		
}
catch (const char* msg) {
	std::cout << msg << std::endl;
}
```