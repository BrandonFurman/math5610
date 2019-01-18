#include <iostream>

double dmaceps() {

	double one = 1.0;
	double seps = 1.0;
	double appone = one + seps;

	while (abs(appone - one) != 0.0) {
		seps = seps / 2.0;
		appone = one + seps;
	}

	return seps;
}

int main()
{
	std::cout << dmaceps() << std::endl;
}