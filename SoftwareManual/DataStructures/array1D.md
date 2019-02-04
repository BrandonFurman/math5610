# Software Manual

**Class Name:** array1D

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:**

**Input:**

**Output:**

**Usage/Example:**

**Implementation/Code:** 

```cpp
struct array1D {
private:

	double* index;
	int length;

public:

	array1D() //DEFAULT CONSTRUCTOR
	{
		length = 0;
		index = NULL;
	}

	void allocateMem(int l) {
		if (index == NULL) {
			length = l;
			index = new double[length];
		}
		else {
			length = l;
			delete[] index;
			index = new double[length];
		}
	}

	int getLength()
	{
		return length;
	}

	array1D(const array1D& oldVec) //COPY CONSTRUCTOR
	{
		length = oldVec.length;
		index = new double[oldVec.length];
		memcpy(&index[0], &oldVec.index[0], sizeof(double)*length);
	}

	array1D(array1D&& otherVec) //MOVE CONSTRUCTOR
	{
		length = otherVec.length;
		index = otherVec.index;
		otherVec.index = nullptr;
	}

	array1D& operator=(const array1D& otherVec) //ASSIGNMENT OPERATOR
	{
		if (&otherVec == this) {
			return *this;
		}
		else {
			delete[] index;

			length = otherVec.length;
			index = new double[length];

			memcpy(&index[0], &otherVec.index[0], sizeof(double)*length);

			return *this;
		}
	}

	array1D& operator=(array1D&& otherVec)
	{
		if (&otherVec == this) {
			return *this;
		}
		else {
			delete[] index;

			length = otherVec.length;
			index = otherVec.index;

			otherVec.index = nullptr;

			return *this;
		}
	}

	double& operator()(int i) {
		return index[i];
	}

	~array1D() //DECONSTRUCTOR
	{
		if (index != NULL) {
			delete[] this->index;
			index = NULL;
			length = 0;
		}
	}
};
```

**Last Modified:** February/2019