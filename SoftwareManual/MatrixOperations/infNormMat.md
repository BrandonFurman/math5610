# Software Manual

**Routine Name:** infNormMat

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:** 

```cpp
double infNormMat(array2D& mat) {

	int m = mat.getRows();
	int n = mat.getCols();

	double sum = 0.0;
	double max = 0.0;

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n;  j++) {
			sum += abs(mat(i,j));
		}

		if (sum > max) max = sum;
		sum = 0.0;
	}

	return max;
}
```

**Last Modified:** February/2019