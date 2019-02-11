# Software Manual

**Routine Name:** absErr

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This routine computes and returns the absolute error in the approximation of a number x by another number y.

**Input:** This routine accepts two double-precision numbers as inputs.

**Output:** This routine returns a double-precision number that is the absolute error between the inputs.

**Usage/Example:** Usage is straightforward. The following code
```cpp
double x, y, e;

x = 2.8;
y = 1.5;

e = absErr(x,y);

std::cout << e;
```
outputs the following to console:
```
1.3
```

**Implementation/Code:** 

```cpp
double absErr(double x, double y) {

	return abs(y - x);

}
```

**Last Modified:** February/2019