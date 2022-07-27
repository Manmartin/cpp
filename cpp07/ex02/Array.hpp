#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template < typename T >
class Array {
	private:
		unsigned int _size;
		T *_arr;
				
	public:
		Array<T>( void ) : _size(0), _arr(new T[0]())   {}
		Array<T>( Array<T> const &ref ) : _arr(NULL) { *this = ref; } 
		Array<T>( unsigned int n ) : _size(n), _arr(new T[_size]()) {}
		~Array<T>() {delete [] this->_arr;}
		
		Array<T>	&operator=( Array<T> const &ref ) {
			T *tmp = ref._size > 0 ? new T[ref._size]() : new T[0]();
			this->_size = ref._size;
			for (unsigned int i = 0; i < this->_size; i++)
				tmp[i] = ref._arr[i];
			if (_arr)
				delete [] this->_arr;
			this->_arr = tmp;
			return *this;
		}
		T	&operator[]( const unsigned int i ) {
			if (i >= this->_size)
				throw std::exception();
			else
				return this->_arr[i];
		}
		T const &operator[]( const unsigned int i ) const {
			if (i >= this->_size)
				throw std::exception();
			else
				return this->_arr[i];
		}
		unsigned int	size( void ) const {return this->_size;}
};

#endif
