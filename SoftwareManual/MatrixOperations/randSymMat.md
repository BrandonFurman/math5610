# Software Manual

**Routine Name:** randSymMat

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function generates a symmetric matrix whose entries are random values between 0 and 1.

**Input:** This function accepts one integer as input. This integer designates both the number of columns and the number of rows.

**Output:** This function returns a symmetric matrix, in the form of an [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object, whose entries have been set to random values between 0 and 1.

**Usage/Example:** Usage of this function is straightforward. The following code

```cpp
int m,n;
array2D mat;

m = 2; n = 3;

mat = randSymMat(m,n);

for (int i = 0; i < m; i++) {
	for (int j = 0; j < n; j++) {
		std::cout << mat(i,j);
	}
	std::cout << std::endl;
}
```
outputs the following to the console:
```
0.00125126 0.563585 0.193304
0.563585 0.808741 0.585009
0.193304 0.585009 0.479873
```
Note that the entries are random, so these values may change upon running the code again.

**Implementation/Code:** 

```cpp
array2D randSymMat(int m) {

	//Creates a new array2D object and
	//allocates memory for it
	array2D mat;
	mat.allocateMem(m, m);

	double tmp = 0.0;

	//Loops through the lower triangular portion
	//of the matrix and sets each element equal
	//to a random number.
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			tmp = (double)rand() / (double)RAND_MAX;
			mat(i, j) = tmp;
			mat(j, i) = tmp;
		}
	}

	return mat;
}
```

**Last Modified:** February/2019