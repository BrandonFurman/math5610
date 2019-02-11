# Software Manual

**Routine Name:** relErr

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This routine computes and returns the relative error in the approximation of a number x by another number y.

**Input:** This routine accepts two double-precision numbers at inputs. The first input, x, is considered the true value, and the second input, y, is considered the approximate value.

**Output:** This routine returns a double-precision number that is the relative error between the first input and second input.

**Usage/Example:** Usage of this routine is straightforward. The only consideration is that the order of the inputs matters. The following code:

```cpp
double x,y,e;

x = 2.8;
y = 1.5;

e = relErr(x,y);

std::cout << e << std::endl;

e = relErr(y,x);

std::cout << e;
```
outputs the following to the console:
```
0.464286
0.866667
```

**Implementation/Code:**

```cpp
double relErr(double x, double y) {

	return abs((y - x)/x);

}
```

**Last Modified:** February/2019