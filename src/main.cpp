#include <iostream>
#include "../include/expreval.h"
#include <thread>
#include <chrono>

int main()
{
    std::cout << expreval::evaluate("2+3.4*(-5.2+10.0)-1");
    std::cout << '\n';
    std::cout << expreval::evaluate("1+(1+(2+3))*100");
    std::cout << '\n';
    std::cout << expreval::evaluate("2^(1+2)");
    std::cout << '\n';
    std::cout << expreval::evaluate("123");
    std::cout << '\n';
    std::cout << expreval::evaluate("-432");
    std::cout << '\n';
    std::cout <<  expreval::evaluate("2+3*(-5+10)");
    return 0;
}