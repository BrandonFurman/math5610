#include <iostream>

float smaceps() {

	float one = 1.0;
	float seps = 1.0;
	float appone = one + seps;

	int ipow = 0;

	while (abs(appone - one) != 0.0f) {
		seps = seps / 2.0f;
		appone = one + seps;
		ipow = ipow + 1;
	}

	return seps;
}

int main()
{
	std::cout << smaceps() << std::endl;
}