# Software Manual

**Routine Name:** randSymPosDefMat

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** The purpose of this function is generate a square, positive definite matrix. It generates the matrix by multiplying a random matrix by its transpose and adding *m* to each of the diagonal entries.

**Input:** This routine accepts a single integer, *m*, that defines the number of rows and columns in the matrix.

**Output:** The functions returns an [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object with *m* rows and *m* columns.

**Usage/Example:** Usage is straightforward. To generate a 4*x*4 matrix the function can be called like in the following code:
```cpp
array2D mat;

mat = randSymPosDefMat(4);

for (int i = 0; i < 4; i++) {
	for (int j = 0; j < 4; j++) {
		std::cout << mat(i, j) << " ";
	}
	std::cout << std::endl;
}
```
Executing this code outputs the following to console:
```cpp
5.00906  1.0635   1.15012 0.361192
1.0635   5.49797  1.67021 0.781994
1.15012  1.67021  6.00258 1.03384
0.361192 0.781994 1.03384 4.86117
```
If a 20*x*20 matrix is desired, then we can call
```
randSymPosDefMat(20);
```
and doing so yields
```
25.5612 3.72904 5.50075 3.98441 4.53272 5.44157 4.13524 4.78415 4.14961 3.38296 4.85773 4.19826 4.62052 4.45429 4.57553 4.4834  4.56055 4.55898 4.97196 4.13268
3.72904 25.4588 5.04753 4.69621 4.5128  4.53037 4.77446 5.08259 4.96795 3.09428 4.54811 5.32652 4.39218 4.57116 4.61463 4.34823 5.09619 4.11683 4.4667  4.80072
5.50075 5.04753 29.1397 5.70031 6.53303 6.34842 5.99064 6.82419 6.0324  4.58241 5.78911 6.80117 6.46275 6.29489 6.97015 6.14338 6.32256 6.02631 5.51659 6.24748
3.98441 4.69621 5.70031 26.3857 4.92052 4.25707 5.1233  5.62027 5.03991 3.63948 4.46727 6.23411 4.45951 4.5714  5.17467 4.67939 5.55565 4.7854  5.06466 5.30582
4.53272 4.5128 6.53303  4.92052 26.1584 5.36655 4.68383 5.38357 5.82465 3.63259 4.86619 5.67009 5.24956 5.48552 5.92689 5.00543 5.06607 4.9948  4.50318 5.21884
5.44157 4.53037 6.34842 4.25707 5.36655 26.9697 5.00394 5.2561  5.39696 3.94759 4.84704 4.95256 5.57147 4.82143 5.17914 5.30176 5.312   5.01816 4.99961 4.8492
4.13524 4.77446 5.99064 5.1233  4.68383 5.00394 26.8055 5.05112 5.44708 4.03133 4.76949 5.8173  5.44134 4.87463 4.70835 5.56251 5.65518 5.03639 5.14701 5.12807
4.78415 5.08259 6.82419 5.62027 5.38357 5.2561  5.05112 27.2305 5.94041 3.68883 5.75954 6.33164 5.20995 5.21331 5.6338  4.85625 5.08408 4.71661 5.37146 6.18144
4.14961 4.96795 6.0324  5.03991 5.82465 5.39696 5.44708 5.94041 27.0366 3.34593 5.31533 5.97516 5.40777 5.09995 5.20261 4.95466 5.03782 4.88274 5.03109 5.75628
3.38296 3.09428 4.58241 3.63948 3.63259 3.94759 4.03133 3.68883 3.34593 24.1869 3.11167 4.16201 3.59533 4.39895 4.1912  3.42855 3.70083 2.77389 3.25658 3.11108
4.85773 4.54811 5.78911 4.46727 4.86619 4.84704 4.76949 5.75954 5.31533 3.11167 26.7814 5.68096 5.38849 4.71861 5.09558 4.38057 5.24362 4.67564 5.32189 5.32808
4.19826 5.32652 6.80117 6.23411 5.67009 4.95256 5.8173  6.33164 5.97516 4.16201 5.68096 27.3367 5.59265 5.60074 5.86391 4.98279 6.23149 4.98854 5.0906  5.88916
4.62052 4.39218 6.46275 4.45951 5.24956 5.57147 5.44134 5.20995 5.40777 3.59533 5.38849 5.59265 26.9103 4.92699 5.43072 5.29207 5.5732 5.05206  4.78726 4.87043
4.45429 4.57116 6.29489 4.5714  5.48552 4.82143 4.87463 5.21331 5.09995 4.39895 4.71861 5.60074 4.92699 26.9586 5.90533 4.59418 5.01136 4.40864 4.74629 4.63461
4.57553 4.61463 6.97015 5.17467 5.92689 5.17914 4.70835 5.6338  5.20261 4.1912  5.09558 5.86391 5.43072 5.90533 26.778  5.12819 5.34192 4.72948 4.88981 5.4709
4.4834  4.34823 6.14338 4.67939 5.00543 5.30176 5.56251 4.85625 4.95466 3.42855 4.38057 4.98279 5.29207 4.59418 5.12819 26.2617 5.13328 4.85725 4.88268 4.89677
4.56055 5.09619 6.32256 5.55565 5.06607 5.312 5.65518   5.08408 5.03782 3.70083 5.24362 6.23149 5.5732  5.01136 5.34192 5.13328 26.6492 5.54225 5.33857 5.08487
4.55898 4.11683 6.02631 4.7854  4.9948  5.01816 5.03639 4.71661 4.88274 2.77389 4.67564 4.98854 5.05206 4.40864 4.72948 4.85725 5.54225 26.4095 4.95707 5.02316
4.97196 4.4667  5.51659 5.06466 4.50318 4.99961 5.14701 5.37146 5.03109 3.25658 5.32189 5.0906  4.78726 4.74629 4.88981 4.88268 5.33857 4.95707 26.1839 5.29577
4.13268 4.80072 6.24748 5.30582 5.21884 4.8492  5.12807 6.18144 5.75628 3.11108 5.32808 5.88916 4.87043 4.63461 5.4709  4.89677 5.08487 5.02316 5.29577 26.3874
```


**Implementation/Code:** The following is the code for randSymDiagDomMat(int m):

```cpp
array2D randSymPosDefMat(int m) {

	array2D A, B;

	A = randMat(m,m);

	B.allocateMem(m, m);

	double sum = 0.0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				sum = sum + A(i, k) * A(j, k);
			}
			if (i == j) sum = sum + m;

			B(i, j) = sum;

			sum = 0.0;
		}
	}

	return B;
}
```

**Last Modified:** April/2019