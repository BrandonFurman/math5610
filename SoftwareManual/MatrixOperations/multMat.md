# Software Manual

**Routine Name:** multMat

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:** 

```cpp
array2D multMat(array2D& mat1, array2D& mat2) {

	int m = mat1.getRows();
	int n = mat1.getCols();
	int p = mat2.getCols();

	array2D mat;

	mat.allocateMem(m, p);

	double sum = 0.0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < n; k++) {
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