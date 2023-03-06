#ifndef EXPREVAL_H
#define EXPREVAL_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <exception>

namespace expreval
{
    struct op
    {
        op(char sym, unsigned int prio);
        char m_symbol;
        unsigned int m_prio;
    };

void _make_this_operation(char symbol, float& lhs, float& rhs);
void _do_operations(std::vector<op>& operators, std::vector<float>& operands, bool obligatory_op = false);
float str_to_float(const std::string& convert);
float evaluate(const std::string& expression);

} // namespace expreval

#endif