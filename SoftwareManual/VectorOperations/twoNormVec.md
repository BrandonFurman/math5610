# Software Manual

**Routine Name:** twoNormVec

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:**

```cpp
double twoNormVec(array1D vec) {

	int n = vec.getLength();

	double vi = 0.0;
	double sum = 0.0;

	for (int i = 0; i < n; i++) {

		vi = vec(i);

		sum += vi * vi;

	}

	sum = sqrt(sum);

	return sum;
}
```

**Last Modified:** February/2019