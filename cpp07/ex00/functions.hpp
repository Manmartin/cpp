#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

template< typename T>
void	swap(T &x, T &y) {
	T temp = x;
	x = y;
	y = temp;
}

template< typename T >
T const &min(T const &x, T const &y) {
	return (x <= y ? x : y);
}

template< typename T >
T const &max(T const &x, T const &y) {
	return (x >= y ? x : y);
}

#endif
