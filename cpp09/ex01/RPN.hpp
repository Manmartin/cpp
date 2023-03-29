#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{
    private:
        std::stack<float>     _stack;

        void   getNumbers( float *n1, float *n2);

    public:
        RPN();
        RPN( RPN const &ref );
        ~RPN();

        RPN &operator=( RPN const &ref );

        bool    readExpression( std::string exp );
};

#endif
