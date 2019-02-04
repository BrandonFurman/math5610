# Software Manual

**Routine Name:** infNormVec

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:**

```cpp
double infNormVec(array1D vec) {

	int n = vec.getLength();

	double vi = 0.0;
	double max = abs(vec(0));

	for (int i = 0; i < n; i++) {
		
		vi = abs(vec(i));

		if (vi > max) max = vi;

	}

	return max;
}
```

**Last Modified:** February/2019