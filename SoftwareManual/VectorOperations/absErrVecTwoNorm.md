# Software Manual

**Routine Name:** absErrVecTwoNorm

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:** 

```cpp
double absErrVecTwoNorm(array1D vec1, array1D vec2) {

	int n1 = vec1.getLength();
	int n2 = vec2.getLength();

	if (n1 != n2) {
		throw std::invalid_argument("absErrVecTwoNorm: Incompatible Vector Sizes");
	}

	double s = 0.0;
	double sum = 0.0;

	for (int i = 0; i < n1; i++) {

		s = vec1(i) - vec2(i);

		sum += s * s;

	}

	sum = sqrt(sum);

	return sum;
}
```

**Last Modified:** February/2019