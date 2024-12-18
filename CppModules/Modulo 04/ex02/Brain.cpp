#include "Brain.h"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];
}

Brain &Brain::operator=(Brain const &src)
{
    std::cout << "Brain assignation operator called" << std::endl;
    if (this != &src)
        for (int i = 0; i < 100; i++)
            this->ideas[i] = src.ideas[i];
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::set_Idea(int index, std::string idea)
{
    if (index > 0 && index < 100)
        this->ideas[index] = idea;
    else
        std::cout << "Not enough memory" << std::endl;
}

std::string Brain::get_Idea(int index) const
{
    if (index > 0 && index < 100)
        return this->ideas[index];
    else
        return "No idea";
}