#include "../include/expreval.h"

namespace expreval
{

op::op(char sym, unsigned int prio)
    : m_symbol(sym), m_prio(prio) 
{
    if(m_symbol == '+' || m_symbol == '-')
        ++m_prio;
    else if(m_symbol == '^')
        m_prio+=3;
    else m_prio+=2;
}

float str_to_float(const std::string& convert)
{

}

static op symbols[] = { {'+',1}, {'-',1}, {'*',2}, {'/',2}, {'^',3} };

int evaluate(const std::string& expr)
{
    std::string digits = "0123456789.";
    std::vector<op> operators;
    std::vector<float> operands;
    unsigned int para = 0;
    bool potential_unary_minus = true;
    for(int i = 0; i < expr.size(); ++i)
    {
        if(expr[i] == ' ')
            continue;
        else if(expr[i] == '(')
        {
            potential_unary_minus = true;
            para += 10;
        }
        else if(expr[i] == ')')
        {
            para -= 10;
        }
        else if(expr[i] == '+' || (expr[i] == '-' && potential_unary_minus == false) || expr[i] == '*' || expr[i] == '/' || expr[i] == '^')
        {
            
        }
        else
        {
            unsigned int start = i;
            unsigned int end = start+1;
            while(digits.find(expr[end]) != std::string::npos)
            {
                ++end;
            }
            i = end - 1;
            std::cout << "Numar: " << expr.substr(start, end-start);
            potential_unary_minus = false;
        }
    }
    return 0;
}
}