# Math 5610 Computational Linear Algebra Software Manual

**Routine Name:**           smaceps

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This routine will compute the single precision value for the machine epsilon or the number of digits
in the representation of real numbers in single precision. This is a routine for analyzing the behavior of any computer. This
usually will need to be run one time for each computer.

**Input:** There are no inputs needed for this routine.

**Output:** This routine returns a single precision value for the number of decimal digits that can be represented on the
computer being queried.

**Usage/Example:**

The routine has two arguments needed to return the values of the precision in terms of the smallest number that can be
represented. Since the code is written in terms of a Fortran subroutine, the values of the machine machine epsilon and
the power of two that gives the machine epsilon. Due to implicit Fortran typing, the first argument is a single precision
value and the second is an integer.

      call smaceps(sval, ipow)
      print *, ipow, sval

Output from the lines above:

      24   5.96046448E-08

The first value (24) is the number of binary digits that define the machine epsilon and the second is related to the
decimal version of the same value. The number of decimal digits that can be represented is roughly eight (E-08 on the
end of the second value).

**Implementation/Code:** The following is the code for smaceps()

    float smaceps() {
    	\\Set up storage for the algorithm and initialize
		\\variables to compute the machine value near 1.0

		float one = 1.0;
		float seps = 1.0;
		float appone = one + seps;

		\\Loop, dividing by 2 each time to determine when the difference
		\\between one and the approximation is zero in single precision

		while (abs(appone - one) != 0.0f) {
			seps = seps / 2.0f;
			appone = one + seps;
		}

		return seps;
    }

**Last Modified:** January/2019
