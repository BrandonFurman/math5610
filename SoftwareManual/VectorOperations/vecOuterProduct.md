# Software Manual

**Routine Name:** vecOuterProduct

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function returns the outer product of two vectors.

**Input:** This function accepts two [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) objects of length *m* and *n* as inputs.

**Output:** This function returns a [array2D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array2D) object that is the outer product of the inputs. This array has dimension *m* x *n*.

**Usage/Example:** Usage of this function is relatively straightforward. Be aware that the order of the inputs affects the output. The following code
```cpp
int m = 3;
int n = 4;

array1D vec1, vec2;
array2D mat;

vec1 = emptyVec(m);
vec2 = emptyVec(n);

vec1(0) = 2; vec1(1) = 3; vec1(2) = 4;
vec2(0) = 5; vec2(1) = 6; vec2(2) = 7; vec2(3) = 8;

mat = vecOuterProduct(vec1, vec2);

for (int i = 0; i < m; i++) {
	for (int j = 0; j < n; j++) {
		std::cout << mat(i, j) << " ";
	}
	std::cout << std::endl;
}
```
outputs the following to the console
```
10 12 14 16
15 18 21 24
20 24 28 32
```
However, if the order of the inputs is reversed then the following is output to the console.
```
10 15 20 12
12 18 24 14
14 21 28 16
```

**Implementation/Code:** This function is implemented as follows:

```cpp
array2D vecOuterProduct(array1D& vec1, array1D& vec2) {

	int m = vec1.getLength();
	int n = vec2.getLength();

	array2D mat;

	mat.allocateMem(m, n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			mat(i, j) = vec1(i)*vec2(j);
		}
	}

	return mat;
}
```

**Last Modified:** March/2019