# Software Manual

**Routine Name:** scaleVec

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:**

```cpp
array1D scaleVec(double c, array1D& vec) {

	int l = vec.getLength();

	array1D nVec;

	nVec = emptyVec(l);

	for (int i = 0; i < l; i++) {
		nVec(i) = c*vec(i);
	}

	return nVec;
}
```

**Last Modified:** February/2019