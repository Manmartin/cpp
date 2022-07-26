#include <iostream>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>
#include <ctime>
#include <cstdlib>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

Base *generate(void) {
	int i = rand() % 3;

	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}
void identify(Base& p) {
	
	try {
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A\n";
	} catch (std::exception &e) {}
	try {
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B\n";
	} catch (std::exception &e) {}
	try {
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C\n";
	} catch (std::exception &e) {}
}
void identify(Base* p) {
	A *a;
	B *b;

	if ((a = dynamic_cast<A *>(p))) 
		std::cout << "A\n";
	else if ((b = dynamic_cast<B *>(p)))
		std::cout << "B\n";
	else
		std::cout << "C\n";
}

int main(void) {
	Base	*a;
	Base	*b;
	Base	*c;

	std::cout << BLUE << "Generating random child classes\n\n" << RESET;	
	a = generate();
	b = generate();
	c = generate();

	std::cout << GREEN << "Identify by pointer\n" << RESET;	
	identify(a);
	identify(b);
	identify(c);

	std::cout << GREEN << "Identify by reference\n" << RESET;	
	identify(*a);
	identify(*b);
	identify(*c);
	std::cout << '\n';

	std::cout << BLUE << "Prove identify with non-random classes\n\n" << RESET;	
	{
		A *a = new A;
		B *b = new B;
		C *c = new C;
		
		std::cout << GREEN << "Identify by pointer\n" << RESET;	
		identify(a);
		identify(b);
		identify(c);

		std::cout << GREEN << "Identify by reference\n" << RESET;	
		identify(*a);
		identify(*b);
		identify(*c);
		
		delete a;
		delete b;
		delete c;
	}
	delete a;
	delete b;
	delete c;
	return 0;
}
