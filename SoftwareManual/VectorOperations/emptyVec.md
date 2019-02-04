# Software Manual

**Routine Name:** emptyVec

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:** 

```cpp
array1D emptyVec(int l) {

	array1D vec;

	vec.allocateMem(l);

	for (int i = 0; i < l; i++) {
		vec(i) = 0;
	}

	return vec;
}
```

**Last Modified:** February/2019