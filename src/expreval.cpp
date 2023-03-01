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
    int dot=-1, power=1;
    float result=0;
    for(int i=0; i<convert.size(); i++) // doar caut daca are punct sau nu;
    {
        if(convert[i]=='.')
        {
            dot=i;
            break;
        }
    }
    if(dot==-1)
        dot=convert.size();
    for(int i=dot-1; i>=0; i--)  // partea intreaga
    {
        result+=(int(convert[i])-48)*power;
        power*=10;
    }
    power=10;
    if(dot!=convert.size()) // partea decimala
    {
        for(int i=dot+1; i<convert.size(); i++)
        {
            result+=1.0*(int(convert[i])-48)/power;
            power*=10;
        }
    }
    return result;
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