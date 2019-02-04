# Software Manual

**Class Name:** array2D

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This code defines a new class called "array2D". This class is designed to be matrix-like, and uses a syntax similar to MATLAB. Memory for a matrix is allocated and deallocated dynamically with little input required from the user.

**Usage/Example:** An object is created with

```cpp
array2D mat;
```
The only constructor is the default constructor. The size of the matrix is defined using the allocateMem(int m, int n) member function. For example,
```cpp
array2D mat;

mat.allocateMem(2,3)
```
creates a matrix with 2 rows and 3 columns. An element of the matrix can then be accessed using mat(i,j) syntax. For example,
```cpp
array2D mat;

mat.allocateMem(2,3)

mat(0,1) = 1.5;

std::cout << mat(0,1);
```
outputs the following to the console:
`
1.5
`
The only other member functions that should be explicitly called are getRows() and getCols(). These two functions allow access to the number of rows and columns in the matrix.

**Implementation/Code:**

```cpp
class array2D {
private:

	int nrows;
	int ncols;
	double* index;

public:
	
	array2D() //DEFAULT CONSTRUCTOR
	{
		nrows = 0;
		ncols = 0;
		index = NULL;
	}

	void allocateMem(int m, int n) {
		if (index == NULL) {
			nrows = m;
			ncols = n;
			index = new double[nrows*ncols];
		}
		else {
			nrows = m;
			ncols = n;
			delete[] index;
			index = new double[nrows*ncols];
		}
	}

	int getRows() { return nrows; }

	int getCols() { return ncols; }

	array2D(const array2D& oldMat) //REDEFINITION OF THE COPY CONSTRUCTOR
	{
		nrows = oldMat.nrows;
		ncols = oldMat.ncols;
		index = new double[nrows*ncols];
		memcpy(&index[0], &oldMat.index[0], sizeof(double)*nrows*ncols);
	}

	array2D(array2D&& otherMat) //REDEFINITION OF THE MOVE CONSTRUCTOR
	{
		nrows = otherMat.nrows;
		ncols = otherMat.ncols;
		index = otherMat.index;
		otherMat.index = nullptr;
	}

	array2D& operator=(const array2D& oldMat) //REDEFINITION OF THE COPY ASSIGNMENT OPERATOR
	{
		//Check for the situation of mat == mat.
		if (&oldMat == this) {
			return *this;
		}
		else {
			//Check if the dimensions of the matrices are equal.
			//If they are, then just do a memcpy from the old matrix to the new matrix.
			if (nrows == oldMat.nrows && ncols == oldMat.ncols) { 
				memcpy(&index[0], &oldMat.index[0], sizeof(double)*nrows*ncols);

				return *this;
			}
			else {
				delete[] index;

				nrows = oldMat.nrows;
				ncols = oldMat.ncols;
				index = new double[nrows*ncols];

				memcpy(&index[0], &oldMat.index[0], sizeof(double)*nrows*ncols);

				return *this;
			}
		}
	}

	array2D& operator=(array2D&& otherMat) //REDEFINITION OF THE MOVE ASSIGNMENT OPERATOR
	{
		if (&otherMat == this) { //Check for the situation of mat == mat.
			return *this;
		}
		else {
			delete[] index; //Deallocates all memory currently associated with the matrix.

			nrows = otherMat.nrows; 
			ncols = otherMat.ncols;
			index = otherMat.index;

			otherMat.index = nullptr;

			return *this;
		}
	}

	double& operator()(int &i, int &j) //This allows the array to be indexed like Mat(i,j).
	{
		return index[i * ncols + j];
	}

	~array2D() //DECONSTRUCTOR
	{
		if (index != NULL) { //Check if the memory has already been deallocated
			delete[] this->index; //Deallocate the memory
			index = NULL; //Set the pointer to null so the memory cant be deallocated again.
			nrows = 0;
			ncols = 0;
		}
	}
};

```

**Last Modified:** February/2019