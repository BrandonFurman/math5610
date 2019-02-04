# Software Manual

**Routine Name:** dotProduct

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:**

```cpp
double dotProduct(array1D& vec1, array1D& vec2) {

	//Gets the length of both inputs.
	int l1 = vec1.getLength();
	int l2 = vec2.getLength();

	//Throws an exception if they are not the same length
	if (l1 != l2) {
		throw "dotProduct: Incompatible Vector Sizes";
	}

	double sum = 0.0;

	for (int i = 0; i < l1; i++) {
		sum = vec1(i) * vec2(i);
	}

	return sum;
}
```

**Last Modified:** February/2019