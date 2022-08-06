#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template < typename T > 
class MutantStack: public std::stack<T> {
 
    public:
        MutantStack<T>( void ) : MutantStack<T>::stack() {}
        MutantStack<T>( MutantStack<T> const &ref ) : MutantStack<T>::stack(ref) {}
        ~MutantStack<T>() {};

        MutantStack<T>  &operator=( MutantStack<T> const &ref ) {this->c = ref.c; return *this;}

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin() {
            return this->c.begin();
        }
        iterator end() {
            return this->c.end();
        }
};

#endif
