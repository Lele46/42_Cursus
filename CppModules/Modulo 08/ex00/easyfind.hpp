#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class ValueNotFound : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "Value not found";
        }
};


template <typename T>
void *easyfind(T &container, int value)
{
    typename T::iterator iter;
    for (iter = container.begin(); iter != container.end(); iter++)
    {
        if (*iter == value)
            return &(*iter);
    }
    throw ValueNotFound();
};

#endif