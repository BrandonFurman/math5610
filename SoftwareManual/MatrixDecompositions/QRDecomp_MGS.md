# Software Manual

**Routine Name:** QRDecomp_MGS

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** 

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:**

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