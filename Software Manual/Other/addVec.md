# Math 5610 Computational Linear Algebra Software Manual

**Routine Name:** addVec

**Author:** Brandon Furman

**Language:** C++

**Description/Purpose:** This routine will add two vectors of the same length element-wise. Suppose the first input is a vector with entries v1 = [1,2,3] and the second input has entries v2 = [4,5,6]. Then this routine returns a vector with entries v3 = [5,7,9]. This routine also checks to ensure that both vectors are of the same length and throws an exception if they are not.

**Input:** This routine accepts two elements of the class "array1D". Both inputs are passed by reference.

**Output:** This routine returns an element of the class "array1D"

**Usage/Example:** Usage is straight forward. The following code

    int main() {

	    array1D vec1(3), vec2(3), vec3;

	    vec1.index[0] = 1; vec1.index[1] = 2; vec1.index[2] = 3;
	    std::cout << "vec1 = "; vec1.print();

	    vec2.index[0] = 4; vec2.index[1] = 5; vec2.index[2] = 6;
	    std::cout << "vec2 = "; vec2.print();

	    vec3 = addVec(vec1, vec2);
	    std::cout << "vec3 = "; vec3.print();

    	return 0;
    }

Would output the following to the console:

    vec1 = [1, 2, 3]
    vec2 = [4, 5, 6]
    vec3 = [5, 7, 9]

**Implementation/Code:** The following is the code for addVec.

    array1D addVec(const array1D& vec1, const array1D& vec2) {

    	//Gets the length of both inputs.
    	int n1 = vec1.length;
    	int n2 = vec2.length;

    	//Throws an exception if they are not the same length
    	if (n1 != n1) {
	    	throw "addVec: Incompatible Vector Sizes";
	    }

	    //Allocates space for vector to be returned.
	    array1D vec = emptyVec(n1);

	    //Each entry in the new vector is the sum of the enrties of the input vectors
	    for (int i = 0; i < n1; i++) {
		    vec.index[i] = vec1.index[i] + vec2.index[i];
	    }

	    return vec;
    }

**Last Modified:** February/2019