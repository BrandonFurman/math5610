# Software Manual

**Routine Name:** absErrVecInfNorm

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:** 

```cpp
double absErrVecInfNorm(array1D vec1, array1D vec2) {

	int n1 = vec1.getLength();
	int n2 = vec2.getLength();

	if (n1 != n2) {
		throw std::invalid_argument("absErrVecInfNorm: Incompatible Vector Sizes");
	}

	double vi = 0.0;
	double max = abs(vec1(0) - vec2(0));

	for (int i = 0; i < n1; i++) {

		vi = abs(vec1(i) - vec2(i));

		if (vi > max) max = vi;

	}

	return max;
}
```

**Last Modified:** February/2019