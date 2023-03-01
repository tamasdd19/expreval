#include <iostream>
#include "../include/expreval.h"

int main()
{
    int result = expreval::evaluate("2+3.4*(-5.2+10.0)");
   // float test = expreval::str_to_float("123.4");
   std::cout << "\n";
    std::cout << expreval::str_to_float("123.4562");
    return 0;
}