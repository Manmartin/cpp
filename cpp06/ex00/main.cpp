#include <iostream>
#include <Caster.hpp>
int main(int argc, char **argv) {
	(void)argv;
	Caster caster;
	if (argc != 2) {
		std::cout << "Wrong args\n";
		return 0;
	}
	caster.setRawValue(argv[1]);
	caster.castValue();
}
