# Software Manual

**Routine Name:** smaceps

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This routine will compute the single precision value for the machine epsilon or the number of digits
in the representation of real numbers in single precision. This is a routine for analyzing the behavior of any computer. This
usually will need to be run one time for each computer.

**Input:** There are no inputs needed for this routine.

**Output:** This routine returns a single precision value for the number of decimal digits that can be represented on the
computer being queried.

**Usage/Example:** The routine has no arguments and only outputs the default machine precision in terms of a decimal number. For example, the following code:
```cpp
std::cout << smaceps();
```
outputs the following to the console:
```
5.96046e-08
```

**Implementation/Code:** The following is the code for smaceps()

```cpp
float smaceps() {
	//Set up storage for the algorithm and initialize
	//variables to compute the machine value near 1.0

	float one = 1.0;
	float seps = 1.0;
	float appone = one + seps;

	//Loop, dividing by 2 each time to determine when the difference
	//between one and the approximation is zero in single precision

	while (abs(appone - one) != 0.0f) {
		seps = seps / 2.0f;
		appone = one + seps;
	}

	return seps;
}
```

**Last Modified:** January/2019
