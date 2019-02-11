# Software Manual

**Routine Name:** oneNormVec

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function computes the 1-norm of an arbitrary vector with real number entries.

**Input:** This function accepts a vector, in the form of an array1D object, as an input. This input is passed by reference.

**Output:** This function returns a double-precision number that is equal to the 1-norm of the input.

**Usage/Example:** Usage of this function is straightforward. For example, the following code:

```cpp
double oneNorm;
array1D vec;

vec = emptyVec(3);
vec(0) = 1; vec(1) = 2; vec(2) = 3;

oneNorm = oneNormVec(vec);

std::cout << oneNorm;
```
outputs the following to the console:
```
6
```

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