# Software Manual

**Routine Name:** crossProduct

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:**

```cpp
array1D crossProduct(array1D& vec1, array1D& vec2) {

	int l1 = vec1.getLength();
	int l2 = vec2.getLength();

	if (l1 != 3 || l2 != 3) {
		throw "crossProduct: Incompatible Vector Sizes";
	}

	array1D nVec;

	nVec.allocateMem(3);

	nVec(0) = vec1(1)*vec2(2) - vec1(2)*vec2(1);
	nVec(1) = vec1(2)*vec2(0) - vec1(0)*vec2(3);
	nVec(2) = vec1(0)*vec2(1) - vec1(1)*vec2(0);

	return nVec;
}
```

**Last Modified:** February/2019