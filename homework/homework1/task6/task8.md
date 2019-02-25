## Machine Precision Shared Library

A shared library containing code to calculate machine precision can be found [here](https://github.com/BrandonFurman/math5610/tree/master/homework/homework1/task6). This shared library can be used by compiling using gpp,
```
gpp MachinePrecision.a Code.cpp
```
where Code.cpp is some code containing calls to the functions [smaceps](https://brandonfurman.github.io/math5610/SoftwareManual/OtherRoutines/smaceps) or [dmaceps](https://brandonfurman.github.io/math5610/SoftwareManual/OtherRoutines/dmaceps). For instance, the following code
```cpp
#include <iostream>

void main() {

std::cout << smaceps() << std::endl;

std::cout << dmaceps() << std::endl;

}
```
when compiled as above outputs the following to console:
```

```