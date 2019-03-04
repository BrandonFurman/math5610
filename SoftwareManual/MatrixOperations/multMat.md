# Software Manual

**Routine Name:** multMat

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function computes the product of two matrices with equal inner dimension.

**Input:** This function accepts two matrices, in the form of [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) objects, as input. Both inputs are passed by reference.

**Output:** This function outputs an array2D object that is the matrix product of the inputs.

**Usage/Example:** Usage of this function is relatively straight forward. Note that matrix multiplication is not commutative, hence the order of the inputs matter. An example of this functions usage is shown below:
```cpp
array2D mat1, mat2, mat3, mat4;

mat1 = emptyMat(3,3);
mat1(0, 0) = 1; mat1(0, 1) = 2; mat1(0, 2) = 3;
mat1(1, 0) = 4; mat1(1, 1) = 5; mat1(1, 2) = 4;
mat1(2, 0) = 3; mat1(2, 1) = 2; mat1(2, 2) = 1;

mat2 = emptyMat(3, 3);
mat2(0, 0) = 1; mat2(0, 1) = 2; mat2(0, 2) = 3;
mat2(1, 0) = 3; mat2(1, 1) = 1; mat2(1, 2) = 2;
mat2(2, 0) = 2; mat2(2, 1) = 3; mat2(2, 2) = 1;

mat3 = multMat(mat1, mat2);
mat4 = multMat(mat2, mat1);

for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
		std::cout << mat3(i, j) << " ";
	}
	std::cout << std::endl;
}

for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
		std::cout << mat4(i, j) << " ";
	}
	std::cout << std::endl;
}
```
This code results in the following output to the console:
```
13 13 10
27 25 26
11 11 14

18 18 14
13 15 15
17 21 19
```

**Implementation/Code:**

```cpp
array2D multMat(array2D& mat1, array2D& mat2) {

	int m = mat1.getRows();
	int n1 = mat1.getCols();
	int n2 = mat2.getRows();
	int p = mat2.getCols();

	if (n1 != n2) {
		throw "multMat: Incompatible Matrix Sizes";
	}

	array2D mat;

	mat.allocateMem(m, p);

	double sum = 0.0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < n1; k++) {
				sum = sum + mat1(i,k) * mat2(k,j);
			}
			mat(i,j) = sum;
			sum = 0.0;
		}
	}

	return mat;
}
```

**Last Modified:** February/2019