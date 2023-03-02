**expreval** provides an API to evaluate constant expressions

---
## Setup
clone the repo, include "include/expreval.h" and compile "src/expreval.cpp" in your project
to run tests **git submodule update --init --recursive --remote** and call **make test**

---
## Supported operations
| symbol | meaning |
| :----: | :-----: |
|`+`| Addition |
|`-`| Subtraction |
|`*`| Multiplication |
|`/`| Division |
|`^`| Exponentiation |
## Usage
call the `evaluate` function providing a well formed string as the expression
```cpp
float result = expreval::evaluate("2+3*(-5+10)"); //  17
```
--
## Other
project made by [tamasdd19](https://github.com/tamasdd19) and [Robertkq](https://github.com/Robertkq)   
sort of a university subject we took interest in and made it into a project
