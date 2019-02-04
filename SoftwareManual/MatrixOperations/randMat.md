# Math 5610 Computational Linear Algebra Software Manual

**Routine Name:** randMat

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This routine returns a matrix, in the form of an array2D object, whose entries have been randomized. 

**Input:** This routine accepts two integers, *m* and *n*, as inputs. *m* is the number of rows in the matrix and *n* is the number of columns.

**Output:** This routine outputs a matrix with *m* rows and *n* columns whose entries have been randomized to between 0 and 1.

**Usage/Example:** Usage is straightforward. The following code

```cpp
array2D mat;

mat = randMat(2, 3);

for (int i = 0; i < 2; i++) {
	for (int j = 0; j < 3; j++) {
		std::cout << mat(i, j) << " ";
	}
		std::cout << std::endl;
}
```
outputs the following to console:
```cpp
0.00125126 0.563585 0.193304
0.808741 0.585009 0.479873
```

**Implementation/Code:** The following is the code for randMat(int m, int n):

```cpp
array2D randMat(int m, int n) {

	array2D mat;

	mat.allocateMem(m, n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			mat(i, j) = (double)rand() / (double)RAND_MAX;
		}
	}

	return mat;
}
```

**Last Modified:** February/2019