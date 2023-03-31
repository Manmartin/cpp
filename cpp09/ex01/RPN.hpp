#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{
    private:
        RPN( RPN const &ref );
        RPN &operator=( RPN const &ref );

        std::stack<float>     _stack;

        void   getNumbers( float *n1, float *n2 );
    public:
        RPN();
        ~RPN();

        bool    readExpression( std::string exp );
};

#endif
