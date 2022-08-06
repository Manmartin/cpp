#include <span.hpp>

Span::Span( void ) : _n(0), _v(0) {}
Span::Span( Span const &ref ) : _n(ref._n), _v(ref._v) {}
Span::Span( unsigned int const n ) : _n(n), _v(0) {}
Span::~Span( void ) {}

Span	&Span::operator=( Span const &ref ) {
	this->_n = ref._n;
	this->_v = ref._v;
	return *this;
}

void	Span::addNumber( unsigned int const x ) {
	if (this->_v.size()  == this->_n)
		throw Span::TooMuchNumbersException();
	this->_v.push_back(x);
}

void	Span::betterAddNumber( unsigned int const init, unsigned int const n, unsigned int const m) {
	
	for (unsigned int i = 0; i < n; i++)
		this->addNumber((i + init) * m);
}

int	Span::longestSpan( void ) {
	if (this->_v.size() < 2)
		throw Span::NotEnoughNumbers();
	return *max_element(_v.begin(), _v.end()) - *min_element(_v.begin(), _v.end());
}

int	Span::shortestSpan( void ) {
	int diff = INT_MAX;
	const int size = this->_v.size();
	if ( size < 2)
		throw Span::NotEnoughNumbers();
	std::sort(_v.begin(), _v.end());
	for (int i = 0; i < size - 1; i++)
		if (_v[i + 1] - _v[i] < diff )
			diff = _v[i + 1] - _v[i];	
	return diff;
}

/* Exceptions */

const char *Span::TooMuchNumbersException::what() const throw(){
	return "Span is already full";
}

const char *Span::NotEnoughNumbers::what() const throw(){
	return "Not enough numbers";
}
