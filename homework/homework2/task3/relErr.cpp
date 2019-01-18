#include <iostream>

double relErr(double x, double y) {

	return abs((y - x)/x);

}

int main()
{
	double x = (double)rand() / RAND_MAX;
	double y = (double)rand() / RAND_MAX;

	std::cout << "The relative error in approximating " << x << " by " << y << " is given by " << relErr(x,y) << std::endl;
}