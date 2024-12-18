#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"

int main()
{
    std::cout << "--------------- Creating Animals ---------------" << std::endl;
    std::cout << std::endl;

    const int n_Animals = 2;
    Animal *animals[n_Animals];

    for (int i = 0; i < n_Animals; i++)
    {
        if (i < n_Animals / 2)
        {
            animals[i] = new Dog();
            std::cout << std::endl;
        }
        else
        {
            animals[i] = new Cat();
            std::cout << std::endl;
        }
    }

    //Test animal sounds
    for (int i = 0; i < n_Animals; i++)
        animals[i]->makeSound();

    std::cout << std::endl;

    //Delete animals
    for (int i = 0; i < n_Animals; i++)
    {
        delete animals[i];
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "--------- Creating Animals with brains ---------" << std::endl;
    std::cout << std::endl;

    Dog *dog = new Dog();
    std::cout << std::endl;
    Cat *cat = new Cat();

    dog->get_Brain()->set_Idea(0, "Bark in the courtyard");
    dog->get_Brain()->set_Idea(1, "Howl at the moon");
    cat->get_Brain()->set_Idea(0, "Steal food");
    cat->get_Brain()->set_Idea(1, "Go outside");

    std::cout << std::endl;
    std::cout << "Dog first idea: " << dog->get_Brain()->get_Idea(0) << std::endl;
    std::cout << "Cat first idea: " << cat->get_Brain()->get_Idea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "--- Testing animals deep copy and destructor ---" << std::endl;
    std::cout << std::endl;

    Dog *dog2 = new Dog(*dog);
    std::cout << std::endl;
    Cat *cat2 = new Cat(*cat);
    std::cout << std::endl;

    std::cout << "CopyDog first idea: " << dog2->get_Brain()->get_Idea(0) << std::endl;
    std::cout << "CopyCat first idea: " << cat2->get_Brain()->get_Idea(0) << std::endl;

    std::cout << std::endl;
    delete dog;
    std::cout << std::endl;
    delete dog2;
    std::cout << std::endl;
    delete cat;
    std::cout << std::endl;
    delete cat2;

    std::cout << std::endl;
    std::cout << "----- Testing copy with assignment operator -----" << std::endl;
    std::cout << std::endl;

    Dog dogA;
    std::cout << std::endl;
    Dog dogB;
    std::cout << std::endl;
    dogB = dogA;
    std::cout << std::endl;
    Cat catA;
    std::cout << std::endl;
    Cat catB;
    std::cout << std::endl;
    catB = catA;
    std::cout << std::endl;
    return 0;
}