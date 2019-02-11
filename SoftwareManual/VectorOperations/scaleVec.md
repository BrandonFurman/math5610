# Software Manual

**Routine Name:** scaleVec

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This function returns a scalar multiple of a given vector.

**Input:** This function accepts a double-precision number and a array1D object as inputs. The array1D object is passed by reference.

**Output:** This function returns an array1D object whose elements have been multiplied by the input scalar.

**Usage/Example:** The first input should be a double precision number and the second input should be an array1D object. Otherwise, usage is straightforward. The following code:

```cpp
double c;
c = 2.5;

array1D vec;
vec = emptyVec(3);
vec(0) = 1; vec(1) = 2; vec(2) = 3;

vec = scaleVec(c,vec);

std::cout << vec(0) << std::endl;
std::cout << vec(1) << std::endl
std::cout << vec(2) << std::endl
```
outputs the following to console:
```
2.5
5.0
7.5
```

**Implementation/Code:**

```cpp
array1D scaleVec(double c, array1D& vec) {

	//Get the length of the input vector
	int l = vec.getLength();

	//Create a new vector and allocate memory for it
	array1D nVec;
	nVec = emptyVec(l); 

	//Set each element of the new vector equal to the
	//corresponding element of the input vector
	//multiplied by the input scalar
	for (int i = 0; i < l; i++) {
		nVec(i) = c*vec(i);
	}

	//Return the new vector
	return nVec;
}
```

**Last Modified:** February/2019