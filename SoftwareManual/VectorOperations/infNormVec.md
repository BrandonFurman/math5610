# Software Manual

**Routine Name:** infNormVec

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function computes the infinity-norm of an arbitrary vector with real number entries.

**Input:** This function accepts a vector, in the form of an [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) object, as an input. This input is passed by reference.

**Output:** This function returns a double-precision number that is equal to the infinity-norm of the input.

**Usage/Example:** Usage of this function is straightforward. For example, the following code:

```cpp
double infNorm;
array1D vec;

vec = emptyVec(3);
vec(0) = 1; vec(1) = 2; vec(2) = 3;

infNorm = infNormVec(vec);

std::cout << infNorm;
```
outputs the following to the console:
```
3
```

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