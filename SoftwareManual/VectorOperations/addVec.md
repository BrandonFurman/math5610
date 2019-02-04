# Software Manual

**Routine Name:** addVec

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This routine will add two vectors of the same length element-wise. Suppose the first input is a vector with entries v1 = [1,2,3] and the second input has entries v2 = [4,5,6]. Then this routine returns a vector with entries v3 = [5,7,9]. This routine also checks to ensure that both vectors are of the same length and throws an exception if they are not.

**Input:** This routine accepts two elements of the class "array1D". Both inputs are passed by reference.

**Output:** This routine returns an element of the class "array1D" whose entries are the sum of the corresponding entries of the inputs.

**Usage/Example:** Usage is straight forward. The following code
```cpp
	array1D vec1(3), vec2(3), vec3;

	vec1(0) = 1; vec1(1) = 2; vec1(2) = 3;
	vec2(0) = 4; vec2(1) = 5; vec2(2) = 6;

	vec3 = addVec(vec1, vec2);

	std::cout << "vec3 = "; vec3.print();
```

Would output the following to the console:
```
    vec3 = [5, 7, 9]
```
**Implementation/Code:** The following is the code for addVec.

```cpp
array1D addVec(array1D& vec1, array1D& vec2) {

	//Gets the length of both inputs.
	int l1 = vec1.getLength();
	int l2 = vec2.getLength();

	//Throws an exception if they are not the same length
	if (l1 != l2) {
		throw "addVec: Incompatible Vector Sizes";
	}

	//Allocates space for vector to be returned.
	array1D vec = emptyVec(l1);

	//Each entry in the new vector is the sum of the enrties of the input vectors
	for (int i = 0; i < l1; i++) {
		vec(i) = vec1(i) + vec2(i);
	}

	return vec;
}
```

**Last Modified:** February/2019