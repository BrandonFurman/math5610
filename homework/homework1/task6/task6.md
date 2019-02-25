## Machine Precision Shared Library

A shared library containing code to calculate machine precision can be found [here](). This shared library can be used by compiling using gpp,
```
gpp MachinePrecision.a Code.cpp
```
where Code.cpp is some code containing calls to the functions [smaceps]() or [dmaceps](). For instance, the following code
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