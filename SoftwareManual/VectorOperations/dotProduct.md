# Software Manual

**Routine Name:** dotProduct

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function returns the dot product of two vectors of equal length.

**Input:** This function accepts two vectors, in the form of [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) objects, as inputs. Both inputs are passed by reference.

**Output:** This function outputs a double-precision number that is the dot product of the inputs.

**Usage/Example:** Usage of this function is straightforward. An example of this functions usage is shown below:
```cpp
array1D vec1, vec2;

vec1 = emptyVec(3);
vec1(0) = 1; vec1(1) = 3; vec1(2) = 5;

vec2 = emptyVec(3);
vec2(0) = 2; vec2(1) = 4; vec2(2) = 6;

double dotProd = dotProduct(vec1, vec2);

std::cout << dotProd;
```
This code results in the following output to the console:
```
44
```

**Implementation/Code:**

```cpp
double dotProduct(array1D& vec1, array1D& vec2) {

	//Gets the length of both inputs.
	int n1 = vec1.getLength();
	int n2 = vec2.getLength();

	//Throws an exception if they are not the same length
	if (n1 != n2) {
		throw "dotProduct: Incompatible Vector Sizes";
	}

	double sum = 0.0;

	for (int i = 0; i < n1; i++) {
		sum += vec1(i) * vec2(i);
	}

	return sum;
}
```

**Last Modified:** February/2019