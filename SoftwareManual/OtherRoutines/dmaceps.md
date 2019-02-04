# Math 5610 Computational Linear Algebra Software Manual

**Routine Name:** dmaceps

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This routine will compute the double precision value for the machine epsilon or the number of digits
in the representation of real numbers in single precision. This is a routine for analyzing the behavior of any computer. This
usually will need to be run one time for each computer.

**Input:** There are no inputs needed for this routine.

**Output:** This routine returns a double precision value for the number of decimal digits that can be represented on the
computer being queried.

**Usage/Example:**

**Implementation/Code:** The following is the code for dmaceps()

```C++
float dmaceps() {
	\\Set up storage for the algorithm and initialize
	\\variables to compute the machine value near 1.0

	double one = 1.0;
	double seps = 1.0;
	double appone = one + seps;

	\\Loop, dividing by 2 each time to determine when the difference
	\\between one and the approximation is zero in single precision

	while (abs(appone - one) != 0.0) {
		seps = seps / 2.0;
	appone = one + seps;
	}

	return seps;
}
```

**Last Modified:** January/2019