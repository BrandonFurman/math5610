# Software Manual

**Routine Name:** randVec

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:** 

```cpp
array1D randVec(int l) {

	array1D vec;
	
	vec.allocateMem(l);

	for (int i = 0; i < l; i++) {
		vec(i) = (double)rand() / (double)RAND_MAX;
	}

	return vec;
}
```

**Last Modified:** February/2019