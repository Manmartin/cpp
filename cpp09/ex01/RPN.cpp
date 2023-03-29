#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN( RPN const &ref ) { *this = ref; }
RPN::~RPN() {}

RPN &RPN::operator=( RPN const &ref ) {
    this->_stack = ref._stack;
    return *this;
}

void RPN::getNumbers(float *n1, float *n2) {
    *n1 = _stack.top();
    _stack.pop();
    *n2 = _stack.top();
    _stack.pop();
}

bool RPN::readExpression( std::string exp ) {
    float first, second;

    for (unsigned i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            if (exp[i+1] != ' ' && exp[i+1] != '\0')
                return false;
            _stack.push(exp[i] - '0');
            continue; 
        }
        else if (exp[i] == ' ')
            continue;
        switch (exp[i])
        {
            case '+':
                if (_stack.size() < 2)
                    return false;
                getNumbers(&second, &first);
                _stack.push(first + second);
                break;
            case '-':
                if (_stack.size() < 2)
                    return false;
                getNumbers(&second, &first);
                _stack.push(first - second);
                break;
            case '*':
                if (_stack.size() < 2)
                    return false;
                getNumbers(&second, &first);
                _stack.push(first * second);
                break;
            case '/':
                if (_stack.size() < 2)
                    return false;
                getNumbers(&second, &first);
                _stack.push(first / second);
                break;
            default:
                return false;
        }
    }
    std::cout << _stack.top() << '\n';
    return true;
}
