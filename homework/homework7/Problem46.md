The purpose of this page is to evaluate the performance of the Steepest Descent and Conjugate Gradient Methods when evalutating a Hilbert coefficient matrix. A tolerance of 0.00001 is used and the maximum number of iterations is restricted to 100,000. 

For a Hilbert matrix of size 4, both the Steepest Descent and Conjugate Gradient methods converge to the correct solution. It took the Steepest Descent method 57,607 iterations to converge to the correct solution whereas the Conjugate Gradient method converged in only 4. The results are shown below.

|        n = 4       |    x1    |    x2   |    x3    |    x4   |
|:------------------:|:--------:|:-------:|:--------:|:-------:|
|  Steepest Descent  | -3.99826 | 59.9804 | -179.953 | 139.969 |
| Conjugate Gradient |       -4 |      60 |     -180 |     140 |

For a Hilbert matrix of size 8, the Steepest Descent method was unable to converge to a correct solution within 100,000 iterations. The Conjugate Gradient Method converged to the correct solution in 18 iterations. The output of both functions is shown below.

|        n = 8       |  x1  |   x2   |   x3  |   x4   |    x5   |    x6   |    x7   |   x8   |
|:------------------:|:----:|:------:|:-----:|:------:|:-------:|:-------:|:-------:|:------:|
|  Steepest Descent  | 3.12 | -42.10 | 62.19 | 159.59 | -106.52 | -299.35 | -153.32 | 411.22 |
| Conjugate Gradient |   -8 |    504 | -7560 |  46200 | -138600 |  216216 | -168168 |  51480 |

For Hilbert matrices of size 16 and 32, both methods fail to converge to a solution. The reason these matrices fail to converge at large sizes is because their condition number is large.


```cpp
int m = 4;
double tol = 0.00001;
int maxIter = 100000;

array2D A;
array1D b, x0, x1, x2;

A = HilbertMat(m);
b = oneVec(m);
x0 = randVec(m);

x1 = steepestDescent(A, b, x0, tol, maxIter);

for (int i = 0; i < m; i++) std::cout << x1(i) << " ";

std::cout << std::endl;

x2 = conjGrad(A, b, x0, tol, maxIter);

for (int i = 0; i < m; i++) std::cout << x2(i) << " ";
```