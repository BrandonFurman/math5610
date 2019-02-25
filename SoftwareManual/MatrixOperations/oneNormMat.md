# Software Manual

**Routine Name:** oneNormMat

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:** 

```cpp
double oneNormMat(array2D& mat) {

	int m = mat.getRows();
	int n = mat.getCols();

	double sum = 0.0;
	double max = 0.0;

	for (int j = 0; j < n; j++) {

		for (int i = 0; i < m; i++) {
			sum += abs(mat(i,j));
		}

		if (sum > max) max = sum;
		sum = 0.0;
	}

	return max;
}
```

**Last Modified:** February/2019