#include <iostream>
#include <vector>
#include <array>
#include <time.h>
#include <chrono> 

using namespace std::chrono;

class Matrix {
private:


public:

};


std::vector<std::vector<double>> randMat(int n, int m) {

	std::vector<std::vector<double>> mat(n,std::vector<double>(m,0));

	//srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mat[i][j] = (double)rand() / (double)RAND_MAX;
		}
	}

	return mat;
}


std::vector<std::vector<double>> multMat(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2, int n, int m, int p) {

	std::vector<std::vector<double>> mat3(n, std::vector<double>(p, 0));

	double sum = 0.0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < m; k++) {
				sum = sum + mat1[i][k] * mat2[k][j];
			}
			mat3[i][j] = sum;
			sum = 0.0;
		}
	}

	return mat3;
}



double ** randMat2(int n, int m) {

	double **mat = new double*[n];

	for (int i = 0; i < n; i++) {

		mat[i] = new double[m];

		for (int j = 0; j < m; j++) {
			mat[i][j] = (double)rand() / (double)RAND_MAX;
		}
	}

	return mat;
}

double **multMat2(double **mat1, double **mat2, int n, int m, int p) {

	double **mat3 = new double *[n];

	double sum = 0.0;

	for (int i = 0; i < n; i++) {

		mat3[i] = new double[p];

		for (int j = 0; j < p; j++) {
			for (int k = 0; k < m; k++) {
				sum = sum + mat1[i][k] * mat2[k][j];
			}
			mat3[i][j] = sum;
			sum = 0.0;
		}
	}

	return mat3;
}



int main() {

	int n = 100;
	int m = 100;
	int p = 100;

	
	std::vector<std::vector<double>> mat1, mat2, mat3;

	mat1 = randMat(n, m);
	mat2 = randMat(m, p);

	mat1.shrink_to_fit();
	mat2.shrink_to_fit();

	auto start = high_resolution_clock::now();

	mat3 = multMat(mat1, mat2, n, m, p);

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	std::cout << duration.count() << std::endl;




	double **mat4;
	double **mat5;
	double **mat6;
	
	mat4 = randMat2(n, m);
	mat5 = randMat2(m, p);

	start = high_resolution_clock::now();

	mat6 = multMat2(mat4, mat5, n, m, p);

	stop = high_resolution_clock::now();

	duration = duration_cast<microseconds>(stop - start);

	std::cout << duration.count() << std::endl;

	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << mat4[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			std::cout << mat5[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			std::cout << mat6[i][j] << " ";
		}
		std::cout << std::endl;
	}
	*/

	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m1; j++) {
			std::cout << mat1[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < p; j++) {
			std::cout << mat2[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			std::cout << mat3[i][j] << " ";
		}
		std::cout << std::endl;
	}
	*/
}