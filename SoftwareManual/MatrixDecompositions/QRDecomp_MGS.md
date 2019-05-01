# Software Manual

**Routine Name:** QRDecomp_MGS

**Author:** Brandon Furman

**Language:** C++
**Description/Purpose:** The purpose of this function is to calculate the *QR* decomposition of a given square matrix *A*. It does so using the Modified Gram-Schmidt process. A comparison between this function, [QRDecomp_CGS](https://brandonfurman.github.io/math5610/SoftwareManual/MatrixDecompositions/QRDecomp_CGS), and [QRDecomp_HOUSE](https://brandonfurman.github.io/math5610/SoftwareManual/MatrixDecompositions/QRDecomp_HOUSE) can be found [here](https://brandonfurman.github.io/math5610/homework/homework6/Problem23).

**Input:** This function accepts a *n* x *n* square matrix, in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object, as input.

**Output:** This function returns a *n* x 2*n* rectangular block matrix in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object. The first *n* x *n* block is the *Q* component of the factorization and the second *n* x *n* block is the *R* component of the factorization.

**Usage/Example:** Usage of the function is straightforward, but special care should be taken when analyzing the output. Consider the problem of finding the QR factorization of *A* = [[12,-51,4],[6,167,-68],[-4,24,-41]]. The code found below utilizes the QRDecomp_MGS() function to solve this problem.
```cpp
int m = 3;

//Create and populate the desired matrix.
array2D A,QR;
A.allocateMem(m,m);
A(0, 0) = 12; A(0, 1) = -51; A(0, 2) = 4;
A(1, 0) = 6; A(1, 1) = 167; A(1, 2) = -68;
A(2, 0) = -4; A(2, 1) = 24; A(2, 2) = -41;

//Use the Modified Gram-Schmidt procedure
//to find the QR factorization.
QR = QRDecomp_MGS(A);

//Display the factorization
for (int i = 0; i < m; i++) {
	for (int j = 0; j < 2*m; j++) {
		std::cout << std::fixed << std::setprecision(5) << QR(i,j) << " ";
	}
	std::cout << std::endl;
}
```
This code outputs the following to the console:
```
 0.85714 -0.39429 -0.33143 14.00000  21.00000 -14.00000
 0.42857  0.90286  0.03429 -0.00000 175.00000 -70.00000
-0.28571  0.17143 -0.94286  0.00000   0.00000  35.00000
```
which means that
```
    0.85714 -0.39429 -0.33143
U = 0.42857  0.90286  0.03429
   -0.28571  0.17143 -0.94286
```
and
```
    14.00000  21.00000 -14.00000
R = -0.00000 175.00000 -70.00000
     0.00000   0.00000  35.00000
```

**Implementation/Code:** The QRDecomp_MGS() function is implemented as follows:

```cpp
array2D QRDecomp_MGS(array2D A) {

	int m = A.getRows();
	int n = A.getCols();

	if (n != m) {
		throw "GSOrtho: Matrix Not Square";
	}

	array2D QR;
	QR.allocateMem(n, 2 * n);

	double rij = 0.0;
	double rjj = 0.0;

	//This loop calculates the Q portion of the QR factorization.
	//It does so using the Modified Gram-Schmidt procedure.
	for (int j = 0; j < n; j++) {

		for (int k = 0; k < n; k++) {
			QR(k, j) = A(k, j);
		}

		for (int i = 0; i < j; i++) {

			//Calculate the dot product of the jth and ith column of Q.
			//Then use that product to orthogonalize the jth column of Q.

			rij = 0.0;

			for (int k = 0; k < n; k++) {
				rij = rij + QR(k, j) * QR(k, i);
			}

			for (int k = 0; k < n; k++) {
				QR(k, j) = QR(k, j) - rij * QR(k, i);
			}
		}

		//Normalize the jth column of Q by calculating
		//its norm and dividing by it.

		rjj = 0.0;

		for (int k = 0; k < n; k++) {
			rjj = rjj + QR(k, j)*QR(k, j);
		}

		rjj = sqrt(rjj);

		for (int k = 0; k < n; k++) {
			QR(k, j) = QR(k, j) / rjj;
		}
	}

	//Calculate the R portion of the QR factorization
	//In this case R = (Q^T)*A

	double sum;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum = 0.0;
			for (int k = 0; k < m; k++) {
				sum = sum + QR(k, i) * A(k, j);
			}
			QR(i, j + n) = sum;
		}
	}

	return QR;
}
```

**Last Modified:** April/2019