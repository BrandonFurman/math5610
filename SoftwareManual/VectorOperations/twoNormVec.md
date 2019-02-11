# Software Manual

**Routine Name:** twoNormVec

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function computes the 2-norm of an arbitrary vector with real number entries.

**Input:** This function accepts a vector, in the form of an array1D object, as an input. This input is passed by reference.

**Output:** This function returns a double-precision number that is equal to the 2-norm of the input.

**Usage/Example:** Usage is straightforward. The following code:

```cpp
double twoNorm;
array1D vec;

vec = emptyVec(3);

vec(0) = 1; vec(1) = 2; vec(2) = 3;

twoNorm = twoNormVec(vec);

std::cout << twoNorm;
```
outputs the following to the console:
```
3.74166
```

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