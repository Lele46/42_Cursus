#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <vector>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() 
        {
            std::cout << "MutantStack constructor called" << std::endl;
        };
        MutantStack(const MutantStack &mutantStack) : std::stack<T>(mutantStack) 
        {
            std::cout << "MutantStack copy constructor called" << std::endl;
        };
        MutantStack &operator=(const MutantStack &mutantStack)
        {
            if (this->size() != 0)
                this->c.clear();
            this->c = mutantStack.c;
            return *this;
        };
        ~MutantStack() 
        {
            std::cout << "MutantStack destructor called" << std::endl;
        };

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin()
        {
            return this->c.begin();
        };

        iterator end()
        {
            return this->c.end();
        };
};

#endif