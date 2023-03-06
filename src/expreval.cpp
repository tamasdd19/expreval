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

void _make_this_operation(char symbol, float& lhs, float& rhs)
{
    if(symbol == '+')
        {
            lhs += rhs;
        }
        else if(symbol == '-')
        {
            lhs -= rhs;
        }
        else if(symbol == '*')
        {
            lhs *= rhs;
        }
        else if(symbol == '/')
        {
            lhs /= rhs;
        }
        else if(symbol == '^')
        {
            lhs = std::pow(lhs, rhs);
        }
        else
        {
            // FIXME: throw exception maybe?
            throw std::exception("WRONG OPERATOR");
        }
}

void _do_operations(std::vector<op>& operators, std::vector<float>& operands, bool obligatory_op)
{
    // obligatory_op is a bool set to true when all the operators have been found thus no normal trigger

    // If we are out of operators, stop the recursive call to _do_operations
    if(operators.size() == 0)
        return; // finished

    bool do_operation = false;
    // minimum 2 operators for this
    if(operators.size() > 1)
    {
        // checks if the most recent added operators triggers operations to take place
        do_operation = (operators.end() - 1)->m_prio <= (operators.end() - 2)->m_prio;
    }

    // if we need to make an operation
    if(do_operation || obligatory_op)
    {
        // an obligatory operation takes places on the true LAST operator in "operators"
        if(obligatory_op)
        {
            _make_this_operation((operators.end() - 1)->m_symbol, *(operands.end() - 2), *(operands.end() - 1));
            operators.erase(operators.end() - 1);
            operands.erase(operands.end() - 1);
        }
        // a non-obligatory operation takes places on the second LAST operator in "operators", since the true last one triggered it
        else
        {
            _make_this_operation((operators.end() - 2)->m_symbol, *(operands.end() - 2), *(operands.end() - 1));
            operators.erase(operators.end() - 2);
            operands.erase(operands.end() - 1);
        }
        // recursive call to make sure all triggered operations are done
        _do_operations(operators, operands, obligatory_op);
    }
}

float str_to_float(const std::string& convert)
{
    bool negative = false;
    int START = 0; // to keep convert const
    if(convert[0] == '-')
    {
        negative = true;
        START=1;
    }
    int dot=-1, power=1;
    float result=0;
    
    for(int i=START; i<convert.size(); i++) // doar caut daca are punct sau nu;
    {
        if(convert[i]=='.')
        {
            dot=i;
            break;
        }
    }
    if(dot==-1)
        dot=convert.size();
        
    for(int i=dot-1; i>=START; i--)  // partea intreaga
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
    return negative ? -1.0 * result : result;
}

float evaluate(const std::string& expr)
{
    std::string digits = "0123456789.-";
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
            // Found and added operand
            operators.push_back({expr[i], para});
            // Check if any operations should be done
            _do_operations(operators, operands);
        }
        else if(digits.find(expr[i])<digits.size())
        {
            unsigned int start = i;
            unsigned int end = start+1;
            while(digits.find(expr[end]) != std::string::npos)
            {
                ++end;
            }
            i = end - 1;
            // Found and added operand
            operands.push_back(str_to_float(expr.substr(start, end-start)));
            potential_unary_minus = false;
        }
        else
            throw std::invalid_argument("Wrong symbol");
    }
    // Do any remaining operations
    _do_operations(operators, operands, true);
    
    return operands[0];
}
}