# Software Manual

**Routine Name:** oneNormVec

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:**

```cpp
double oneNormVec(array1D vec) {

	int n = vec.getLength();

	double sum = 0.0;

	for (int i = 0; i < n; i++) {

		sum += abs(vec(i));

	}

	return sum;
}
```

**Last Modified:** February/2019