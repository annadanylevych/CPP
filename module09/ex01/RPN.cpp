#include "RPN.hpp"

std::vector<std::string> parseNumbers(std::string& numbers)
{
    std::vector<std::string> parsedNums;
    std::istringstream iss(numbers);
    std::string token;
    
    while (iss >> token)
    {
        if (token.size() == 1 && (std::isdigit(token[0]) || token[0] == '+' || token[0] == '-'
                || token[0] == '*' || token[0] == '/'))
            parsedNums.push_back(token);
        else
            throw (std::invalid_argument("Error: invalid character detected"));
    }
    return (parsedNums);
}

int calculate(int num1, int num2, char op)
{
   switch (op)
   {
        case '+':
            return(num1 + num2);
        case '-':
            return(num1 - num2);
        case '*':
            return(num1 * num2);
        case '/':
            return(num1 / num2);
   }
}

void    operate(std::vector<std::string> parsedNums)
{
    std::stack<int> rpn;
    for (std::vector<std::string>::iterator it = parsedNums.begin(); it != parsedNums.end(); ++it)
    {
        if (std::isdigit((*it)[0]))
            rpn.push(std::atoi((*it).c_str()));
        else {
            if (rpn.size() < 2)
                throw (std::invalid_argument("Error: operation not possible"));
            int num2 = rpn.top();
            int num1 = rpn.top();
            rpn.pop();
            rpn.pop();
            if (num2 == 0 && *it == "/")
                throw(std::invalid_argument("You cannot divide by 0"));
            rpn.push(calculate(num1, num2, (*it)[0]));
        }
    }
}  