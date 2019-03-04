# Software Manual

**Routine Name:** absErrVecOneNorm

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This method returns the absolute error in the approximation of one vector by another when the 1-norm is used.

**Input:** The function accepts two vectors, in the form of [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) objects, as inputs. Both inputs are passed by reference.

**Output:** This function returns a double-precision number that represents the absolute error in the approximation of the first input by the second input.

**Usage/Example:**
```cpp
array1D vec1, vec2;

vec1 = emptyVec(3);
vec1(0) = 5; vec1(1) = 4; vec1(2) = 3;

vec2 = emptyVec(3);
vec2(0) = 7; vec2(1) = 8; vec2(2) = 9;

double oneNorm = absErrVecOneNorm(vec1, vec2);

std::cout << oneNorm;
```
outputs the following to console:
```
12
```

**Implementation/Code:** 

```cpp
double absErrVecOneNorm(array1D vec1, array1D vec2) {

	int n1 = vec1.getLength();
	int n2 = vec2.getLength();

	if (n1 != n2) {
		throw std::invalid_argument("absErrVecOneNorm: Incompatible Vector Sizes");
	}

	double sum = 0.0;

	for (int i = 0; i < n1; i++) {

		sum += abs(vec1(i) - vec2(i));

	}

	return sum;
}
```

**Last Modified:** February/2019