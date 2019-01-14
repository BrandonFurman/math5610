// MachinePrecision.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

float smaceps();
float dmaceps();

int main()
{
	std::cout << smaceps() << std::endl;

	std::cout << dmaceps() << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


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

float dmaceps() {

	double one = 1.0;
	double seps = 1.0;
	double appone = one + seps;

	while (abs(appone - one) != 0.0) {
		seps = seps / 2.0;
		appone = one + seps;
	}

	return seps;
}