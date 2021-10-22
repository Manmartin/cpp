#include "includes.hpp"

int main(void) {
    std::cout << "\e[1;35m[ Creating MaterialSource ]\e[1;0m" << std::endl;
    std::cout << std::endl;
    IMateriaSource* src = new MateriaSource();
    std::cout << "\e[1;36mMaterialSource learn Ice and Cure materials\e[1;0m" << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << std::endl;
    std::cout << "\e[1;35m[ Creating Character \"me\" ]\e[1;0m" << std::endl;
    std::cout << std::endl;
    ICharacter* me = new Character("me");
    std::cout << "\e[1;33mCharacter's name = \e[1;31m" << me->getName() << "\e[1;0m" <<std::endl;
    std::cout << std::endl;

    std::cout << "\e[1;35m[ Creating AMateria ]\e[1;0m" << std::endl;
    std::cout << std::endl;
    AMateria* tmp;
    std::cout << "\e[1;36mEquip \"me\" with Ice and Cure from \"createMateria()\"\e[1;0m" << std::endl;
    std::cout << std::endl;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << "\e[1;33m[ Wrong Materia input in createMateria() ]" << std::endl << std::endl
    << "createMateria(\"fire\") = \e[1;31m" << src->createMateria("fire") << "\e[1;0m" <<std::endl
    << std::endl;

    std::cout << "\e[1;35m[ Creating Character \"bob\" ]\e[1;0m" << std::endl;
    std::cout << std::endl;
    ICharacter* bob = new Character("bob");


    std::cout << "\e[1;36m\"me\" use Ice and Cure in \"bob\"\e[1;31m" << std::endl;
    std::cout << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;


    std::cout << "\e[1;35m[ Copy test ]\e[1;0m" << std::endl;
    std::cout << std::endl;

    ICharacter* og = new Character("Original");
    ICharacter* fk = new Character("Fake");
    
    std::cout << "\e[1;36mOriginal starts with ice\e[1;31m" << std::endl;
    og->equip(src->createMateria("ice"));
    og->use(0, *fk);
    std::cout << "\e[1;36mFake starts with cure\e[1;31m" << std::endl;
    fk->equip(src->createMateria("cure"));
    fk->use(0, *og);
    std::cout << "\e[1;36mFake = Original\e[1;31m" << std::endl;
    fk = og;
    fk->use(0, *og);


    delete fk;
   // delete og;
    delete src;
    return 0;
}