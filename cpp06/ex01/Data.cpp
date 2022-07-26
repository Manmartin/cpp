#include <Data.hpp>

Data::Data() : nb(0), nbf(0), nbd(0) {}
Data::Data(int nb, float nbf, double nbd) : nb(nb), nbf(nbf), nbd(nbd) {}
Data::Data( Data const &ref ) {
	*this = ref;
}
Data::~Data() {}

Data &Data::operator=( Data const &ref ) {
	this->nb = ref.nb;
	this->nbf = ref.nbf;
	this->nbd = ref.nbd;
	return *this;
}

void	Data::printData( void ) {
	std::cout << this->nb << '\n';
	std::cout << this->nbf << '\n';
	std::cout << this->nbd << '\n';
}
