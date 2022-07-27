#include <Caster.hpp>

const char * Caster::special[7] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan", NULL};

/* Aux functions */

static int strlen( std::string const &str ) {
	int i = 0;

	while (str[i])
		i++;
	return i;
}

static bool isDigit( int c ) {

	if (c >= '0' && c <= '9')
		return true;
	return false;
}

static bool isPrint( int c ) {

	if (c >= 32 && c <= 126)
		return true;
	return false;
}


/* Constructors And destructor */

Caster::Caster( void ) {}
Caster::Caster( Caster const &ref ) { *this = ref; }
Caster::~Caster( void ) {}

Caster const &Caster::operator=( Caster const &ref ) {
	this->_rawValue = ref._rawValue;
	return *this;
}

void	Caster::setRawValue( std::string const &rawValue ) {
	this->_rawValue = rawValue;
}

std::string const &Caster::getRawValue( void ) {
	return this->_rawValue;
}


/* Print functions */

void	Caster::printChar( int c, char const *special ) {
	std::cout << "char: ";
	if (special)
		std::cout << "impossible";
	else if (!isPrint(c))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(c) << "'";
	std::cout << '\n';
}

void	Caster::printInt( int nb, char const *special ) {
	std::cout << "int: ";
	if (special)
		std::cout << "impossible";
	else
		std::cout << nb;
	std::cout << '\n';
}

void	Caster::printFloat( float nbf, char const *special ) {
	(void)special;
	std::cout << "float: ";
	
	if (special) {
		for (int i = 0; this->special[i]; i++) {
			if (std::string(this->special[i]) == std::string(special)) {
				std::cout << this->special[i % 3];
				break;
			} else if (this->special[i + 1] == NULL)
				std::cout << "impossible";
		}
	}
	else {
		std::cout << nbf;
		std::cout << 'f';
	}
	std::cout << '\n';
	
}

void	Caster::printDouble( double nbd, char const *special ) {
	(void)special;
	std::cout << "double: ";
	
	if (special) {
		for (int i = 0; this->special[i]; i++) {
			if (std::string(this->special[i]) == std::string(special)) {
				std::cout << this->special[i % 3 + 3];
				break;
			} else if (this->special[i + 1] == NULL)
				std::cout << "impossible";
		}
	}
	else {
		std::cout << nbd;
	}
	std::cout << '\n';
}


/* Utils */

bool	Caster::isSpecial( std::string const &str ) {
	for (int i = 0; special[i]; i++)
		if (str == special[i])
			return true;
	return false;
}

bool	Caster::isException( void ) {
	return value.nb == std::numeric_limits<double>::infinity() || value.nb == -std::numeric_limits<double>::infinity() || std::isnan(value.nb); 
} 

/* Casts functions */

void	Caster::castFromChar( void ) {
	this->printChar(this->value.c, NULL);
	this->printInt(static_cast<int>(this->value.c), NULL);
	this->printFloat(static_cast<float>(this->value.c), NULL);
	this->printDouble(static_cast<double>(this->value.c), NULL);
}

void	Caster::castFromSpecial( void ) {
	this->printChar(0, this->value.special);
	this->printInt(0, this->value.special);
	this->printFloat(0.0f, this->value.special);
	this->printDouble(0.0, this->value.special);
}

void	Caster::castFromDouble( void ) {
	if (value.nb >= std::numeric_limits<char>::min() && value.nb <= std::numeric_limits<char>::max())
		this->printChar(static_cast<int>(this->value.nb), NULL);
	else
		this->printChar(0, "noprint");
	
	if (value.nb >= std::numeric_limits<int>::min() && value.nb <= std::numeric_limits<int>::max())
		this->printInt(static_cast<int>(this->value.nb), NULL);
	else
		this->printInt(0, "noprint");
	
	if ((value.nb >= -std::numeric_limits<float>::max() && value.nb <= std::numeric_limits<float>::max()) || this->isException())
		this->printFloat(static_cast<float>(this->value.nb), NULL);
	else
		this->printFloat(0.0, "noprint");
	this->printDouble(this->value.nb, NULL);
}

void	Caster::castError( void ) {
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}

void	Caster::castValue( void ) {
	char	*end;

	if (this->_rawValue.length() == 1 && isPrint(this->_rawValue[0]) && !isDigit(this->_rawValue[0])) {
		this->type = CHAR;
		this->value.c = this->_rawValue[0];
	}
	else if (isSpecial(this->_rawValue)){
		this->type = SPECIAL;	
		this->value.special = this->_rawValue.c_str();
	} else {
		this->value.nb = strtod(this->_rawValue.c_str(), &end);
		if (end != this->_rawValue.c_str() && (*end == '\0' || ( strlen(end) == 1 && *end == 'f' )) && this->value.nb != HUGE_VAL)
			this->type = DOUBLE;
		else
			this->type = ERROR;
	}
	switch (this->type) {
		case CHAR:
			castFromChar();
			break;
		case DOUBLE:
			castFromDouble();
			break;
		case SPECIAL:
			castFromSpecial();
			break;	
		case ERROR:
			castError();
			break;
	}
}
