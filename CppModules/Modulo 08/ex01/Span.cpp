#include "Span.hpp"

Span::Span()
{
    std::cout << "Empty Span created" << std::endl;
}

Span::Span(unsigned int size) : _size(size)
{
    std::cout << "Span created with size:" << _size << std::endl;
}

Span::Span(const Span &span)
{
    std::cout << "Span copy created" << std::endl;
    *this = span;
}

Span::~Span()
{
    std::cout << "Span destroyed" << std::endl;
}

Span &Span::operator=(const Span &span)
{
    std::cout << "Span copy assigned" << std::endl;
    if (this->_v.size() != 0)
        this->_v.clear();
    this->_v = span._v;
    return *this;
}

void Span::addNumber(int number)
{
    if (this->_v.size() == this->_size)
    {
        std::cout << "Impossible to add: " << number << std::endl;
        throw MaxSize();
    }
    this->_v.push_back(number);
}

unsigned int Span::shortestSpan()
{
    if (_v.empty())
        throw VectorEmpty();
    if (this->_v.size() <= 1)
        throw NotEnoughValues();
    std::vector<int> vCopy = this->_v;
    std::sort(vCopy.begin(), vCopy.end());
    int shortest = INT_MAX;
    size_t j = 0;
    while (j < vCopy.size())
    {
        for (size_t i = 0; i < vCopy.size();)
        {
            if (vCopy[j] - vCopy[i] < shortest && vCopy[j] - vCopy[i] >= 1)
                shortest = vCopy[j] - vCopy[i];
            i++;
        }
        j++;
        
    }
    return shortest;
}

unsigned int Span::longestSpan()
{
    if (_v.empty())
        throw VectorEmpty();
    if (this->_v.size() <= 1)
        throw NotEnoughValues();
    std::vector<int> vCopy = this->_v;
    int max = INT_MIN;
    int min = INT_MAX;
    for (size_t i = 0; i < vCopy.size(); i++)
    {
        if (vCopy[i] > max)
            max = vCopy[i];
        if (vCopy[i] < min)
            min = vCopy[i];
    }
    int longest = max - min;
    return longest;
}

void Span::addTot(int call)
{
    srand(time(NULL));
    for (int i = 0; i < call; i++)
    {
        unsigned int j = (rand() % _size * 2) + 1;
        if (this->_v.size() == this->_size)
        {
            std::cout << "Impossible to add: " << j << std::endl;
            throw MaxSize();
        }
        else
            this->addNumber(j);
    }
}