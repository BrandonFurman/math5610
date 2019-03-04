# Software Manual

**Routine Name:** crossProduct

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function calculates the cross-product of two vectors of length three.

**Input:** This function accepts two vectors, in the form of [array1D](https://brandonfurman.github.io/math5610/SoftwareManual/DataStructures/array1D) objects, as inputs. Both inputs are passed by reference.

**Output:** This function returns a of length three that is the cross-product of the inputs.

**Usage/Example:** Usage of this function is relatively straight forward. Note that the cross-product is anti-commutative, hence the order of the inputs matter. An example of this functions usage is shown below:
```cpp
array1D vec1, vec2, vec3, vec4;

	vec1 = emptyVec(3);
	vec1(0) = 1; vec1(1) = 3; vec1(2) = 5;

	vec2 = emptyVec(3);
	vec2(0) = 2; vec2(1) = 4; vec2(2) = 6;

	vec3 = crossProduct(vec1, vec2);
	vec4 = crossProduct(vec2, vec1);

	for (int i = 0; i < 3; i++) {
		std::cout << vec3(i) << " ";
	}

	std::cout << std::endl;

	for (int i = 0; i < 3; i++) {
		std::cout << vec4(i) << " ";
	}
```
This code results in the following output to the console:
```
-2  4 -2
 2 -4  2
```

**Implementation/Code:**

```cpp
array1D crossProduct(array1D& vec1, array1D& vec2) {

	int l1 = vec1.getLength();
	int l2 = vec2.getLength();

	if (l1 != 3 || l2 != 3) {
		throw "crossProduct: Incompatible Vector Sizes";
	}

	array1D vec3;

	vec3.allocateMem(3);

	vec3(0) = vec1(1)*vec2(2) - vec1(2)*vec2(1);
	vec3(1) = vec1(2)*vec2(0) - vec1(0)*vec2(2);
	vec3(2) = vec1(0)*vec2(1) - vec1(1)*vec2(0);

	return vec3;
}
```

**Last Modified:** February/2019