#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

int main()
{
    std::cout << std::endl;
    std::cout << "------ Constructors Animal, Dog and Cat ------" << std::endl;
    std::cout << std::endl;
    const Animal *animal = new Animal();
    std::cout << std::endl;
    const Animal *dog = new Dog();
    std::cout << std::endl;
    const Animal *cat = new Cat();
    std::cout << std::endl;
    std::cout << "----- Testing Animal, Dog and Cat sounds -----" << std::endl;
    std::cout << std::endl;
    std::cout << "Animal: " << animal->get_type() << " sound" << std::endl;
    animal->makeSound();
    std::cout << std::endl;
    std::cout << "Animal: " << dog->get_type() << " sound" << std::endl;
    dog->makeSound();
    std::cout << std::endl;
    std::cout << "Animal: " << cat->get_type() << " sound" << std::endl;
    cat->makeSound();
    std::cout << std::endl;
    std::cout << "---- Constructors WrongAnimal and WrongCat ----" << std::endl;
    std::cout << std::endl;
    const WrongAnimal *wrongAnimal = new WrongAnimal("WrongAnimal");
    std::cout << std::endl;
    const WrongAnimal *wrongCat = new WrongCat();
    std::cout << std::endl;
    std::cout << "--- Testing WrongAnimal and WrongCat sounds ---" << std::endl;
    std::cout << std::endl;
    std::cout << "WrongAnimal: " << wrongAnimal->get_type() << " sound" << std::endl;
    wrongAnimal->makeSound();
    std::cout << std::endl;
    std::cout << "WrongAnimal: " << wrongCat->get_type() << " sound" << std::endl;
    wrongCat->makeSound();
    std::cout << std::endl;
    std::cout << "------ Destructors Animal, Dog and Cat -------" << std::endl;
    std::cout << std::endl;
    delete animal;
    std::cout << std::endl;
    delete dog;
    std::cout << std::endl;
    delete cat;
    std::cout << std::endl;
    std::cout << "---- Destructors WrongAnimal and WrongCat ----" << std::endl;
    std::cout << std::endl;
    delete wrongAnimal;
    std::cout << std::endl;
    delete wrongCat;
    std::cout << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << std::endl;
    return 0;
}