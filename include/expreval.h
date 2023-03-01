#ifndef EXPREVAL_H
#define EXPREVAL_H

#include <iostream>
#include <string>
#include <vector>

namespace expreval
{
    struct op
    {
        op(char sym, unsigned int prio);
        char m_symbol;
        unsigned int m_prio;
    };

float str_to_float(const std::string& convert);
int evaluate(const std::string& expression);
}

#endif