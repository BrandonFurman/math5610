The purpose of this page is to test the Classical Gram-Schmidt process on various sizes of Hilbert matrices. The function being used for the following tests is [QRDecomp_CGS](https://brandonfurman.github.io/math5610/SoftwareManual/MatrixDecompositions/QRDecomp_CGS). For Hilbert matrices of size 4 we have the following:

```
The QR decomposition for the Hilbert matrix of size 4 is:
 0.8381 -0.5226  0.1540 -0.0263
 0.4191  0.4417 -0.7278  0.3157
 0.2794  0.5288  0.1395 -0.7892
 0.2095  0.5021  0.6536  0.5261

The product (Q^T)Q is:
 1.0000 -0.0000  0.0000 -0.0000
-0.0000  1.0000  0.0000 -0.0000
 0.0000  0.0000  1.0000 -0.0000
-0.0000 -0.0000 -0.0000  1.0000
```

This data shows that *Q* is orthogonal to within 4 decimal places. For the Hilbert matrix of size 6 we have the following:

```
The QR decomposition for the Hilbert matrix of size 6 is:
 0.8189 -0.5397  0.1893 -0.0482  0.0090 -0.0011
 0.4094  0.3320 -0.7024  0.4489 -0.1617  0.0332
 0.2730  0.4219 -0.1529 -0.5723  0.5854 -0.2322
 0.2047  0.4067  0.2015 -0.3866 -0.4687  0.6189
 0.1638  0.3735  0.3963  0.0915 -0.4285 -0.6961
 0.1365  0.3399  0.4998  0.5574  0.4773  0.2784

The product (Q^T)Q is:
 1.0000 -0.0000  0.0000 -0.0000  0.0000 -0.0000
-0.0000  1.0000  0.0000 -0.0000  0.0000 -0.0000
 0.0000  0.0000  1.0000 -0.0000  0.0000 -0.0000
-0.0000 -0.0000 -0.0000  1.0000  0.0000 -0.0000
 0.0000  0.0000  0.0000  0.0000  1.0000 -0.0002
-0.0000 -0.0000 -0.0000 -0.0000 -0.0002  1.0000
```

This data shows that *Q* is very nearly orthogonal. For the Hilbert matrix of size 8 we have the following:

```
The QR decomposition for the Hilbert matrix of size 8 is:
 0.8091 -0.5467  0.2064 -0.0605  0.0144 -0.0028  0.0003 -0.0003
 0.4046  0.2825 -0.6766  0.4934 -0.2236  0.0713 -0.0143  0.0138
 0.2697  0.3736 -0.2413 -0.4274  0.6135 -0.3854  0.1345 -0.1315
 0.2023  0.3636  0.0543 -0.4519 -0.1109  0.5920 -0.4607  0.4563
 0.1618  0.3354  0.2226 -0.2124 -0.4481  0.0758  0.5776 -0.5794
 0.1349  0.3059  0.3161  0.0579 -0.3360 -0.4428  0.0392 -0.0337
 0.1156  0.2792  0.3669  0.2932  0.0292 -0.3318 -0.5831  0.5842
 0.1011  0.2559  0.3929  0.4813  0.4965  0.4289  0.3071 -0.3101

The product (Q^T)Q is:
 1.0000  0.0000  0.0000 -0.0000  0.0000 -0.0000  0.0000 -0.0000
 0.0000  1.0000 -0.0000  0.0000 -0.0000  0.0000 -0.0000  0.0000
 0.0000 -0.0000  1.0000 -0.0000  0.0000 -0.0000  0.0000 -0.0000
-0.0000  0.0000 -0.0000  1.0000  0.0000 -0.0000  0.0000 -0.0000
 0.0000 -0.0000  0.0000  0.0000  1.0000 -0.0000  0.0003 -0.0004
-0.0000  0.0000 -0.0000 -0.0000 -0.0000  1.0000  0.0260 -0.0340
 0.0000 -0.0000  0.0000  0.0000  0.0003  0.0260  1.0000 -1.0000
-0.0000  0.0000 -0.0000 -0.0000 -0.0004 -0.0340 -1.0000  1.0000
```

This data shows that *Q* is not even close to being orthogonal. For the Hilbert matrix of size 10 we have the following:

```
The QR decomposition for the Hilbert matrix of size 10 is:
 0.8033 -0.5503  0.2165 -0.0683  0.0183 -0.0042  0.0010  0.0010  0.0010  0.0009
 0.4016  0.2544 -0.6577  0.5136 -0.2592  0.0977 -0.0337 -0.0326 -0.0319 -0.0312
 0.2678  0.3461 -0.2809 -0.3399  0.5977 -0.4499  0.2429  0.2379  0.2345  0.2308
 0.2008  0.3390 -0.0159 -0.4411  0.0574  0.4711 -0.5724 -0.5665 -0.5620 -0.5568
 0.1607  0.3136  0.1384 -0.2974 -0.3151  0.3096  0.2697  0.2715  0.2715  0.2705
 0.1339  0.2866  0.2263 -0.1080 -0.3863 -0.1288  0.4162  0.4155  0.4154  0.4154
 0.1148  0.2618  0.2759  0.0658 -0.2638 -0.3766 -0.0067 -0.0096 -0.0105 -0.0107
 0.1004  0.2401  0.3029  0.2094 -0.0461 -0.3289 -0.3787 -0.3828 -0.3856 -0.3886
 0.0893  0.2213  0.3162  0.3230  0.2056 -0.0275 -0.3007 -0.3027 -0.3049 -0.3081
 0.0803  0.2049  0.3213  0.4108  0.4577  0.4505  0.3638  0.3699  0.3743  0.3794

The product (Q^T)Q is:
 1.0000  0.0000 -0.0000  0.0000 -0.0000  0.0000 -0.0000 -0.0000 -0.0000 -0.0000
 0.0000  1.0000 -0.0000  0.0000 -0.0000  0.0000 -0.0000 -0.0000 -0.0000 -0.0000
-0.0000 -0.0000  1.0000  0.0000 -0.0000  0.0000 -0.0000 -0.0000 -0.0000 -0.0000
 0.0000  0.0000  0.0000  1.0000 -0.0000  0.0000 -0.0000 -0.0000 -0.0000 -0.0000
-0.0000 -0.0000 -0.0000 -0.0000  1.0000  0.0000 -0.0008 -0.0007 -0.0007 -0.0006
 0.0000  0.0000  0.0000  0.0000  0.0000  1.0000 -0.0531 -0.0421 -0.0350 -0.0277
-0.0000 -0.0000 -0.0000 -0.0000 -0.0008 -0.0531  1.0000  0.9999  0.9998  0.9996
-0.0000 -0.0000 -0.0000 -0.0000 -0.0007 -0.0421  0.9999  1.0000  1.0000  0.9998
-0.0000 -0.0000 -0.0000 -0.0000 -0.0007 -0.0350  0.9998  1.0000  1.0000  1.0000
-0.0000 -0.0000 -0.0000 -0.0000 -0.0006 -0.0277  0.9996  0.9998  1.0000  1.0000
```

Which once again shows that *Q* is not orthogonal. The reason the Classical Gram-Schmidt procedure fails to produce an orthogonal Q for larger Hilbert matrices is due to a build up of rounding errors. These rounding errors make the algorithm numerically unstable. A better algorithm to use is the Modified Gram-Schmidt Process ([QRDecomp_MGS](https://brandonfurman.github.io/math5610/SoftwareManual/MatrixDecompositions/QRDecomp_MGS)).

This data was generated using the code below:

```cpp
int m = 4;

array2D A,QR;

A = HilbertMat(m);

QR = QRDecomp_CGS(A);

std::cout << std::endl << "The QR decomposition for the Hilbert matrix of size " << m << " is:" << std::endl;

for (int i = 0; i < m; i++) {
	for (int j = 0; j < m; j++) {
		std::cout << std::fixed << std::setw(7) << std::setprecision(4) << QR(i,j) << " ";
	}
	std::cout << std::endl;
}

std::cout << std::endl << "The product (Q^T)Q is:" << std::endl;

double sum = 0.0;
for (int i = 0; i < m; i++) {
	for (int j = 0; j < m; j++) {
		sum = 0.0;
		for (int k = 0; k < m; k++) {
			sum += QR(k, i) * QR(k, j);
		}
		std::cout << std::fixed << std::setw(7) << std::setprecision(4) << sum << " ";
	}
	std::cout << std::endl;
}
```