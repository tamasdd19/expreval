#include <iostream>
#include "../include/expreval.h"

int main()
{
    int result = expreval::evaluate("2+3.4*(-5.2+10.0)");
    return 0;
}