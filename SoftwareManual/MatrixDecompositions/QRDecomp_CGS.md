# Software Manual

**Routine Name:** QRDecomp_CGS

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** The purpose of this function is to calculate the *QR* decomposition of a given square matrix *A*. It does so using the Classical Gram-Schmidt process.

**Input:** This function accepts a *n* x *n* square matrix, in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object, as input.

**Output:** This function returns a *n* x 2*n* rectangular block matrix in the form of a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object. The first *n* x *n* block is the *Q* component of the factorization and the second *n* x *n* block is the *R* component of the factorization.

**Usage/Example:** The f ... 

**Implementation/Code:**

```cpp
array2D QRDecomp_CGS(array2D A) {

	int m = A.getRows();
	int n = A.getCols();

	if (n != m) {
		throw "QRDecomp_CGS: Matrix Not Square";
	}

	array2D QR;
	QR.allocateMem(n, 2 * n);

	double rjj = 0.0;

	double dotNum = 0.0;
	double dotDen = 0.0;

	//This loop calculates the Q portion of the QR factorization.
	//It does so using the Classical Gram-Schmidt procedure.
	for (int j = 0; j < n; j++) {

		for (int k = 0; k < n; k++) {
			QR(k, j) = A(k, j);
		}

		for (int i = 0; i < j; i++) {

			//Calculate the dot product of the jth and ith column of Q.
			//Then use that product to orthogonalize the jth column of Q.

			dotNum = 0.0;
			dotDen = 0.0;

			for (int k = 0; k < n; k++) {
				dotNum = dotNum + QR(k, i) * A(k, j);
				dotDen = dotDen + QR(k, i) * QR(k, i);
			}

			for (int k = 0; k < n; k++) {
				QR(k, j) = QR(k, j) - (dotNum / dotDen) * QR(k, i);
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