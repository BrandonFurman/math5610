#include <iostream>

double absErr(double x, double y) {

	return abs(y - x);

}

int main()
{
	double x = (double)rand() / RAND_MAX;
	double y = (double)rand() / RAND_MAX;

	std::cout << "The absolute error in approximating " << x << " by " << y << " is given by " << absErr(x,y) << std::endl;
}